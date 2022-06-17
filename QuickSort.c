#include <stdio.h>
#include <stdlib.h>
#define a 5
#define c 1
#define m 17
#define x0 3
typedef struct scale{
    int start;
    int end;
}Scale;

typedef struct QNode{
    Scale data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
void InitQueue(LinkQueue *Q);
void EnQueue(LinkQueue *Q,Scale node);
void DeQueue(LinkQueue *Q,Scale *node);
/*���ö���ʵ�ֶԵݹ�����㷨���������Ĺ�ģ���д洢*/

void QuickSort(LinkQueue *Q,int *times,int X[],int first,int last);
int partition(int *times,int X[],int first,int last);

int main()
{
    int k,nums;
    int p = 1;
    int* times = (int*)malloc(sizeof(int));
    LinkQueue *Q = (LinkQueue*)malloc(sizeof(LinkQueue));
    Scale nodes;
    InitQueue(Q);
    times[0] = 0;
    scanf("%d",&nums);
    int *X = (int*)malloc(sizeof(int)*nums);
    X[0] = x0;
    for(k = 1;k < nums;k++){
        X[k] = (a*X[k - 1] + c)%m;
    } //���á�����ͬ�෨��ʵ��������Ļ�ã�ͬʱ����õ�������洢��һά���鵱��
    QuickSort(Q,times,X,0,nums - 1);
    while(Q->front->next != NULL){
        DeQueue(Q,&nodes);
        printf("%d\t",nodes.end - nodes.start);
        if(p % 10 == 0){
            printf("\n");
        }
        p++;
    }
    printf("\n%d",times[0]);
    return 0;
}
/*�����������Ҫʱ�俪�������ڻ����ϣ�ÿһ�λ����ҵ���׼Ԫ���ڶ����е�����λ�ã��Ӷ�ʵ��һ������ֱ��ȫ������û�кϲ�����*/
void QuickSort(LinkQueue *Q,int *times,int X[],int first,int last){
    Scale node;
    if(first < last){ //���õݹ�ķ�ʽ��ʵ�ֿ�������
        node.start = first;
        node.end = last;
        EnQueue(Q,node); //��ÿһ�ε��û����㷨���������ģ�����
        int pivot = partition(times,X,first,last);
        QuickSort(Q,times,X,first,pivot - 1);
        QuickSort(Q,times,X,pivot + 1,last);
    }
}

int partition(int *times,int X[],int first,int last){
    int pivotValue = X[first]; //�����������еĵ�һ��Ԫ����Ϊ��׼Ԫ��
    int pivotIndex = first; //����׼Ԫ���������е��±���б��
    int i,temp;
    for(i = first + 1;i <= last;i++ ){
        if(X[i] < pivotValue){ //��������������С�ڻ�׼Ԫ��ֵ����н�������
            pivotIndex++;
            //�������ݽ��н���
            temp = X[pivotIndex];
            X[pivotIndex] = X[i];
            X[i] = temp;
            //��¼�㷨�л�������ִ�еĴ���
            times[0]++;
        }
    }
    //�������ݽ��н���
    temp = X[first];
    X[first] = X[pivotIndex];
    X[pivotIndex] = temp;
    return pivotIndex;
}

void InitQueue(LinkQueue *Q){
    QueuePtr temp = (QueuePtr)malloc(sizeof(QNode));
    Q->front = temp;
    Q->rear = temp;
    Q->front->next = NULL;
    Q->rear->next = NULL;
}

void EnQueue(LinkQueue *Q,Scale node){
    QueuePtr nodes = (QueuePtr)malloc(sizeof(QNode));
    nodes->data = node;
    nodes->next = NULL;
    if(Q->front == Q->rear){
        Q->front->next = nodes;
        Q->rear = nodes;
    }
    else{
        Q->rear->next = nodes;
        Q->rear = nodes;
    }
}

void DeQueue(LinkQueue *Q,Scale* node){
    if(Q->front->next == Q->rear){
        *node = Q->rear->data;
        Q->front->next = NULL;
        Q->rear = Q->front;
    }
    else{
        QueuePtr temp = Q->front->next;
        *node = temp->data;
        Q->front->next = temp->next;
    }
}

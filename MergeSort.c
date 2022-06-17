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
/*���ö���ʵ�ֶ�ÿ�ε���ʱ������ӹ�ģ���д洢*/

void MergeSort(LinkQueue *Q,int* times,int X[],int first,int last);
int Merge(int X[],int first,int first_last,int second,int second_last);

int main(){
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
    } //��������ͬ�෨����һ�������趨�£��������Ҫ����n�������һά����
    MergeSort(Q,times,X,0,nums - 1);
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

void MergeSort(LinkQueue *Q,int* times,int X[],int first,int last){
    int middle;
    Scale node;
    if(first < last){ //���õݹ�ķ�ʽʵ�ֹ鲢���򣬸�������Ҫʱ�俪�������������еĺϲ������ֹ��̲�δռ��ʱ�俪��
        middle = (first + last)/2;
        MergeSort(Q,times,X,first,middle);
        MergeSort(Q,times,X,middle + 1,last);
        times[0] += Merge(X,first,middle,middle + 1,last);
        node.start = first;
        node.end = last;
        EnQueue(Q,node); //�������ӹ�ģ�����
    }
}

int Merge(int X[],int start1,int end1,int start2,int end2){
    int p = start1;
    int n = start2;
    int times = 0;
    int count = 0;
    int C[end2 - start1 + 1];
    while(p <= end1 && n <= end2){
        if(X[p] <= X[n]){
            C[count] = X[p];
            times++;
            p++;
        }
        else{
            C[count] = X[n];
            times++;
            n++;
        }
        count++;
    } //������һ���������Ѿ���ȫ��������һ��������δ��ȫ������ɣ����轫ʣ�ಿ�����ν��д洢���ɣ�����Ƚ�
    while(p <= end1){
        C[count] = X[p];
        p++;
        count++;
    }
    while(n <= end2){
        C[count] = X[n];
        n++;
        count++;
    }
    count = 0;
    for(p = start1;p <= end2;p++){
        X[p] = C[count];
        count++;
    }
    return times; //��ÿһ���������������кϲ�ʱ���еıȽϴ������з��ز��ۼ�
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

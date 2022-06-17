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
/*利用队列实现对递归调用算法求解子问题的规模进行存储*/

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
    } //利用“线性同余法”实现随机数的获得，同时将获得的随机数存储在一维数组当中
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
/*快速排序的主要时间开销花费在划分上，每一次划分找到基准元素在队列中的最终位置，从而实现一趟排序，直至全部有序，没有合并操作*/
void QuickSort(LinkQueue *Q,int *times,int X[],int first,int last){
    Scale node;
    if(first < last){ //采用递归的方式来实现快速排序
        node.start = first;
        node.end = last;
        EnQueue(Q,node); //将每一次调用划分算法的子问题规模入队列
        int pivot = partition(times,X,first,last);
        QuickSort(Q,times,X,first,pivot - 1);
        QuickSort(Q,times,X,pivot + 1,last);
    }
}

int partition(int *times,int X[],int first,int last){
    int pivotValue = X[first]; //将待排序序列的第一个元素作为基准元素
    int pivotIndex = first; //将基准元素所在序列的下标进行标记
    int i,temp;
    for(i = first + 1;i <= last;i++ ){
        if(X[i] < pivotValue){ //从左至右若该数小于基准元素值则进行交换，且
            pivotIndex++;
            //将两数据进行交换
            temp = X[pivotIndex];
            X[pivotIndex] = X[i];
            X[i] = temp;
            //记录算法中基本操作执行的次数
            times[0]++;
        }
    }
    //将两数据进行交换
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

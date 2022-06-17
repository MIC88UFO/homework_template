#include <stdio.h>
#include <stdlib.h>
#define a 5
#define c 1
#define m 17
#define x0 5
int Bubble_Sort(int X[],int nums);

int main(){
    int k,nums,counts;
    scanf("%d",&nums);
    int *X = (int*)malloc(sizeof(int)*nums);
    X[0] = x0;
    for(k = 1;k < nums;k++){
        X[k] = (a*X[k - 1] + c)%m;
    }
    counts = Bubble_Sort(X,nums);
    printf("%d",counts);
    return 0;
}

int Bubble_Sort(int X[],int nums){
    int flag = 1;
    int length = nums;
    int k,temp;
    int count = 0;
    while(flag == 1){
        flag = 0;
        for(k = 0;k < length - 1;k++){
            count++;
            if(X[k] > X[k + 1]){
                temp = X[k];
                X[k] = X[k + 1];
                X[k + 1] = temp;
                flag = 1;
            }
        }
        length--;
    }
    return count;
}

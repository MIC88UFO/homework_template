#include <stdio.h>
#include <stdlib.h>
int Fibonacci(int n,int* times);


int main()
{
     int n = 30;
     int *times = (int*)malloc(sizeof(int));
     times[0] = 0;
     Fibonacci(n,times);
     printf("%d\n",times[0]);
     return 0;
}

int Fibonacci(int n,int* times){
    if(n == 1 || n == 2){
        return 1;
    }
    else{
        times[0]++;
        return Fibonacci(n - 1,times)+Fibonacci(n - 2,times);
    }
}

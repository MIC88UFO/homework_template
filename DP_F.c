#include <stdio.h>
#include <stdlib.h>
#define n 30

int main()
{
    int f[n] = {0};
    int k;
    int count = 0;
    for(k = 0;k < n;k++){
        if(k == 1 || k == 2){
            f[k] = 1;
        }
        else{
            count++;
            f[k] = f[k - 1] + f[k - 2];
        }
    }
    printf("%d\n",count);
    return 0;
}

#include <stdio.h>

void PRN(int A[], int N, int i);

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    int N = 5;
    
    //TRIGGER CALL
    PRN(arr, N, N-1);

    return(0);
}

void PRN(int arr[], int N, int i)
{
    //Terminating condition
    if(i < 0 || i >= N)
    {
        return;
    }

    printf("arr[%d] : %d\n", i, arr[i]); //ACTION(i)
    PRN(arr, 5, i-1);
}
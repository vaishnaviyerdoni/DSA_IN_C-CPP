#include <stdio.h>

void prn(int A[], int N, int i);

int main(void)
{
    int N = 5;
    int A[5] = {10, 20, 30, 40, 50};
    
    //TRIGGER CALL
    prn(A, N, 0);
    
    return(0);
}

void prn(int A[], int N, int i)
{
    if(i >= N)
    {
        return;
    }

    printf("A[%d] : %d\n", i, A[i]); //ACTION(i)
    prn(A, N, i+1);
}
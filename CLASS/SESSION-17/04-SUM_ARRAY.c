#include <stdio.h>

int sum_array(int A[], int N, int i);

int main(void)
{
    int A[8] = {100, 200, 300, 400, 500, 600, 700, 800};
    int N = 8;
    static int summation;
    int i;

    //Recursion
    summation = sum_array(A, N, 0);
    printf("Summation of all elements in array (computed recursively) = %d\n", summation);

    //Iteration
    summation = 0; 
    for(i = 0; i < N; ++i)
        summation += A[i];
        printf("a[%d] : %d\n", i, A[i]); //the placement of print is altering the value of summation as well as the value at a particular index of an array: why??

    printf("Summation of all elements in array (computed iteratively) = %d\n", summation); 

    return(0);
}

int sum_array(int A[], int N, int i)
{
    //terminating condition
    if(i >= N)
    {
        return 0;
    }

    return A[i] + sum_array(A, N, i + 1);
}
#include <stdio.h> 

int sum_array(int A[], int N, int i); 

int main(void)
{
    int A[8] = {100, 200, 300, 400, 500, 600, 700, 800}; 
    int N = 8; 
    int summation; 
    int i;

    summation = sum_array(A, N, 0); 
    printf("Summation of all elements in array (computed recursively) = %d\n", summation); 

    summation = 0; 
    for(i = 0; i < N; ++i)
        summation += A[i]; 

    printf("Summation of all elements in array (computed iteratively) = %d\n", summation); 
    
    return (0); 
}

int sum_array(int A[], int N, int i)
{
    if(i >= N)
        return (0); 
    
    return A[i] + sum_array(A, N, i+1);  
}
#include <stdio.h>
#include <stdlib.h>

int factorial(int N);

int main(void)
{
    printf("Factorial(5):%d", factorial(5));

    return (0);
}

int factorial(int N)
{
    //terminating codn
    if(N == 0)
    {
        return(1);
    }

    int tmp = factorial(N-1);
    return(N*tmp);
}
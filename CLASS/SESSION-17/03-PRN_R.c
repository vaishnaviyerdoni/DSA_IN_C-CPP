#include <stdio.h>

void prn_r(int a[], int N, int i);

int main(void)
{
    int N = 5;1
    int a[] = {100, 200, 300, 400, 500};

    //TRIGGER CALL
    prn_r(a, N, 0);

    return (0);
}

void prn_r(int a[], int N, int i)
{
    //terminating condition
    if(i >= N)
    {
        return;
    }

    prn_r(a, N, i+1);//Calling beffore action results in printing in reverse order
    printf("a[%d] : %d\n", i, a[i]); //ACTION(i)
}
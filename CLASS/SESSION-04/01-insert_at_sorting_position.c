#include <stdio.h>

//declare necessary functions

void insert_at_sorting_position(int a[], int size);
void display(int a[], int N, const char* msg);

int main(void) {
    int a[6] = {10, 20, 30, 40, 50, 15};
    int b[5] = {100, 200, 300, 400, 5};

    display(a, 6, "Displaying \'a\' before insert_at_sorting_position():");
    insert_at_sorting_position(a, 6);
    display(a, 6, "Displaying \'a\' after insert_at_sorting_position():");

    display(b, 5, "Displaying \'b\' before insert_at_sorting_position():");
    insert_at_sorting_position(b, 5);
    display(b, 5, "Displaying \'b\' after insert_at_sorting_position():");

    return 0;
}

/*
    pre-condtions for the iasp:
    C1 : N >= 2
    C2 : a[0] .... a[N-2] is sorted;
         but a[0] to a[N-1] is not necessarily sorted

    post-condition for iasp: 
        entire array is sorted i.e a[0] to a[N-1] is all sorted;
*/


void insert_at_sorting_position(int a[], int N) {
    int temp;
    int i;

    temp = a[N - 1];
    i = N - 2;

    while(i >= 0 && a[i] > temp) {
        a[i + 1] = a[i];
        i = i - 1;
    }

    a[i + 1] = temp;
}

void display(int a[], int N, const char* msg){
    
    if(msg != NULL)
        puts(msg);

    int i;

    i = 0;
    while(i < N)
    {
        printf("a[%d]:%d\n", i, a[i]);
        i = i + 1;
    }
}

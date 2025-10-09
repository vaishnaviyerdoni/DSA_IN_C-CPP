#include <stdio.h>

void display(int arr[], int N, const char* msg);
void right_rotate(int arr[], int N);

int main(void) {

    int a[5] = {1,2,3,4,0};
    int b[3] = {22,33,11};

    display(a,5,"Displaying array \'a\' before right rotate:");
    right_rotate(a,5);
    display(a,5,"Displaying array \'a\' after right rotate:");


    display(b,3,"Displaying array \'b\' before right rotate:");
    right_rotate(b,3);
    display(b,3,"Displaying array\'b\' after right rotate: ");

    return 0;
}

void right_rotate(int arr[], int N) {
    int i, key;

    key = arr[N-1];
    i = N-2;

    while(i >= 0) {
        arr[i + 1] = arr[i];
        i = i - 1;
    }
    arr[i + 1] = key;
}

void display(int arr[], int N, const char* msg) {
    if(NULL != msg) {
        puts(msg);
    }

    int i;
    i = 0;
    while(i < N) {
        printf("a[%d] : %d\n", i, arr[i]);
        i = i + 1;
    }
}
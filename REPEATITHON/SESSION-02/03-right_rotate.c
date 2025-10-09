#include <stdio.h>

void display(int arr[], int N, const char* msg);

int main(void) {
    int a[5] = {30, 40, 50, 60, 20};
    display(a, 5, "Before right rotate: ");
    int key, i;

    key = a[4];
    for(i = 3; i >= 0; i--) {
        a[i + 1] = a[i];
    }

    a[i+1] = key;

    display(a, 5, "After right rotate: ");

    return 0;
}

void display(int arr[], int N, const char* msg) {

    if(NULL != msg) {
        puts(msg);
    }

    int i;
    for(i = 0; i < N; i++) {
        printf("a[%d] : %d\n", i, arr[i]);
    }
}
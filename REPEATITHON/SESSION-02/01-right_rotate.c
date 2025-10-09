#include <stdio.h>

void output(int arr[], int N, const char* msg);

int main(void) {
    int a[5] = {10, 20, 30, 40, 0};
    output(a, 5, "Before Right Rotate:");
    int i;
    int key = a[4];

    i = 3;
    while(i >= 0) {
        a[i + 1] = a[i];
        i = i - 1;
    }

    a[i + 1] = key;
    output(a, 5, "After right rotate");
}

void output(int arr[], int N, const char* msg){

    int i;

    if(NULL != msg) {
        puts(msg);
    }

    for(i = 0; i < N; i++) {
        printf("a[%d] : %d\n", i, arr[i]);
    }
}
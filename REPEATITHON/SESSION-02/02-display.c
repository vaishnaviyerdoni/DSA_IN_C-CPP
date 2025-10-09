#include <stdio.h>

void  display(int arr[], int N, const char* msg);

int main(void) {
    int a[5] = {12, 56, 24, 67, 23};
    int b[3] = {123, 246, 567};
    int c[1] = {5463};

    display(a, 5, "Displaying a:");
    display(b, 3, "Displaying b:");
    display(c, 1, "Displaying c:");

    return 0;
}

void display(int arr[], int N, const char* msg) {
    int i;

    if(NULL != msg) {
        puts(msg);
    } 

    i = 0;

    while(i < N) {
        printf("a[%d] : %d\n", i, arr[i]);
        i = i + 1;
    }
}
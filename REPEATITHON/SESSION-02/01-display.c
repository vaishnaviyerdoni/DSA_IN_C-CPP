#include <stdio.h>

void display(int arr[], int size, const char* msg);

int main(void) {
    int a[5] = {10, 20, 30, 40, 50};
    int b[3] = {100, 200, 300};
    int c[1] = {1000};

    display(a, 5, "Displaying a:");
    display(b, 3, "Displaying b:");
    display(c, 1, "Displaying c:");

    return 0;
}

void display(int arr[], int size, const char* msg) {
    int i;

    if(NULL != msg) {
        puts(msg);
    }

    i = 0;

    while(i < size) {
        printf("a[%d] : %d\n", i, arr[i]);
        i = i + 1;
    }
}
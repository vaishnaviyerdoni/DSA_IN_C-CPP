#include <stdio.h>

void output(int arr[], size_t N, const char* msg);

int main(void) {
    int a[6] = {35, 23, 564, 324, 43, 4};
    int b[4] = {134, 123, 3, 32};

    output(a, 6, "Displaying a:");
    output(b, 4, "Displaying b:");

    return 0;
}

void output(int arr[], size_t N, const char* msg){

    int i;

    if(NULL != msg) {
        puts(msg);
    }

    for(i = 0; i < N; i++) {
        printf("a[%d] : %d\n", i, arr[i]);
    }
}
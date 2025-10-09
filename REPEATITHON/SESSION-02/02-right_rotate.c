#include <stdio.h>

void output(int arr[], size_t N, const char* msg);

int main(void) {
    int a[6] = {100, 200, 300, 400, 500, 0};
    output(a, 6, "Before right rotate:");
    int temp;
    int i;

    temp = a[5];
    i = 4;
    while(i >= 0) {
        a[i+1] = a[i];
        i--;
    }

    a[i + 1] = temp;

    output(a, 6, "After right rotate:");

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
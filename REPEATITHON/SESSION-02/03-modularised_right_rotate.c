#include <stdio.h>

void output(int arr[], size_t N, const char* msg);
void right_rotate(int arr[], size_t N);

int main(void) {
    int a[6] = {3,5,7,9,11,1};

    output(a, 6, "Displaying  \'a\' before right rotate:");
    right_rotate(a, 6);
    output(a, 6, "Displaying \'a\' after right rotate:");
}

void output(int arr[], size_t N, const char* msg){
    int i;
    if(NULL != msg) {
        puts(msg);
    }

    for(i = 0; i < N; i++) {
        printf("arr[%d] : %d\n", i, arr[i]);
    }
}

void right_rotate(int arr[], size_t N) {
    int key, i;
    key = arr[N - 1];
    for(i = N - 2; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }

    arr[i + 1] = key;
}
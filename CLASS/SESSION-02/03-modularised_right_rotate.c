#include <stdio.h>

//declare necessary functions
void display(int arr[], int N);
void right_rotate(int arr[], int N);

int main(void) {

    int a[5] = {10, 20, 30, 40, 0};
  
    printf("The array \'b\'  before right rotate:\n");
    display(a, 5);

    right_rotate(a, 5);

    printf("The array \'b\' after right rotate:\n");
    display(a, 5);

    return 0;
}

void right_rotate(int arr[], int N) {
    int i;

    int temp = arr[N - 1]; //store ele from last index in temp variable
    i = N - 2; // set the counter variable to second index

    while(i >= 0) {
        arr[i + 1] = arr[i];
        i = i - 1;
    }

    arr[i + 1] = temp;
}

void display(int arr[], int N) {
    int i;
    i = 0;

    while(i < N) {
        printf("arr[%d] : %d\n", i, arr[i]);
        i = i + 1;
    }
}
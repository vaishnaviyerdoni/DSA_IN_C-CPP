#include <stdio.h>

//declare necessary func
void display(int arr[], int N);

int main(void){

    int a[5] = {20, 30, 40, 50, 10};

    printf("The array before right rotate:\n");
    display(a, 5);

    int i;
    int temp = a[4];
    i = 3;

    while(i >= 0) {
        a[i + 1] = a[i];
        i = i - 1;
    } 
    a[i + 1] = temp;

    printf("The array after right rotate:\n");
    display(a, 5);

    return 0;
}

void display(int arr[], int N) {
    
    int i;
    i = 0;

    while(i < N) {
        printf("arr[%d] : %d\n", i, arr[i]);
        i = i + 1;
    }
}
#include <stdio.h>

void display(int a[], int N, const char* msg);
void right_rotate(int a[], int N);

int main(void) {
    int a[10] = {10,15,20,25,30,35,40,45,50,5};

    display(a, 10, "Displaying \'a\' before right rotate:");
    right_rotate(a, 10);
    display(a,10, "Displaying \'a\' after right rotate:");

    return 0;
}

void right_rotate(int a[], int N) {
    int key, i;

    key = a[N-1];
    
    for(i=N-2; i >= 0; i--){
        a[i+1] = a[i];
    }

    a[i+1] = key;
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
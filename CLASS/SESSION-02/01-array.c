#include <stdio.h>

//declare func
void display(int arr[],int N);

int main(void){
    int a[5] = {10, 20, 30, 40, 50};
    int b[4] = {100, 200, 300, 400};
    int c[1] = {1000};

    display(a, 5);
    display(b, 4);
    display(c, 1);

    return 0;
}

void display(int arr[], int N) {
    puts("The array is: ");
    
    int i;
    i = 0;

    while(i < N) {
        printf("arr[%d] : %d\n", i, arr[i]);
        i = i + 1;
    }

}
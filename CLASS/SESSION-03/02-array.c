#include <stdio.h>
/*
    @goal : 
        You will be given anon empty array of integers.
        The array is filled in such a way that 
        all the negative numbers are stacked on the left of the array
        and all non negative are on stacked on the right of the array.

        Your Job is to right shift and rotate all non negative elements
    @boundry case:
        There may not be any negative element, in that case the entire array will right shifted and rotated
*/

//declare necessary functions
void display(int a[], int size);
void right_shift_and_rotate(int arr[], int size);

int main(void) {

    int b[8] = {-10, -5, -8, -3, 30, 40, 20, 10};
    int c[8] = {30, 10, 2, 25, 30, 16, 28, 40};

    //For array b
    printf("ARRAY \'b\' BEFORE RIGHT-SHIFT-AND-ROTATE:\n");
    display(b, 8);
    right_shift_and_rotate(b, 8);
    printf("ARRAY \'b\' AFTER RIGHT-SHIFT-AND-ROTATE:\n");
    display(b, 8);

    //For array c
    printf("ARRAY \'c\' BEFORE RIGHT-SHIFT-AND-ROTATE:\n");
    display(c, 8);
    right_shift_and_rotate(c, 8);
    printf("ARRAY \'c\' AFTER RIGHT-SHIFT-AND-ROTATE:\n");
    display(c, 8);

    return 0;
}

void right_shift_and_rotate(int arr[], int size){
    int temp = arr[size - 1];
    int i;

    i = size - 2;
    while(i >= 0 && arr[i] > 0) {
        arr[i + 1] = arr[i];
        i = i - 1;
    }

    arr[i + 1] = temp;

}

void display(int arr[], int size){
    int i;

    i = 0;

    while(i < size) {
        printf("arr[%d] : %d\n", i, arr[i]);
        i = i + 1;
    }
}
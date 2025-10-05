#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void input(int* p_array, int N);
void output(int* p_array, int N, const char* msg);
void sort(int* p_array, int N);

int main(void) {

    int* a = NULL;
    int N = 0;

    printf("Enter number of elements in array:");
    scanf("%d", &N);

    if(N <= 0) {

        puts("Bad size for array");
        exit(EXIT_FAILURE);
    }

    a = (int*)malloc(N * sizeof(int));
    if(NULL == a) {

        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    input(a, N); //array gets populated with random numbers
    output(a, N, "Before sort:"); //unsorted array is displayed
    sort(a, N); //array is sorted
    output(a, N, "After sort:"); //sorted array is displayed

    free(a);
    a = NULL;

    exit(EXIT_SUCCESS);
}

void input(int* p_array, int N){
    int cap = N * 10; //populates the array with random numbers
    int i;

    srand(time(0)); //set seed for random generator //seed?

    i = 0;

    while(i < N) {
        p_array[i] = rand() % cap; // cap is upper limit for random no.s
        i = i + 1;
    }
}


void output(int* p_array, int N, const char* msg){ //Displays the array
    
    int i;
    if(NULL != msg) {
        puts(msg);
    }

    i = 0;
    while(i < N) {
        printf("a[%d] : %d\n", i, p_array[i]);
        i = i + 1;
    }
}

void sort(int* p_array, int N){ //sorts the array => insertion sort algorithm
    int i, j;

    int key;

    j = 1; //array of two elements

    while(j < N) {
        key = p_array[j]; //last element in key variable
        i = j - 1; //assigning i to second last index

        while(i > -1 && p_array[i] > key) { //insert at sorting position algorithm
            p_array[i+1] = p_array[i];
            i = i - 1;
        }

        p_array[i+1] = key;

        j = j + 1;
    }
}

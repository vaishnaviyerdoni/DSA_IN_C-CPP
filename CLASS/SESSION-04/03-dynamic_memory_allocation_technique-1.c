#include <stdio.h> //for declaration of printf()
#include <stdlib.h> //for declaration of malloc(), free(), exit()
#include <string.h> //for declaration of memset()

struct Date {

    int day;
    int month;
    int year;
};

struct array{

    int* a;
    int N;
};

void dynamic_builtin(void);
void dynamic_user_defined(void);


int main(void) {

    dynamic_builtin();
    dynamic_user_defined_date();
    dynamic_user_defined_array();

    return 0;

}

void_builtln(void) {
    //1 : Declare a pointer and initialize it to NULL;
    int* ptr = NULL;

    //2 : Allocate dynamic memory using malloc() and do the validation check
    ptr = (int*)malloc(sizeof(int));
    if(NULL == ptr) {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    //3 : Initiliaze allocated memory instance to 0
    memset(ptr, 0, sizeof(int));

    //4, 5 : Read/ Write on the dynamically allocated instance

    *ptr = 100; //Write Operation
    int n = *ptr; // Read Operation
    printf("*ptr= %d\n", *ptr); //Read Operation

    //6 : When dynamic instance is no longer wanted, Release it and make pointer null
    free(ptr);
    ptr = NULL;
}

void dynamic_user_defined_date(){

}

void dynamic_user_defined_array(){

}
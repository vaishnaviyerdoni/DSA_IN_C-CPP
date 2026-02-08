#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date
{
    int day;
    int month;
    int year;
};

void test_malloc(void);
void test_calloc(void);
void test_realloc(void);
void test_cpa_calloc(void);
void* cpa_calloc(size_t no_of_elements, size_t size_per_element);

int main(void)
{
    test_malloc();
    test_calloc();
    test_cpa_calloc();

    return(0);
}

void test_malloc(void)
{
    puts("-----------------------Entered test_malloc()------------------------");
    char* ptr = (char*)malloc(16);
    if(!ptr)
    {
        puts("test_malloc():malloc():allocation error");
        return;
    }

    int i;
    for(i = 0; i < 16; ++i)
    {
        unsigned char n = ptr[i];
        printf("Content at index %d : %hhu\n", i, n);
    }

    free(ptr);
    ptr = NULL;

    puts("We have seen that memory block allocated by malloc() contains garbage values");
    puts("We can make use of memset() to zero out the content");

    ptr = (char*)malloc(16);
    if(!ptr)
    {
        puts("test_malloc():malloc():allocation error");
        return;
    }

    //initialize malloc'd block to zero
    memset(ptr, 0, 16);

    puts("Printing initialized memory block");
    for(i = 0; i < 16; ++i)
    {
        unsigned char n = ptr[i];
        printf("Content at %d : %hhu\n", i, n);
    }

    free(ptr);
    ptr = NULL;

    puts("-----------------------Leaving test_malloc()------------------------");

}

void test_calloc(void)
{
    puts("-----------------------Entered test_calloc()------------------------");

    int* p = (int*)calloc(1, sizeof(int));
    if(!p)
    {
        puts("test_calloc():calloc():allocation error");
        return;
    }

    printf("*p = %d\n", *p);
    free(p);
    p = NULL;

    struct Date* pdate = (struct Date*)calloc(1, sizeof(struct Date));
    if(!pdate)
    {
        puts("test_calloc():calloc():allocation error");
        return;
    }

    printf("pdate->day = %d, pdate->month = %d, pdate->year = %d\n",
            pdate->day, pdate->month, pdate->year);

    free(pdate);
    pdate = NULL;

    puts("-----------------------Leaving test_calloc()------------------------");    
}

void* cpa_calloc(size_t no_of_elements, size_t size_per_element)
{
    puts("-----------------------Entered cpa_calloc()------------------------");

    size_t size_in_bytes;
    size_in_bytes = no_of_elements * size_per_element;
    void* ptr = malloc(size_in_bytes);

    if(ptr)
        memset(ptr, 0, size_in_bytes);

    return(ptr);

    puts("-----------------------Leaving cpa_calloc()------------------------");
}

void test_cpa_calloc(void)
{
    puts("-----------------------Entered test_cpa_calloc()------------------------");

    int* p = (int*)cpa_calloc(1, sizeof(int));
    if(!p)
    {
        puts("test_calloc():calloc():allocation error");
        return;
    }

    printf("*p = %d\n", *p);
    free(p);
    p = NULL;

    struct Date* pdate = (struct Date*)cpa_calloc(1, sizeof(struct Date));
    if(!pdate)
    {
        puts("test_calloc():calloc():allocation error");
        return;
    }

    printf("pdate->day = %d, pdate->month = %d, pdate->year = %d\n",
            pdate->day, pdate->month, pdate->year);

    free(pdate);
    pdate = NULL;

    puts("-----------------------Leaving test_cpa_calloc()------------------------");
}

void test_realloc(void)
{
    puts("-----------------------Entered test_realloc()------------------------");
    //  void* realloc(void* old_ptr, size_t new_size);
    puts("-----------------------Leaving test_realloc()------------------------");
}
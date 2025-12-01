#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          //data instance
    struct node* prev; //backward link
    struct node* next; //forward link
};

void experiment_1(void);

int main(void)
{
    experiment_1();
    return(0);
}

void experiment_1(void)
{
    struct node* p_node = NULL;
    
}
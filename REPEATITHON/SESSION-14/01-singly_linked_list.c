//HEADER 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//symv
#define TRUE 0
#define FALSE 1
#define LIST_DATA_NOT_FOUND 2
#define SUCCESS 1
#define LIST_EMPTY 3

#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

#define SUCESS 1
#define TRUE 1
#define FALSE 0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

struct node
{
    int data;
    struct node* next;
}

struct node
{
    int data;
    struct node* next;
}

struct node
{
    int data;
    struct node* next;
}

struct node
{
    int data;
    struct node* next;
}

struct node
{
    int data;
    struct node* next;
}

struct node* create_list(void)
{
    struct node* p_new_list = NULL;

    p_new_list = (struct node*)malloc(sizeof(struct node));

    if(NULL == p_new_list)
    {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }

    p_new_list -> data = 0;
    p_new_list -> next =NULL;

    return(p_new_list);
}

struct node* create_list(void)
{
    struct node* head_node = NULL;

    head_node = (struct node*)malloc(sizeof(struct node));

    if(NULL == head_node)
    {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }

    head_node -> data = 0;
    head_node -> next = NULL;

    return(head_node);
}

struct node* create_list(void)
{
    struct head_node = NULL;

    head_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == head_node){
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }

    head_node -> data = 0;
    head_node -> next = NULL;

    return(head_node);
}


struct node* create_list(void)
{
    struct node* new_node = NULL;
    
    new_node = (struct_node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of memorty");
        exit(EXIT_FAILURE);
    }

    new_node -> data = 0;
    new_node ->next = NULL;

    return new_node;
}

struct node* create_list(void)
{
    struct node* mylist = NULL;

    mylist = (struct node*)malloc(sizeof(struct node));
    if(NULL == mylist)
    {
        puts("Out of memeory");
        exit(EXIT_FAILURE);
    }

    mylist -> data = 0;
    mylist -> next =  NULL;

    return mylist;
}

struct node* create_list(void)
{
    struct node* list = NULL:
    list = (struct node*)malloc(sizeof(struct node));

    if(NULL == list)
    {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }

    list -> data = 0;
    list -> next = NULL;

    return list;
}
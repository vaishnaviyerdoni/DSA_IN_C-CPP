//header files
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//Symbolic constants
#define TRUE 1
#define TRUE 1
#define TRUE 1
#define TRUE 1

#define SUCCESS 1
#define SUCCESS 1
#define SUCCESS 1
#define SUCCESS 1

#define FALSE 0
#define FALSE 0
#define FALSE 0
#define FALSE 0

#define LIST_DATA_NOT_FOUND 2
#define LIST_DATA_NOT_FOUND 2
#define LIST_DATA_NOT_FOUND 2
#define LIST_DATA_NOT_FOUND 2

#define LIST_EMPTY 3
#define LIST_EMPTY 3
#define LIST_EMPTY 3
#define LIST_EMPTY 3

//Node layout definitions
struct node
{
    int data;
    struct node* next;
};

//Interface function definition
//list creation functions
struct node* create_list(void)
{
    struct node* head_node = NULL;

    head_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == head_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    head_node -> data = 0;
    head_node -> next = NULL;

    return(head_node);
}

struct node* create_list(void)
{
    struct node* head_node = NULL;
    head_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == head_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    head_node -> data = 0;
    head_node -> next = NULL;

    return(head_node);
}

struct node* create_list(void)
{
    struct node* head_node = NULL;

    head_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == head_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    head_node -> data = 0;
    head_node -> next = NULL;

    return(head_node);
}

struct node* create_list(void)
{
    struct node*  head_node = NULL;
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
    struct node* head_node = NULL:
    head_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == head_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    head_node -> data = 0;
    head_node -> next = NULL:

    return(head_node);
}

//Data addition Functions
int insert_start(struct node* p_list, int new_data)
{
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = p_list -> next; //maintain the back pointer
    p_list -> next = new_node;

    return(SUCCESS);
}

int insert_start(struct node* p_list, int new_data)
{
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = p_list -> next; //back pointer
    p_list -> next = new_node;

    return(SUCCESS);
}

int insert_start(struct node* p_list, int new_data)
{
    struct node* new_node = NULL;
    new_node = (struc node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = p_list -> next;
    p_list -> next = new_node;

    return(SUCCESS);
}

int insert_start(struct node* p_list, int new_data)
{
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of Memory");
        xit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = p_list -> next;
    p_list -> next = new_node;

    return(SUCCESS);
}

int insert_start(struct node* p_list, int new_data)
{
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = p_list -> next;
    p_list -> next = new_node;

    return(SUCCESS);
}

int insert_end(struct node* p_list, int new_data)
{

}

int insert_end(struct node* p_list, int new_data)
{

}

int insert_end(struct node* p_list, int new_data)
{

}

int insert_end(struct node* p_list, int new_data)
{
    
}

int insert_end(struct node* p_list, int new_data)
{

}

int insert_after(struct node* p_list, int existing_data, int new_data)
{

}

int insert_after(struct node* p_list, int existing_data, int new_data)
{

}

int insert_after(struct node* p_list, int existing_data, int new_data)
{

}

int insert_after(struct node* p_list, int existing_data, int new_data)
{

}

int insert_after(struct node* p_list, int existing_data, int new_data)
{

}

int insert_before(struct node* p_list, int existing_data, int new_data)
{
    
}

int insert_before(struct node* p_list, int existing_data, int new_data)
{

}

int insert_before(struct node* p_list, int existing_data, int new_data)
{

}

int insert_before(struct node* p_list, int existing_data, int new_data)
{

}

int insert_before(struct node* p_list, int existing_data, int new_data)
{

}

//Get Functions
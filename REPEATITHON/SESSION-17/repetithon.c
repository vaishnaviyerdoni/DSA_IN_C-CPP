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
    struct node* run = NULL;
    struct node* new_node = NULL;
    
    //Allocate and Initialize the new node
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = NULL;

    //Locate the last node
    run = p_list;
    while(run -> next != NULL)
    {
        run = run -> next;
    }

    //Append the node to the last position
    run -> next = new_node;

    return(SUCCESS);
}

int insert_end(struct node* p_list, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;

    new_node = (struce node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = NULL;

    run = p_list;
    while(NULL != run -> next)
    {
        run = run -> next;
    }

    run -> next = new_node;

    return(SUCCESS);
}

int insert_end(struct node* p_list, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;

    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = NULL;

    run = p_list;
    while(NULL != run -> next)
    {
        run = run -> next;
    }

    run -> next = new_node;

    return(SUCCESS);
}

int insert_end(struct node* p_list, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;

    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_SUCCESS);
    }

    new_node -> data = new_data;
    new_node -> next = NULL;

    run = p_list;
    while(run -> next != NULL)
    {
        run = run->next;
    }

    run -> next = new_node;

    return(SUCCESS);
}

int insert_end(struct node* p_list, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;

    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = NULL;

    run = p_list;
    while(NULL != run -> next)
    {
        run = run -> next;
    }

    run -> next = new_node;

    return(SUCCESS);
}

int insert_after(struct node* p_list, int existing_data, int new_data)
{
    struct node* existing_node = NULL;
    struct node* new_node = NULL;
    struct node* run = NULL;

    //search for the node containing first occurence of existing data
    run = p_list -> next;
    while(run != NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }

        run = run -> next;
    }

    if(NULL == run )
        return(LIST_DATA_NOT_FOUND);

    existing_node = run;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = existing_node -> next; //back pointer

    existing_node -> next = new_node; //new_node  attached to the next of existing node having existing data

    return(SUCCESS);
}

int insert_after(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* existing_node = NULL;
    struct node* new_node = NULL;

    run = p_list -> run;
    while(run != NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }

        run = run -> next;
    }

    if(NULL == run)
    {
        return(LIST_DATA_NOT_FOUND);
    }

    existing_node = run;
    new_node = (struct node*)malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data =  new_data;
    new_node -> next = existing_node -> next; //back pointer
    existing_node -> next = new_node;

    return(SUCCESS);
}

int insert_after(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;
    struct node* existing_node = NULL:

    //Search for the node that has the first occurence of the existing data
    run = p_list -> next;
    while (run != NULL)
    {
        if(run->data == existing_data)
        {
            break;
        }
        run = run -> next;
    }

    if(NULL == run)
    {
        return(LIST_DATA_NOT_FOUND);
    }

    //Allocate and INItialize the new node
    existing_node = run;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = existing_node -> next;
    existing_node -> next = new_node;

    return(SUCCESS);
}

int insert_after(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;
    struct node* existing_node = NULL;

    //Searching for the node with first occurence of existing data
    run = p_list -> next;
    while (run != NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }

        run = run -> next;
    }

    if(run == NULL)
        return(LIST_DATA_NOT_FOUND;)

    //Allocate the new_node and Initialise
    existing_node = run;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = existing_node -> next; // back pointer
    existing_node -> next = new_node;

    return(SUCCESS);
}

int insert_after(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;
    struct node* existing_node = NULL;

    //Search for the node with existing
    run = p_list -> next;
    if(run != NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }

        run =  run -> next;
    }

    if(run == NULL)
        return(LIST_DATA_NOT_FOUND);

    //Allocate and Initialize the node
    existing_node = run;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node ==  NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = existing_node -> next;
    existing_node -> next = new_node;

    return(SUCCESS);
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
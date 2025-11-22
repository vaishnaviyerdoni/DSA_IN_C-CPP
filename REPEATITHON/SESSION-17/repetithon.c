//header files
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//Symbolic constants
#define TRUE                1
#define TRUE                1
#define TRUE                1
#define TRUE                1

#define SUCCESS             1
#define SUCCESS             1
#define SUCCESS             1
#define SUCCESS             1

#define FALSE               0
#define FALSE               0
#define FALSE               0
#define FALSE               0

#define LIST_DATA_NOT_FOUND 2
#define LIST_DATA_NOT_FOUND 2
#define LIST_DATA_NOT_FOUND 2
#define LIST_DATA_NOT_FOUND 2

#define LIST_EMPTY          3
#define LIST_EMPTY          3
#define LIST_EMPTY          3
#define LIST_EMPTY          3

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

int insert_before(struct node* p_list, int existing_data, int new_data)
{
    struct node* run_previous = NULL;
    struct node* run = NULL;
    struct node* new_node = NULL;

    //Search for the node having the first occurrence of the data
    run_previous = p_list;
    run = p_list -> next;
    while(run != NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }

        run = run -> next;
    } 

    if(run == NULL)
        return(LIST_DATA_NOT_FOUND);

    //Allocate an Initialize the new data
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    //Insert the new node at an appropriate position
    new_node -> next = run;
    run_previous -> next = new_node;

    return(SUCCESS);
}

int insert_before(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;
    struct node* run_previous = NULL;

    //Search for the node having first occurence of the 
    run_previous = p_list;
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
        return(LIST_DATA_NOT_FOUND);
    
    //Initialize and allocate the new node
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out off Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = run;
    run_previous -> next =  new_node;

    return(SUCCESS);
}

int insert_before(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;
    struct node* run_previous = NULL;

    //Search for the node with first occurence of the existing data
    run_previous = p_list;
    run =  p_list -> next;
    while(run != NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }

        run = run -> next;
    }

    if(run == NULL)
        return(LIST_DATA_NOT_FOUND);

    //ALlocate and Initialize the new_node
    new_node = (struct node*)struct(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = existing_data;
    new_node -> next = run;
    run_previous -> next = new_node;

    return(SUCCESS);
}

int insert_before(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;
    struct node* run_previous =  NULL;

    //Search for the node with first occurence of the existing data
    run_previous = p_list;
    run = p_list -> next;
    while(run != NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }
        run = run -> next;
    }

    if(run == NULL)
        return(LIST_DATA_NOT_FOUND);

    //Allocate abd Initialize the new_node
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = run;
    run_previous -> next = new_node;

    return(SUCCESS);
}

int insert_before(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;
    struct node* run_previous = NULL;
    
    //search for the node having the first occurence of the existing data
    run_previous = p_list;
    run =  p_list -> next;
    while(run !=  NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }

        run = run -> next;
    }

    if(run == NULL)
        return(LIST_DATA_NOT_FOUND);

    //Allocate and Initialize the new_node
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    //Insert the new node at the appropriate position
    new_node -> run;
    run_previous -> next = new_node;

    return(SUCCESS);
}

//Get Functions
int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data;

    return(SUCCESS);
}

int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data;

    return(SUCCESS);
}

int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data;

    return(SUCCESS);
}

int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data;

    return(SUCCESS);
}

int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list -> next == NULL)
        return(LIST_EMPTY);
    
    *p_start_data = p_list -> next -> data;

    return(SUCCESS);
}

int get_end(struct node* p_list, int* p_end_data)
{
    struct node* run = NULL;

    if(p_list -> next == NULL)
        return(LIST_EMPTY);
    
    run = p_list -> next;
    while (run-> next  != NULL)
    {
        run =  run -> next;
    }

    *p_end_data = run -> data;

    return(SUCCESS);   
}

int get_end(struct node* p_list, int* p_end_data)
{
    struct node* run = NULL;

    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    run = p_list -> next;
    while(run -> next != NULL)
    {
        run = run -> next;
    }

    *p_end_data = run -> data;

    return(SUCCESS);
}

int get_end(struct node* p_list, int* p_end_data)
{
    struct node* run = NULL;

    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    run = p_list -> next;
    while(run -> next != NULL)
    {
        run = run -> next;
    }

    *p_end_data = run -> data;

    return(SUCCESS);
}

int get_end(struct node* p_list, int* p_end_data)
{
    struct node* run = NULL;

    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    run = p_list -> next;
    while (run -> next != NULL)
    {
        run = run -> next;
    }

    *p_end_data = run -> data;

    return(SUCCESS);
}

int get_end(struct node* p_list, int* p_end_data)
{
    struct node* run = NULL;

    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    run = p_list -> next;
    while(run -> next != NULL)
    {
        run = run -> next;
    }

    *p_end_data = run -> data;

    return(SUCCESS);
}

int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* delete_node = NULL;
    struct node* delete_next = NULL;
    struct node* delete_previous = NULL;

    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data;

    delete_previous = p_list;
    delete_node = p_list -> next;
    delete_next = p_list -> next -> next;

    delete_previous -> next = delete_next; // now headnode points to 2nd node, making it the 1st one, since we will pop the original 1st node

    free(delete_node);
    delete_node = NULL;

    return(SUCCESS);
}

int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* delete_node = NULL;
    struct node* delete_next = NULL;
    struct node* delete_previous = NULL;

    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data;

    delete_previous = p_list;
    delete_node = p_list -> next; //node that headnode points to, so 1st node, one that we intend to pop
    delete_next = p_list -> next -> next; //2nd node, that 1st is currently pointing

    delete_previous -> next = delete_next; //now 2nd node is 1st

    free(delete_node); //pop the first node
    delete_node = NULL; //make the first node = NULL

    return(SUCCESS);
}

int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* delete_node = NULL;
    struct node* delete_next = NULL;
    struct node* delete_previous = NULL;

    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data;


    delete_previous = p_list; //headnode
    delete_node = p_list -> next; //1st node that headnode points to
    delete_next = p_list -> next -> next; //2nd node that will become 1st. once 1st is popped

    delete_previous -> next = delete_next; //address of 2nd put in head_node's next, hence 2nd node becomes 1st

    free(delete_node);
    delete_node = NULL;

    return(SUCCESS);
}

int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* delete_next = NULL;
    struct node* delete_node = NULL;
    struct node* delete_previous = NULL;

    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data;

    delete_previous = p_list;
    delete_node = p_list -> next;
    delete_next = p_list -> next -> next;

    delete_previous -> next = delete_next;

    free(delete_node);
    delete_node = NULL;

    return(SUCCESS);
}

int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* delete_next = NULL;
    struct node* delete_node = NULL;
    struct node* delete_previous = NULL;

    if (p_list -> next == NULL)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data;

    delete_previous = p_list;
    delete_node = p_list -> next;
    delete_next = p_list -> next -> next;

    delete_previous -> next = delete_next;

    free(delete_node);
    delete_node = NULL;

    return(SUCCESS);
}
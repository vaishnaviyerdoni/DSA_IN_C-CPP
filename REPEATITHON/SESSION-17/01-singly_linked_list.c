//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//symbolic constants
#define SUCCESS             1
#define TRUE                1
#define FALSE               0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

//Node Layout Definition
struct node
{
    int data;
    struct node* next;
};

//Interface Functions Definition
//List Creation Function
struct node* create_list(void);

//Data Insertion Functions
int insert_start(struct node* p_list, int new_data);
int insert_end(struct node* p_list, int new_data);
int insert_after(struct node* p_list, int existing_data, int new_data);
int insert_before(struct node* p_list, int existing_data, int new_data);

//get functions
int get_start(struct node* p_list, int* p_start_data);
int get_end(struct node* p_list, int* p_end_data);

//pop Functions
int pop_start(struct node* p_list, int* p_start_data);
int pop_end(struct node* p_list, int* p_end_data);

//remove Functions
int remove_start(struct node* p_list);
int remove_end(struct node* p_list);
int remove_data(struct node* p_list, int r_data);

//miscellaneous Functions
int find(struct node* p_list, int f_data);
int is_list_empty(struct node* p_list);
int get_list_length(struct node* p_list);
void show(struct node* p_list, const char* msg);

//List Destruction Function
int destroy_list(struct node* p_list);

//Client of the list
int main(void)
{
    return(0);
}

//Server of the List
//Interface Function Definition
//List creation function
struct node* create_list(void)
{
    struct node* head_node = NULL;
    head_node = (struct node*)malloc(sizeof(struct node));
    if(head_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    head_node -> data = 0;
    head_node -> next = NULL;

    return(head_node);
}

//Data addition Function
int insert_start(struct node* p_list, int new_data)
{
    //Declare, Allocare and Initialize the new node
    struct node* new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    //Insert the new node at the appropriate position0
    new_node -> data = new_data;
    new_node -> next = p_list -> next; //back pointer;
    p_list -> next =  new_node;

    return(SUCCESS);
}

int insert_end(struct node* p_list, int new_data)
{
    //Declare necessary instances of struct node
    struct node* new_node =  NULL;
    struct node* run = NULL;

    //Loop through the list to find the last position
    run = p_list;
    while(run-> next != NULL)
    {
        run =  run -> next;
    }

    //Allocate and Initialize the new node
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = NULL;
    
    //Insert the node at the appropriate position
    run -> next = new_node;

    return(SUCCESS);
}

int insert_after(struct node* p_list, int existing_data, int new_data)
{
    //DEclare necessary instances of the struct node
    struct node* run = NULL;
    struct node* new_node = NULL;
    struct node* existing_node = NULL;

    //find the node that has first occurence of data
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

    //Allocate and initialize the new node
    existing_node = run; //this is what i did - run = existing_node;

    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;

    //Insert new node at the appropriate position
    new_node -> next = existing_node -> next;
    existing_node -> next = new_node;

    return(SUCCESS);
}

int insert_before(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* new_node = NULL;
    struct node* run_previous = NULL;

    //search the node with first occurence of the existing data
    run_previous = p_list;
    run = p_list -> next;
    while(run != NULL)
    {
        if (run-> data = existing_data)
        {
            break;
        }
        run = run -> next;
    }

    if(run == NULL)
        return(LIST_DATA_NOT_FOUND);

    //Allocate and initialize new_node
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        puts("Out of Memory");
        eixt(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = run;// back pointer

    //Insert the new node at the appropriate position
    run_previous -> next = new_node;

    return(SUCCESS);
}

//get functions
int get_start(struct node* p_list, int* p_start_data)
{
    
}

int get_end(struct node* p_list, int* p_end_data)
{

}

//pop Functions
int pop_start(struct node* p_list, int* p_start_data)
{

}

int pop_end(struct node* p_list, int* p_end_data)
{

}

//remove Functions
int remove_start(struct node* p_list)
{

}

int remove_end(struct node* p_list)
{

}

int remove_data(struct node* p_list, int r_data)
{

}

//miscellaneous Functions
int find(struct node* p_list, int f_data)
{

}

int is_list_empty(struct node* p_list)
{

}

int get_list_length(struct node* p_list)
{

}

void show(struct node* p_list, const char* msg)
{

}

//List Destruction Function
int destroy_list(struct node* p_list)
{

}

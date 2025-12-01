#include <stdio.h>

#define SUCCESS 1
#define TRUE    1
#define FALSE   0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

typedef int data_t;
typedef int status_t;
typedef int len_t;

typedef struct node node_t;
typedef node_t list_t;

//Node layout definition
struct node
{
    data_t data;
    struct node* prev;
    struct node* next;
};
//  Helper 
//  Doubly linked list 
//  remove_end() | pop_end() | insert_end() 
//  These three functions require an address of the last node. 
//  last node is defined as follows: 
//  if the list is not empty then the last node with data whose next pointer is NULL is the last node. 
//  if the list is empty then the dummy node is the last node. 

int get_last_node(struct node* p_list, struct node* last_node)
{
    struct node* run = NULL;
    run = p_list;
    while(run != NULL)
    {
        run = run -> next;
    }

    //run is last node
    last_node =  run;
    return(SUCCESS);
}


//  Design and implement a helper function which fetches the "LAST NODE" of the list (last node is defined in the above sense)


//////////// Helper function for singly linked list/////////////////////
//  In singly linked list, we require last node and its previous node (when the linked list is not empty)
//  Sometimes we are require a node having a given data and its previous node. 

//  Design and implement function for each of the above requirement 

int get_prev_and_last_node(struct node* p_list, struct node* prev_node, struct node* last_node)
{
    struct node* run_previous = NULL;
    struct node* run = NULL;

    run_previous = p_list;
    run = p_list -> next;
    while(run != NULL)
    {
        run_previous = run;
        run = run -> next;
    }

    prev_node = run_previous;
    last_node = run;

    return(SUCCESS);
}

//MASSIVE HINT - node pointer should not be a return value
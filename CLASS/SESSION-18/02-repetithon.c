#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <string.h>

#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

struct node
{
    int data;
    struct node* next;
};

int pop_start(struct node* p_list, int* p_start_data);

int main(void)
{

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

    delete_previous -> next = delete_next;

    free(delete_node);
    delete_node = NULL;

    return(SUCCESS);
}

int pop_start(struct node* p_list, int* p_start_end)
{
    struct node* delete_next = NULL;
    struct node* delete_node = NULL;
    struct node* delete_previous = NULL;

    if(p_list -> next == NULL) 
        return(LIST_EMPTY);

    *p_start_end = p_list -> next -> data;

    delete_previous = p_list;
    delete_node = p_list -> next;
    delete_next = p_list -> next -> next;
    
    delete_previous -> next =  delete_next;

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
    delete_node = p_list -> next;
    delete_next = p_list -> next -> next;

    delete_previous -> next = delete_next;

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
    delete_node = p_list -> next;
    delete_node = p_list -> next -> next;

    delete_previous -> next = delete_next;

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
    delete_node = p_list -> next;
    delete_next = p_list -> next -> next;
    
    delete_previous -> next = delete_next;

    free(delete_node);
    delete_node = NULL;

    return(SUCCESS);
}
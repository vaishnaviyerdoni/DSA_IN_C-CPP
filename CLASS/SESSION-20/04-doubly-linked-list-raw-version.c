#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//Node Layout DEfinition
struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

//Interface Functions
//List creation function
struct node* create_list(void);

//data addition functions
int insert_start(struct node* p_list, int new_data);
int insert_end(struct node* p_list, int new_data);
int insert_after(struct node* p_list, int e_data, int new_data);
int insert_before(struct node* p_list, int e_data, int new_data);

//get functions
int get_start(struct node* p_list, int* p_start_data);
int get_end(struct node* p_list, int* p_end_data);

//pop functions
int pop_start(struct node* p_list, int* p_start_data);
int pop_end(struct node* p_list, int* p_end_data);

//remove functions
int remove_start(struct node* p_list);
int remove_end(struct node* p_list);
int remove_data(struct node* p_list, int e_data);

//miscellaneous functions
int is_list_empty(struct node* p_list);
int get_list_length(struct node* p_list);
int find(struct node* p_list, int f_data);
void show(struct node* p_list, const char* msg);

//list destruction function
int destroy_list(struct node* p_list);

//Client of List
int main(void)
{
    return(0);
}

//Interface Fucntions
struct node* create_list(void)
{
    struct node* head_node = NULL;
    if(NULL == head_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    head_node -> data  = -1;
    head_node -> prev = NULL;
    head_node -> next = NULL;

    return(head_node);
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


}

int insert_end(struct node* p_list, int new_data);
int insert_after(struct node* p_list, int e_data, int new_data);
int insert_before(struct node* p_list, int e_data, int new_data);

int remove_start(struct node* p_list);
int remove_end(struct node* p_list);
int remove_data(struct node* p_list, int e_data);

int destroy(struct node* p_list);
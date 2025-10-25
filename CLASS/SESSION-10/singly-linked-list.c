// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//Symbolic Constants
#define SUCCESS             1
#define TRUE                1
#define FALSE               0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

// Node Layout Definition
struct node {

    int data;
    struct node* next;
};

//Interface Function Declarations
//List Creation Function
struct node* create_list(void);

//Data Addition Functions
int insert_start(struct node* p_list, int new_data);
int insert_end(struct node* p_list, int new_data);
int insert_after(struct node* p_list, int existing_data, int new_data);
int insert_before(struct node* p_list, int existing_data, int new_data);

//Get Functions
int get_start(struct node* p_list, int* p_start_data);
int get_end(struct node* p_list, int* p_end_data);

//Pop Functions
int pop_start(struct node* p_list, int* p_start_data);
int pop_end(struct node* p_list, int* p_end_data);

//Remove Functions
int remove_start(struct node* p_list);
int remove_end(struct node* p_list);
int remove_data(struct node* p_list, int r_data);

//Miscellaneous Functions
int find(struct node* p_list, int f_data);
int get_list_length(struct node* p_list);
int is_list_empty(struct node* p_list);
void show(struct node* p_list, const char* msg);

//Destruction Function
int destroy_list(struct node* p_list);

//Client of Linked List
int main(void) {

    struct node* p_list = NULL;
    int data, start_data, end_data;
    int length;

    static const char* line = "------------------------------------------------------------------------";

    p_list = create_list();
    assert(p_list != NULL);
    printf("List created Successfully\n");
    puts(line);

    printf("Testing assertions on the empty list:\n");
    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);
    assert(get_start(p_list, &start_data) == LIST_EMPTY);
    assert(get_end(p_list, &end_data) == LIST_EMPTY);
    assert(pop_start(p_list, &start_data) == LIST_EMPTY);
    assert(pop_end(p_list, &end_data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);
    printf("All assertions on the empty list are successful\n");
    puts(line);

    show(p_list, "Showing empty list immediately after creation");
    puts(line);
    
    return 0;
}

//Server of Linked List
//Interface Function Definitions
//List Creation Function
struct node* create_list(void)
{
    struct node* head_node = NULL;

    head_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == head_node) {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    head_node -> data = 0;
    head_node -> next = NULL;

    return (head_node);
}

//Data Addition Functions
int insert_start(struct node* p_list, int new_data)
{
    struct node* new_node = NULL;
    
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node) {
        puts("out of memory");
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
    
    //Step 1 - Allocate and Initialize new node
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = NULL;

    //Step 2 - Locate the last node
    run = p_list;
    while(run -> next != NULL) 
    {
        run = run-> next;
    }

    //Step 3 - Append the new node at the last position
    run -> next = new_node;

    return(SUCCESS);
    
}

int insert_after(struct node* p_list, int existing_data, int new_data)
{
    struct node* existing_node = NULL;
    struct node* run = NULL;
    struct node* new_node = NULL;

    //Step 1 - Search for the node containing the first occurence of the existing data
    run = p_list -> next;
    while(run != NULL)
    {
        if(run -> data == existing_data) 
        {
            break;
        }
        run = run -> next;
    }

    // If existing data is not found then return error as such
    if(run == NULL) {
        return (LIST_DATA_NOT_FOUND);
    }

    //Step 2 - Allocate and Initialize the new node
    existing_node = run;
    new_node = (struct node*)malloc(sizeof(struct node));

    if(NULL == new_node)
    {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;

    //Step 3 - Insert the new node at its appropriate position
    new_node -> next = existing_node -> next;
    existing_node -> next = new_node;

    return(SUCCESS);
}

int insert_before(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;
    struct node* new_node = NULL;

    /*
        Step 1 - Search for the first occurence of the existing data
                 maintaining the back pointer
    */
    run_previous = p_list;
    run = p_list -> next;

    while(run != NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }

        run_previous = run;
        run = run -> next;
    }

    //If the existing data is not found throughout the list then return an error saying as such
    if(run == NULL){
        return (LIST_DATA_NOT_FOUND);
    }

    //Step 2 - Allocate and Initialize the new node
    new_node = (struct node*)malloc(sizeof(struct node));

    if(NULL == new_node) {
        puts("out of memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;

    //Step 3 - Insert new node at the appropriate position
    new_node -> next = run;
    run_previous -> next = new_node;

    return(SUCCESS);
}

//Get Functions
int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list -> next == NULL)
    {
        return(LIST_EMPTY);
    }

    *p_start_data = p_list -> next -> data;
    
    return(SUCCESS);
}


int get_end(struct node* p_list, int* p_end_data)
{
    struct node* run = NULL;

    if(p_list -> next == NULL) {
        return(LIST_EMPTY);
    }

    run = p_list -> next;

    while(run -> next !=  NULL){
        run = run -> next;
    }
    *p_end_data = run -> data;

    return(SUCCESS);
}

//Pop Functions
int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* delete_previous = NULL;
    struct node* delete_node = NULL;
    struct node* delete_next = NULL;

    if(p_list -> next == NULL){
        return (LIST_EMPTY);
    }

    *p_start_data = p_list -> next -> data;

    delete_previous = p_list;
    delete_node = p_list -> next;
    delete_next = p_list -> next -> next;

    delete_previous -> next = delete_next;

    free(delete_node);
    delete_node = NULL;

    return(SUCCESS);
}

int pop_end(struct node* p_list, int* p_end_data)
{
    struct node* run = NULL; 
    struct node* run_previous = NULL; 

    if(p_list->next == NULL)
        return (LIST_EMPTY); 

    run_previous = p_list; 
    run = p_list->next; 
    while(run->next != NULL)
    {
        run_previous = run; 
        run = run->next; 
    }

    *p_end_data = run->data; 

    free(run); 
    run = NULL; 
    run_previous->next = NULL; 

    return (SUCCESS); 
}


//Remove Functions
int remove_start(struct node* p_list)
{
    struct node* delete_previous = NULL;
    struct node* delete_node = NULL;
    struct node* delete_next = NULL;

    if(p_list -> next == NULL){
        return (LIST_EMPTY);
    }

    delete_previous = p_list;
    delete_node = p_list -> next;
    delete_next = p_list -> next -> next;

    delete_previous -> next = delete_next;

    free(delete_node);
    delete_node = NULL;

    return(SUCCESS);
}

int remove_end(struct node* p_list)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;

    if(NULL == p_list-> next){
        return(LIST_EMPTY);
    }

    run_previous = p_list;
    run = p_list -> next;
    while(run -> next != NULL) {
        run_previous = run;
        run = run -> next;
    }

    free(run);
    run = NULL;
    run_previous = NULL;

    return(SUCCESS);
}

int remove_data(struct node* p_list, int r_data)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;

    run_previous = p_list;
    run = p_list -> next;

    while(NULL != run) {
        if(run -> data == r_data) {
            break;
        }

        run_previous = run;
        run = run -> next;
    }

    if( run == NULL) {
        return(LIST_DATA_NOT_FOUND);
    }

    run_previous -> next = run -> next;
    free(run);
    run = NULL;

    return (SUCCESS);
}

//Miscellaneous Functions
int find(struct node* p_list, int f_data)
{
    struct node* run = NULL;

    run = p_list -> next;
    while(NULL != run) {
        if(run -> data = f_data) {
            return(TRUE);
        }

        run = run -> next;
    }

    return(FALSE);
}

int get_list_length(struct node* p_list)
{  
    int len = 0;
    struct node* run = NULL;

    run = p_list -> next;
    while(run != NULL) {
        len = len + 1;
        run = run -> next;
    }

    return len;
}

int is_list_empty(struct node* p_list)
{
    return (p_list -> next == NULL);
}

void show(struct node* p_list, const char* msg)
{
    struct node* run = NULL; 

    if(msg != NULL)
        puts(msg); 

    printf("[START]->"); 
    run = p_list->next; 
    while(run != NULL)
    {
        printf("[%d]->", run->data); 
        run = run->next; 
    }
    printf("[END]\n"); 
}

//Destruction Function
int destroy_list(struct node* p_list)
{
    struct node* run = NULL;
    struct node* run_next = NULL;

    run = p_list;
    run_next = p_list -> next;

    while(run != NULL) {

        run_next = run -> next;
        free(run);
        run = run_next;
    }

    return(SUCCESS);
}
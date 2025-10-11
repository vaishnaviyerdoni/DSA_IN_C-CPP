// Header Files
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//Symbolic Constants
#define SUCCESS             0
#define TRUE                1
#define FALSE               0
#define LIST_DATA_NOT_FOUND 1
#define LIST_EMPTY          2

// Node Layout Definition
struct node {

    int data;
    struct node* next;
}

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


    return 0;
}

//Server of Linked List
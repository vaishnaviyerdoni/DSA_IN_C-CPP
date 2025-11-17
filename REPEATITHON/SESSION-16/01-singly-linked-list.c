//Import all the necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//Define the Symbolic constants
#define SUCCESS             1
#define TRUE                1
#define FALSE               0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

//Node definition layout
struct node
{
    int data;
    struct node* next;
};

//Interface Function Declaration
//List Creation function
struct node* create_list(void);

//Data addition functions
int insert_start(struct node* p_list, int new_data);
int insert_end(struct node* p_list, int new_data);
int insert_after(struct node* p_list, int existing_data, int new_data);
int insert_before(struct node* p_list, int existing_data, int new_data);

//Get functions
int get_start(struct node* p_list, int* p_start_data);
int get_end(struct node* p_list, int* p_end_data);

//Pop functions
int pop_start(struct node* p_list, int* p_start_data);
int pop_end(struct node* p_list, int* p_end_data);

//Remove functions
int remove_start(struct node* p_list);
int remove_end(struct node* p_list);
int remove_data(struct node* p_list, int r_data);

//Miscellaneous Functions
int find(struct node* p_list, int f_data);
int get_list_length(struct node* p_list);
int is_list_empty(struct node* p_list);
void show(struct node* p_list, const char* msg);

//List destruction functions
int destroy_list(struct node* p_list);

//Client of the list
int main(void)
{
    struct node* p_list = NULL;

    int status;
    int data, start_data, end_data;
    int length;

    static const char* line = "-----------------------------------------------------------------------";

    p_list = create_list();
    assert(p_list != NULL);
    puts(line);
    printf("List created Successfully!\n");
    puts(line);

    printf("Testing assertions on empty list:\n");
    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);
    assert(get_start(p_list, &start_data) == LIST_EMPTY);
    assert(get_end(p_list, &end_data) == LIST_EMPTY);
    assert(pop_start(p_list, &start_data) == LIST_EMPTY);
    assert(pop_end(p_list, &end_data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);
    printf("All Assertions are on empty list are successful!\n");
    puts(line);

    show(p_list, "Showing empty list right after creation:");
    puts(line);

    //insert start
    for(data = 1; data <= 5; ++data) //adds 10, 20, 30, 40, 50 at the start of the list
    {
        status = insert_start(p_list, data * 10);
        assert(status == SUCCESS);
        printf("%d inserted successfully at the start of the list\n", data * 10);
    }
    puts(line);
    show(p_list, "Showing list after inserting 5 data elements at the start:");
    puts(line);

    //insert end
    for(data = 1; data <= 5; ++data)
    {
        status = insert_end(p_list, data * 5);
        assert(status == SUCCESS);
        printf("%d inseerted successfully at the end of the list\n", data * 5);
    }
    puts(line);
    show(p_list, "Showing list after inserting 5 data elements at the end:");
    puts(line);

    //insert after : checking for successful and unsuccessful events
    status = insert_after(p_list, -5, 100);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected failure to insert data 100 after non-existant data -5\n");
    puts(line);

    status = insert_after(p_list, 10, 12);
    assert(status == SUCCESS);
    show(p_list, "Showing list after successfully inserting 12 after 10");
    puts(line);

    //insert before : checking for successful and unsuccessful events
    status = insert_before(p_list, 100, 12);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected failure to insert data 12 before non-existant data 100\n");
    puts(line);

    status = insert_before(p_list, 12, 11);
    assert(status == SUCCESS);
    show(p_list, "Showing list after successfully inserting 11 before 12");
    puts(line);

    //get functions - They retrieve the data wihtout removing it
    status = get_start(p_list, &start_data);
    assert(status == SUCCESS);
    printf("Start Data by get_start() = [%d]\n", start_data);
    puts(line);

    status = get_end(p_list, &end_data);
    assert(status == SUCCESS);
    printf("End Data by get_end() = [%d]\n", end_data);
    puts(line);

    //Pop Functions - They retrieve and pop the data element out of the list
    status = pop_start(p_list, &start_data);
    assert(status == SUCCESS);
    printf("Start Data by pop_start() that will get popped out of list = [%d]\n", start_data);
    puts(line);

    status = pop_end(p_list, &end_data);
    assert(status == SUCCESS);
    printf("End data by pop_end() that will get popped out of list = [%d]\n", end_data);
    puts(line);

    //Remove Functions - Successful and Unsuccessful Events
    status = remove_start(p_list);
    assert(status == SUCCESS);
    show(p_list, "Showing list after removing starting data from the list");
    puts(line);

    status = remove_end(p_list);
    assert(status == SUCCESS);
    show(p_list, "Showing list after removing last data from the list");
    puts(line);

    status = remove_data(p_list, 11);
    assert(status == SUCCESS);
    show(p_list, "Showing list after removing data = 11");
    puts(line);

    status = remove_data(p_list, 100);
    assert(status == LIST_DATA_NOT_FOUND);
    printf("Expected error when removing non-existant data 100\n");
    puts(line);

    //Miscellaneous Functions
    status = find(p_list, 91);
    assert(status == FALSE);
    printf("Expected return value = FALSE for non-existant data\n");
    puts(line);

    status = find(p_list, 12);
    assert(SUCCESS == TRUE);
    printf("Expected return value = TRUE for exiting data\n");
    puts(line);

    length = get_list_length(p_list);
    printf("The length of list is %d\n", length);
    puts(line);

    status = is_list_empty(p_list);
    assert(status == FALSE);
    printf("Expected return value FALSE because list is not empty\n");
    puts(line);

    status = destroy_list(p_list);
    assert(status == SUCCESS);
    p_list = NULL;
    printf("List destroyed Successfully!\n");
    puts(line);

    return(0);
}

//Server side of the List
//Interface function Defintions
//List Creation Function
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

//Data addition functions
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

    //Step 1 = Allocate and Initialize new node
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    new_node -> next = NULL;

    //Step 2 = Locate the last node by looping through the list
    run = p_list;
    while (run->next != NULL)
    {
        run = run -> next;
    }

    //Step 3 - Append the new node at the last position
    run -> next = new_node;

    return(SUCCESS);
}

int insert_after(struct node* p_list, int existing_data, int new_data)
{
    struct node* existing_node = NULL;
    struct node* new_node = NULL;
    struct node* run = NULL;

    //Step 1 - Search for the node containing the first occurence of the existing data
    run = p_list -> next;
    while(run != NULL)
    {
        if(run->data == existing_data)
        {
            break;
        }
        run = run -> next;
    }

    //If existing node is not found then return error saying as such
    if(NULL == run)
    {
        return(LIST_DATA_NOT_FOUND);
    }

    //Step 2 = Allocate and initialize new node
    existing_node = run;
    new_node = (struct node*)malloc(sizeof(struct node));

    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;

    //Step 3 = Insert the new node at its appropriate position
    new_node -> next = existing_node -> next;
    existing_node -> next = new_node;

    return(SUCCESS);
}

int insert_before(struct node* p_list, int existing_data, int new_data)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;
    struct node* new_node = NULL;

    //Step 1 - Search for the first occurence of the existing data
    //         maintaining back pointer 

    run_previous = p_list;
    run = p_list->next;
    while(run != NULL)
    {
        if(run -> data == existing_data)
        {
            break;
        }
        run_previous = run;
        run = run -> next;
    }

    //If existing data is not found throughout the list then return an error saying as such
    if(run == NULL)
        return (LIST_DATA_NOT_FOUND);

    //Step 2 - Allocate and Initialize the new node
    new_node = (struct node*)malloc(sizeof(struct node));
    if(NULL == new_node)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    new_node -> data = new_data;
    
    //Step 3 - Insert the new node at the appropriate position
    new_node -> next = run; //Maintaining a back pointer to next of p_list ? 
    run_previous -> next = new_node; // Node inserted at the right position

    return(SUCCESS);
}

//Get functions
int get_start(struct node* p_list, int* p_start_data)
{
    //To get the starting node without removing it
    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data; // p_list is headnode, hence node after it is first one
                                            // hence that data is returned as parameterized value

    return(SUCCESS);
}

int get_end(struct node* p_list, int* p_end_data)
{
    //To get the last node without removing it
    struct node* run = NULL;
    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    run = p_list->next;
    while (run -> next != NULL)
    {
        run = run -> next;
    }

    *p_end_data = run -> data;

    return(SUCCESS);
}

//Pop functions
int pop_start(struct node* p_list, int* p_start_data)
{
    //To get the start data and remove it after returning it
    struct node* delete_previous = NULL;
    struct node* delete_node = NULL;
    struct node* delete_next = NULL;

    if(p_list -> next == NULL)
        return (LIST_EMPTY);

    *p_start_data = p_list -> next -> data;

    delete_previous = p_list;
    delete_node = p_list -> next; // node whose data is to be deleted/removed
    delete_next = p_list -> next -> next; //node whose next is to be deleted/removed

    delete_previous -> next = delete_next;

    free(delete_node);
    delete_node = NULL;

    return(SUCCESS);
}

int pop_end(struct node* p_list, int* p_end_data)
{
    //To get the last data and remove it after returning it
    struct node* run = NULL;
    struct node* run_previous = NULL;

    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    run_previous = p_list;
    run = p_list -> next;

    while(run->next != NULL)
    {
        run_previous = run;
        run = run -> next;
    }

    *p_end_data = run->data;

    free(run);
    run = NULL;
    run_previous -> next = NULL;

    return(SUCCESS);
}

//Remove Functions
int remove_start(struct node* p_list)
{
    struct node* delete_previous = NULL;
    struct node* delete_node = NULL;
    struct node* delete_next = NULL;

    if(p_list -> next == NULL)
        return(LIST_EMPTY);

    delete_previous = p_list;
    delete_node = p_list -> next; //node to be deleted/removed
    delete_next = p_list -> next -> next; //The node next to the one we are deleting

    delete_previous -> next = delete_next;

    free(delete_node);
    delete_node = NULL;

    return(SUCCESS);
}

int remove_end(struct node* p_list)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;

    if(p_list ->next == NULL)
        return(LIST_EMPTY);

    run_previous = p_list;
    run = p_list->next;

    while(run->next != NULL)
    {
        run_previous = run;
        run = run -> next;
    }

    free(run);
    run = NULL;

    run_previous -> next = NULL;

    return(SUCCESS);
}   

int remove_data(struct node* p_list, int r_data)
{
    struct node* run = NULL;
    struct node* run_previous = NULL;

    if(p_list -> next == NULL)
        return (LIST_EMPTY);

    run_previous = p_list;
    run = p_list -> next;

    while(run != NULL)
    {
        if(run -> data == r_data)
        {
            break;
        }

        run_previous = run;
        run = run -> next;
    }

    if(run == NULL)
        return(LIST_DATA_NOT_FOUND);

    run_previous -> next = run -> next;
    free(run);
    run = NULL;

    return(SUCCESS);
}

//Miscellaneous Functions
int find(struct node* p_list, int f_data)
{
    struct node* run = NULL;
    run = p_list -> next;

    while(run != NULL)
    {
        if(run -> data == f_data)
            return(TRUE);
    
        run = run -> next;
    }

    return(FALSE);
}

int get_list_length(struct node* p_list)
{
    int len = 0;
    struct node* run = NULL;

    run = p_list -> next;

    while(run != NULL)
    {
        len = len + 1;
        run = run -> next;
    }

    return(len);
}

int is_list_empty(struct node* p_list)
{
    return(p_list -> next == NULL);
}

void show(struct node* p_list, const char* msg)
{
    struct node* run = NULL;

    if(msg != NULL)
    {
        puts(msg);
    }

    printf("[START] -> ");
    run = p_list -> next;

    while(run != NULL)
    {
        printf("[%d] -> ", run -> data);
        run = run -> next;
    }

    printf("[END]\n");
}

//List destruction functions
int destroy_list(struct node* p_list)
{
    struct node* run = NULL;
    struct node* run_next = NULL;
    
    run = p_list;

    while(run != NULL)
    {
        run_next = run -> next;
        free(run);
        run = run_next;
    }

    return(SUCCESS);
}



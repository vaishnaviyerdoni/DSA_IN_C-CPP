//HEADER FILES
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//SYMBOLIC CONSTANTS
enum status
{
    SUCCESS             = 1,
    TRUE                = 1,
    FALSE               = 0,
    LIST_DATA_NOT_FOUND = 2,
    LIST_EMPTY          = 3
};

//TYPDEFS
typedef int         data_t;
typedef int         len_t;
typedef enum status status_t;
typedef status_t    bool_t;

typedef struct node node_t;
typedef node_t      list_t;

//INFORMATION STRUCTURE DEFINITION
struct node
{
    data_t data;
    struct node* next;
};

//INTERFACE FUNCTION DECLARATION
//CREATE FUNCTION
list_t* create_list(void);

//DATA INSERTION FUNCTIONS
status_t insert_start(list_t* p_list, data_t n_data);
status_t insert_end(list_t* p_list, data_t n_data);
status_t insert_after(list_t* p_list, data_t e_Data, data_t n_data);
status_t insert_before(list_t* p_list, data_t e_Data, data_t n_data);

//GET, POP AND REMOVE FUNCTIONS
//GET
status_t get_start(list_t* p_list, data_t* start_data);
status_t get_end(list_t* p_list, data_t* end_data);

//POP
status_t pop_start(list_t* p_list, data_t* start_data);
status_t pop_end(list_t* p_list, data_t* end_data);

//REMOVE
status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

//MISCELLANEOUS FUNCTIONS
bool_t find(list_t* p_list, data_t f_data);
bool_t is_list_empty(list_t* p_list);
len_t get_list_length(list_t* p_list);
void show(list_t* p_list, const char* msg);

//DESTROY FUNCTION
status_t destroy_list(list_t** pp_list);

//HELPER/AUXILLARY FUNCTIONS DECLARATIONS
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* del_prev_node, node_t* p_del_node);
static node_t* generic_search(list_t* p_list, data_t s_data, node_t** run_prev);
static node_t* get_node(data_t n_data);
static void* xmalloc(size_t size);

//TEST FUNCTION
void test_list(void);

//CLIENT FOR THE LINKED LIST
//MAIN FUNCTION
int main(void)
{
    test_list();
    return(EXIT_SUCCESS);
}

//TEST FUNCTION
void test_list(void)
{
    list_t* p_list = NULL;

    status_t status;
    data_t data, start_data, end_data;
    len_t len;

    static const char* line = "---------------------------------------------------------------";

    p_list = create_list();
    assert(p_list != NULL);
    puts(line);
    printf("List created successfully!\n");
    puts(line);

    //Testing all the assertions on the empty linked list
    printf("Testing assertions on the empty list:\n");
    assert(is_list_empty(p_list) ==  TRUE);
    assert(get_list_length(p_list) == 0);
    assert(get_start(p_list, &start_data) == LIST_EMPTY);
    assert(get_end(p_list, &end_data) == LIST_EMPTY);
    assert(pop_start(p_list, &start_data) == LIST_EMPTY);
    assert(pop_end(p_list, &end_data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);
    printf("All assertions on the empty list are successful\n");
    puts(line);

    show(p_list, "Showing empty list immediately after creation:");
    puts(line);

    //Inserting data and testing the assertions on the filled linked list
    //Inserting data and checking assertions on non empty linked list
    for(data = 0; data < 5; ++data) {
        status = insert_start(p_list, data * 10);
        assert(status == SUCCESS);
    }
    show(p_list, "Showing the list after inserting 5 data elements at the start:");
    puts(line);
    

    for(data = 1; data <= 5; ++data) {
        status = insert_end(p_list, data * 5);
        assert(status == SUCCESS);
    }
    show(p_list, "Showing list after inserting 5 data elements at the end:");
    puts(line);

    assert(insert_after(p_list, 20, 22) == SUCCESS);
    show(p_list, "Showing list after inserting 22 after 20:");
    puts(line);

    assert(insert_after(p_list, -5, 100) == LIST_DATA_NOT_FOUND);
    puts("Expecting the failure while inserting data after non existential data : -5");
    puts(line);

    assert(insert_before(p_list, 0, -5) == SUCCESS);
    show(p_list, "Showing list after inserting -5 before 0:");
    puts(line);

    assert(insert_before(p_list, 500, 50) == LIST_DATA_NOT_FOUND);
    puts("Expecting failure while inserting data before non existential data : 500");
    puts(line);

    assert(get_start(p_list, &start_data) == SUCCESS);
    printf("The starting data in the linked list is %d\n", start_data);
    show(p_list, "Showing list after getting the starting data");
    puts(line);
    assert(get_end(p_list, &end_data) == SUCCESS);
    printf("The ending data in the linked list is %d\n", end_data);
    show(p_list, "Showing list after getting the ending data");
    puts(line);
    
    assert(pop_start(p_list, &start_data) == SUCCESS);
    printf("The starting data in the linked list is %d\n", start_data);
    show(p_list, "Showing list after popping the starting data");
    puts(line);

    assert(pop_end(p_list, &end_data) == SUCCESS);
    printf("The end data that was popped out of the linked list is %d\n", end_data);
    show(p_list, "Showing list after popping the ending data");
    puts(line);

    assert(remove_start(p_list) == SUCCESS);
    show(p_list, "Starting data 30 is removed");
    puts(line);

    assert(remove_end(p_list) == SUCCESS);
    show(p_list, "Ending data 20 has been removed");
    puts(line);

    assert(remove_data(p_list, -5) == SUCCESS);
    show(p_list, "data element -5 is removed");
    puts(line);

    assert(is_list_empty(p_list) == FALSE);
    len = get_list_length(p_list);
    printf("The length of list is %d\n", len);
    assert(find(p_list, 22) == TRUE);
    puts(line);

    assert(destroy_list(&p_list) == SUCCESS);
    printf("List destroyed successfully\n");
    puts(line);
}

//SERVER FOR THE LINKED LIST
//INTERFACE FUNCTION DEFINITION
//CREATE FUNCTION
list_t* create_list(void)
{
    list_t* p_list = NULL;
    p_list = get_node(-1);

    p_list -> next = p_list;

    return(p_list);
}

//DATA INSERTION FUNCTIONS
status_t insert_start(list_t* p_list, data_t n_data)
{
    generic_insert(p_list, get_node(n_data), p_list -> next);
    return(SUCCESS);
}

status_t insert_end(list_t* p_list, data_t n_data)
{
    node_t* run = NULL;
    node_t* run_prev = NULL;

    run_prev = p_list;
    run = p_list -> next;
    while (run != p_list)
    {
        run_prev = run;
        run = run -> next;
    }

    generic_insert(run_prev, get_node(n_data), run);
    
    return(SUCCESS);
}

status_t insert_after(list_t* p_list, data_t e_Data, data_t n_data)
{
    node_t* s_node = NULL;
    s_node = generic_search(p_list, e_Data, NULL);

    if(s_node == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    generic_insert(s_node, get_node(n_data), s_node -> next);

    return(SUCCESS);
}

status_t insert_before(list_t* p_list, data_t e_Data, data_t n_data)
{
    node_t* e_node = NULL;
    node_t* e_prev_node = NULL;

    e_node = generic_search(p_list, e_Data, &e_prev_node);
    if(e_node == NULL)
        return(LIST_DATA_NOT_FOUND);

    generic_insert(e_prev_node, get_node(n_data), e_node);

    return(SUCCESS);
}

//GET, POP AND REMOVE FUNCTIONS
//GET
status_t get_start(list_t* p_list, data_t* start_data)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    *start_data = p_list -> next -> data;

    return(SUCCESS);
}

status_t get_end(list_t* p_list, data_t* end_data)
{
    node_t* run = NULL;
    node_t* run_previous = NULL;

    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    run_previous = p_list;
    run = p_list -> next;
    while(run != p_list)
    {
        run_previous = run;
        run = run -> next;
    }

    *end_data = run -> data;

    return(SUCCESS);
}

//POP
status_t pop_start(list_t* p_list, data_t* start_data)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    *start_data = p_list -> next -> data;

    return(SUCCESS);
}

status_t pop_end(list_t* p_list, data_t* end_data)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    node_t* run = NULL;
    node_t* run_prev = NULL;

    run_prev = p_list;
    run = p_list -> next;
    while(run != NULL)
    {
        run_prev = run;
        run = run -> next;
    }

    *end_data = run -> data;

    generic_delete(run_prev, run);

    return(SUCCESS);
}

//REMOVE
status_t remove_start(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    generic_delete(p_list, p_list -> next);

    return(SUCCESS);
}

status_t remove_end(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    node_t* run_prev = NULL;
    node_t* run = NULL;

    run_prev = p_list;
    run = p_list -> next;
    while(run != NULL)
    {
        run_prev = run;
        run = run -> next;
    }

    generic_delete(run_prev, run);

    return(SUCCESS);
}

status_t remove_data(list_t* p_list, data_t r_data)
{
    node_t* s_node = NULL;
    node_t* s_prev_node = NULL;

    s_node = generic_search(p_list, r_data, &s_prev_node);
    if(s_node == NULL)
        return(LIST_DATA_NOT_FOUND);

    generic_delete(s_prev_node, s_node);

    return(SUCCESS);
}

//MISCELLANEOUS FUNCTIONS
bool_t find(list_t* p_list, data_t f_data)
{
    node_t* s_node = NULL;
    s_node = generic_search(p_list, f_data, NULL);
    if(s_node != NULL)
        return(TRUE);
    
    return(FALSE);
}

bool_t is_list_empty(list_t* p_list)
{
    return(p_list -> next == p_list);
}

len_t get_list_length(list_t* p_list)
{
    node_t* run = NULL;
    len_t len;

    len = 0;
    run = p_list -> next;
    while(run != p_list)
    {
        len += 1;
        run = run -> next;
    }

    return(len);
}

void show(list_t* p_list, const char* msg)
{
    node_t* run = NULL;

    if(msg != NULL)
        puts(msg);

    run = p_list -> next;
    printf("[START] <->");
    while(run != p_list)
    {
        printf("[%d] <-> ", run -> data);
        run = run -> next;
    }
    puts("[END]");
}

//DESTROY FUNCTION
status_t destroy_list(list_t** pp_list)
{
    node_t* run_next = NULL;
    node_t* p_list = NULL;
    node_t* run = NULL;

    p_list = *pp_list;
    run = p_list -> next;
    while(run != NULL)
    {
        run_next = run -> next;
        free(run);
        run = run_next;
    }

    pp_list = NULL;
    free(p_list);
    p_list = NULL;

    return(SUCCESS);
}

//HELPER/AUXILLARY FUNCTIONS DECLARATIONS
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_mid -> next = p_end;
    p_beg -> next = p_mid;
}

static void generic_delete(node_t* del_prev_node, node_t* p_del_node)
{
    if(p_del_node == NULL)
        return;

    if(del_prev_node != NULL)
        del_prev_node -> next = p_del_node -> next;
    
    free(p_del_node);
    p_del_node = NULL;
}

static node_t* generic_search(list_t* p_list, data_t s_data, node_t** run_prev)
{
    node_t* run = NULL;
    node_t* run_previous = NULL;
        
    run_previous = p_list;
    run = p_list -> next;
    while(run -> next != p_list)//why run -> next : next?
    {
        if(run -> data == s_data)
            //*run_prev = run_previous;
            return(run);
        
        run_previous = run;
        run = run -> next;
    }

    return(NULL);
}

static node_t* get_node(data_t n_data)
{
    node_t* n_node = NULL;
    n_node = (node_t*)xmalloc(sizeof(node_t));

    n_node -> data = n_data;
    n_node -> next = NULL;

    return(n_node);
}

static void* xmalloc(size_t size)
{
    void* ptr = NULL;

    ptr = malloc(size);
    if(NULL == ptr)
    {
        fprintf(stderr, "xmalloc():malloc():Out of Memory");
        exit(EXIT_FAILURE);
    }

    return(ptr);
}
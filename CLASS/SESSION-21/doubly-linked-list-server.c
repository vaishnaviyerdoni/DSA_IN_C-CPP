//Header Files
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"

//Client
int main(void)
{
    list_t* reversed_list = NULL;
    list_t* p_list1 = NULL;
    list_t* p_list2 = NULL;
    list_t* concat_list = NULL;
    list_t* merged_list = NULL;
    status_t status;
    len_t len;
    list_t* p_list = NULL;
    data_t data, start_data, end_data;
    const char* line = "---------------------------------------------------------------";

    p_list = create_list();
    assert(p_list != NULL);
    puts(line);
    printf("List created Successfully\n");
    puts(line);

    show(p_list, "Showing list just after creation:");

    assert(is_list_empty(p_list) == TRUE);
    assert(get_list_length(p_list) == 0);
    assert(get_start(p_list, &data) == LIST_EMPTY);
    assert(get_end(p_list, &data) == LIST_EMPTY);
    assert(pop_end(p_list, &data) == LIST_EMPTY);
    assert(pop_start(p_list, &data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);
    puts("All assertions on empty list checked");
    puts(line);

    //Adding data to the list and Checking assertions on non empty linked list
    for(data = 0; data < 5; ++data)
        assert(insert_start(p_list, data) == SUCCESS);
    show(p_list,  "After insert_start(): ");
    puts(line);
    
    for(data = 5; data < 10; ++data)
        assert(insert_end(p_list, data) == SUCCESS);
    show(p_list, "After insert_end(): ");
    puts(line);

    assert(insert_after(p_list, -10, 100) == LIST_DATA_NOT_FOUND);
    assert(insert_after(p_list, 0, 100) == SUCCESS);
    show(p_list, "Inserting 100 after existing data 0");
    puts(line);

    assert(insert_before(p_list, 300, 332) == LIST_DATA_NOT_FOUND);
    assert(insert_before(p_list, 0, 200) == SUCCESS);
    show(p_list, "Inserting 200 before existing data 0");
    puts(line);

    len = get_list_length(p_list);
    assert(len > 0);
    printf("List length = %d\n", len);
    puts(line);

    assert(get_start(p_list, &start_data) == SUCCESS);
    printf("Start data = %d\n", start_data);
    show(p_list, "After get_start()");
    puts(line);

    assert(get_end(p_list, &end_data) == SUCCESS);
    printf("End data = %d\n", end_data);
    show(p_list, "After get_end()");
    puts(line);

    assert(pop_start(p_list, &start_data) == SUCCESS);
    printf("Data Popped from the starting of list = %d\n", start_data);
    show(p_list, "After pop_start() : ");
    puts(line);

    assert(pop_end(p_list, &end_data) == SUCCESS);
    printf("Data Popped from the end of the list = %d\n", end_data);
    show(p_list, "After pop_start()");
    puts(line);

    assert(remove_start(p_list) == SUCCESS);
    show(p_list, "After remove_start(): ");
    puts(line);

    assert(remove_end(p_list) == SUCCESS);
    show(p_list, "After remove_end()");
    puts(line);

    assert(remove_data(p_list, -22) == LIST_DATA_NOT_FOUND);
    assert(remove_data(p_list, 0) == SUCCESS);
    show(p_list, "After remove_data()");
    puts(line);

    len = get_list_length(p_list);
    printf(("Length after pop and remove operations = %d\n", len);
    assert(is_list_empty(p_list) == FALSE);
    puts(line);
    
    if(find(p_list, 1000) == LIST_DATA_NOT_FOUND)
        puts("1000 is not present in the list");
    if(find(p_list, 2) == TRUE)
        puts("2 is present in list");
    puts(line);

    show(p_list, "p_list before immutble reversal");
    reversed_list = get_reversed_list(p_list);
    show(reversed_list, "After reversing immutably");
    show(p_list, "p_list, after get_reversed_list():it should be same before and after");
    assert(destroy_list(&reversed_list) == SUCCESS && reversed_list == NULL);
    puts(line);

    show(p_list, "Before mutable reversal: reverse_list()");
    assert(reverse_list(p_list) == SUCCESS);
    show(p_list, "After mutable reversal: reverse_list()");
    puts(line);

    return(0);
}

//Server
//Interface Functions
//List Creation Function
list_t* create_list(void)
{
    return get_node(0); // get node returns a list with data = 0 and prev and next = NULL
}

//Data Addition Functions
status_t insert_start(list_t* p_list, data_t new_data)
{
    generic_insert(p_list, get_node(new_data), p_list-> next);
    return(SUCCESS);
}

status_t insert_end(list_t* p_list, data_t new_data)
{
    node_t* run = NULL;

    run = p_list;
    while(run -> next != NULL)
    {
        run = run -> next;
    }

    generic_insert(run, get_node(new_data),run -> next);
    return(SUCCESS);
}

status_t insert_after(list_t* p_list, data_t e_data, data_t n_data)
{
    node_t* run = NULL;

    run = search_node(p_list, e_data);
    if(run == NULL)
        return(LIST_DATA_NOT_FOUND);

    generic_insert(run, get_node(n_data), run -> next);
    return(SUCCESS);
}

status_t insert_before(list_t* p_list, data_t e_data, data_t n_data)
{
    node_t* run = NULL;

    run = search_node(p_list, e_data);
    if(NULL == run)
        return(LIST_DATA_NOT_FOUND);

    generic_insert(run -> prev, get_node(n_data), run);
    return(SUCCESS);
}

//Get and Pop Functions
status_t get_start(list_t* p_list, data_t* p_start_data)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data;
    return(SUCCESS);    
}

status_t get_end(list_t* p_list, data_t* p_end_data)
{
    node_t* run = NULL;

    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    run = p_list;
    while(run-> next != NULL)
    {
        run = run -> next;
    }

    *p_end_data = run -> data;
    return(SUCCESS);
}

status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    *p_start_data = p_list -> next -> data;

    generic_delete(p_list -> next);
    return(SUCCESS);
}

status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    node_t* run = NULL;

    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    run = p_list;
    while(run -> next != NULL)
    {
        run = run -> next;
    }

    *p_end_data = run -> data;

    generic_delete(run);
    return(SUCCESS);
}

//Remove Functions
status_t remove_start(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY);

    generic_delete(p_list-> next);
    return(SUCCESS);
}

status_t remove_end(list_t* p_list)
{
    node_t* run = NULL;

    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    run = p_list;
    while(run -> next != NULL)
    {
        run = run -> next;
    }

    generic_delete(run);
    return(SUCCESS);
}

status_t remove_data(list_t* p_list, data_t r_data)
{
    node_t* run = NULL;

    run = search_node(p_list, r_data);
    if(run == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    generic_delete(run);
    return(SUCCESS);
}


//Miscellaneous Functions
status_t is_list_empty(list_t* p_list)
{
    return(p_list -> next == NULL && p_list -> prev == NULL);
}

status_t find(list_t* p_list, data_t s_data)
{
    node_t* p_node = NULL;

    p_node = search_node(p_list, s_data);
    return(p_node != NULL);
}

len_t get_list_length(list_t* p_list)
{
    node_t* run = NULL;
    len_t len = 0;

    run = p_list -> next;
    while(run != NULL)
    {
        run = run -> next;
        len = len + 1;
    }

    return(len);
}

void show(list_t* p_list, const char* msg)
{
    if(msg != NULL)
        puts(msg);

    node_t* run = NULL;

    printf("[START] <-> ");
    run = p_list;
    while (run -> next != NULL)
    {
        printf("[%d] <-> ", run->data);
        run = run -> next;
    }
    puts("[END]");    
}

//list destruction Function
status_t destroy_list(list_t** pp_list)
{
    node_t* run = NULL;
    node_t* run_next = NULL;
    list_t* p_list = NULL;

    p_list = *pp_list; //derefering pp_list will give us pointer pointing to head node of struct node

    run = p_list;
    while(run != NULL)
    {
        run_next = run-> next;
        free(run);
        run = run_next;
    }

    free(p_list);
    p_list = NULL;
    *pp_list = NULL;

    return(SUCCESS);
}

//List auxillary Funcitions
static void generic_insert(node_t* start_node, node_t* mid_node, node_t* end_node)
{
    //end_node may be NULL. 
    //start_node is NEVER NULL.

    mid_node -> prev = start_node;
    mid_node -> next = end_node;

    if(start_node != NULL)
        start_node -> next = mid_node;

    if(end_node != NULL)
        end_node -> prev = mid_node;
}

static void generic_delete(node_t* p_delete_node)
{
    if(p_delete_node == NULL)
        return;

    if(p_delete_node -> next != NULL)
        p_delete_node -> next -> prev = p_delete_node -> prev;

    if(p_delete_node -> prev != NULL)
        p_delete_node -> prev -> next = p_delete_node -> next;

    free(p_delete_node);
    p_delete_node = NULL;
}

static node_t* search_node(list_t* p_list, data_t s_data)
{
    node_t* run = NULL;

    run = p_list -> next;
    while(run != NULL)
    {
        if(run -> data == s_data)
            return(run);

        run = run -> next;
    }

    return(NULL);
}

static node_t* get_node(data_t new_data)
{
    node_t* new_node = NULL;

    new_node = (node_t*)xcalloc(1, sizeof(node_t));
   
    new_node -> data = new_data;
    new_node -> prev = NULL;
    new_node -> next = NULL;

    return(new_node);
}

static void* xcalloc(size_t nr_elements, size_t size_per_elements)
{
    void* ptr = NULL;

    ptr = calloc(nr_elements, size_per_elements);
    if(ptr == NULL)
    {
        fprintf(stderr, "calloc:Out of Memory\n");
        exit(EXIT_FAILURE);
    }

    return(ptr);
}

//Concat Immuable
list_t* get_concated_list(list_t* p_list1, list_t* p_list2)
{
    list_t* p_concat_list = NULL;
    node_t* run = NULL;

    p_concat_list = create_list();
    for(run = p_list1 -> next; run != NULL; run = run -> next)
        assert(insert_end(p_concat_list, run -> data) == SUCCESS);
    
    for(run = p_list2 -> next; run != NULL; run - run -> next)
        assert(insert_end(p_concat_list, run -> data) ==  SUCCESS);

    return(p_concat_list);
}

//concat mutable
status_t concat_lists(list_t* p_list1, list_t** pp_list2)
{
    list_t* p_list2 = NULL;
    node_t* run = NULL;

    p_list2 = *pp_list2;
    if(is_list_empty(p_list2) == TRUE)
    {
        free(p_list2);
        p_list2 = NULL;
        *pp_list2 = NULL;
        return(SUCCESS);
    }

    run = p_list1;
    while(run -> next != NULL)
    {
        run = run -> next;
    }

    run -> next = p_list2 -> next;
    p_list2 -> next -> prev = run;

    free(p_list2);
    p_list2 = NULL;
    *pp_list2 = NULL;

    return(SUCCESS);
}

//Merge sorted lists
list_t* merge_lists(list_t* p_list1, list_t* p_list2)
{
    node_t* run_1 = NULL;
    node_t* run_2 = NULL;
    list_t* merged_list = NULL;

    merged_list = create_list();
    run_1 = p_list1 -> next;
    run_2 = p_list2 -> next;

    while(TRUE)
    {
        if(run_1 == NULL)
        {
            while(run_2 != NULL)
            {
                assert(insert_end(merged_list, run_2 -> data) == SUCCESS);
                run_2 = run_2 -> next;
            }
            break;
        }

        if(run_2 == NULL)
        {
            while(run_1 != NULL)
            {
                assert(insert_end(merged_list, run_1 -> data) == SUCCESS);
                run_1 = run_1 -> next;
            }
            break;
        }

        if(run_1 -> data <= run_2 -> data)
        {
            assert(insert_end(merged_list, run_1 -> data) == SUCCESS);
            run_1 = run_1 -> next;
        }
        else{
            assert(insert_end(merged_list, run_2 -> data) == SUCCESS);
            run_2 = run_2 -> next;
        }
    }

    return(merged_list);
}

//reverse list
//immutable reverse list
list_t* get_reversed_list(list_t* p_list)
{
    list_t* reversed_list = NULL;
    node_t* run = NULL;

    reversed_list = create_list();
    if(is_list_empty(p_list))
        return(reversed_list);

    run = p_list -> next;
    while(run != NULL)
    {
        assert(insert_start(reversed_list, run -> data) == SUCCESS);
        run = run -> next;
    }

    return(reversed_list);
}

//mutable reverse list
status_t reverse_list(list_t* p_list)
{
    node_t* run = NULL;
    node_t* run_prev = NULL;
    node_t* original_last = NULL;
    node_t* current_last = NULL;

    original_last = p_list;
    while(original_last -> next != NULL)
    {
        original_last = original_last -> next;
    }

    run = original_last -> prev;
    current_last = original_last;
    while(run && run != p_list)
    {
        run_prev = run -> prev;
        current_last -> next = run;
        run -> prev = current_last;
        current_last = run;
        current_last -> next = NULL;
        run = run -> prev;
    }

    if(p_list != original_last)
    {
        p_list -> next = original_last;
        original_last -> prev = p_list;
    }

    return(SUCCESS);
}
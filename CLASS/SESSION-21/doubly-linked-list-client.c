#include <stdio.h>
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
    list_t* concated_list = NULL;
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
    printf("Length after pop and remove operations = %d\n", len);
    assert(is_list_empty(p_list) == FALSE);
    puts(line);
    
    if(find(p_list, -10) == FALSE)
        printf("-10 is not in the list.\n");
    
    if(find(p_list, 7) == TRUE)
        printf("7 is present in the list.\n");
    puts(line);

    show(p_list, "Showing p_list before reversal");
    reversed_list = get_reversed_list(p_list);
    show(reversed_list, "Reversed version of p_list after immutable reversal");
    show(p_list, "p_list after reversal: It should same as before since reversal is immutable");
    assert(destroy_list(&reversed_list) == SUCCESS);
    puts(line);

    show(p_list, "Showing p_list: before mutable reversal");
    assert(reverse_list(p_list) == SUCCESS);
    show(p_list, "Showing p_list after mutable reversal");
    puts(line);

    while(is_list_empty(p_list) != TRUE)
        assert(remove_end(p_list) == SUCCESS);    
    assert(is_list_empty(p_list));

    show(p_list, "p_list is now empty.");
    assert(reverse_list(p_list) == SUCCESS);
    show(p_list, "reversed list should be empty too.");
    puts(line);

    assert(insert_end(p_list, 10) == SUCCESS);
    show(p_list, "List should contain one element");
    assert(reverse_list(p_list) == SUCCESS);
    show(p_list, "reversed version of list with one element is same as original list");
    assert(destroy_list(&p_list) == SUCCESS && p_list == NULL);
    puts("p_list destroyed successfully!");
    puts(line);

    puts("Testing inter list routines");
    p_list1 = create_list();
    p_list2 = create_list();
    assert(is_list_empty(p_list1) == TRUE && is_list_empty(p_list2) == TRUE);
    merged_list = merge_lists(p_list1, p_list2);
    assert(is_list_empty(merged_list) == TRUE);
    assert(destroy_list(&merged_list) == SUCCESS && merged_list == NULL);

    for(data = 5; data <= 55; data += 10)
        assert(insert_end(p_list1, data) == SUCCESS);

    for(data = 10; data <= 50; data += 10)
        assert(insert_end(p_list2, data) == SUCCESS);

    show(p_list1, "Before concating");
    show(p_list2, "Before concating");
    concated_list = get_concated_list(p_list1, p_list2);
    show(concated_list, "after concating p_list1 and p_list2");
    puts(line);

    show(p_list1, "Before concating mutably");
    show(p_list2, "Before concating mutably");
    assert(concat_lists(p_list1, &p_list2) == SUCCESS);
    show(p_list1, "After concating mutably");
    puts(line);

    assert(destroy_list(&p_list1) == SUCCESS && p_list1 == NULL);
    assert(destroy_list(&concated_list) ==  SUCCESS && concated_list == NULL);
    puts("All assertions checked successfully!");
    puts("All lists destroyed");
    puts(line);
    
    return(EXIT_SUCCESS);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"
//Client
int main(void)
{
    list_t* p_list = NULL;
    data_t data;
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



    return(0);
}
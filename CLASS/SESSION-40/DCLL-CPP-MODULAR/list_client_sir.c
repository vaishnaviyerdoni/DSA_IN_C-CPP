#include <iostream>
#include "list.hpp"

void test_single_list_functions(); 
void test_interlist_functions(); 

int main() 
{
    test_single_list_functions(); 
    test_interlist_functions(); 
 
    return 0; 
}

void test_single_list_functions()
{
    list* L = new list; 
    int data; 
    int start_data, end_data; 

    // Try to invoke invalid operations on emptuy list 

    if(L->empty())
    {
        std::cout << "List is empty" << std::endl; 
    }
    else 
    {
        std::cerr << "Unexpected error" << std::endl; 
    }

    std::cout << "L->size():" << L->size() << std::endl; 

    try 
    {
        L->get_start(&start_data); 
    }
    catch(const list_empty& e)
    {
        std::cerr << "get_start():" << e.what() << std::endl; 
    }

    try 
    {
        L->get_end(&end_data); 
    }
    catch(const list_empty& e)
    {
        std::cerr << "get_end():" << e.what() << std::endl; 
    }

    try 
    {
        L->pop_start(&start_data); 
    }
    catch(const list_empty& e)
    {
        std::cerr << "pop_start():" << e.what() << std::endl; 
    }

    try 
    {
        L->pop_end(&end_data); 
    }
    catch(const list_empty& e)
    {
        std::cerr << "pop_end():" << e.what() << std::endl; 
    }

    try 
    {
        L->remove_start(); 
    }
    catch(const list_empty& e)
    {
        std::cerr << "remove_start():" << e.what() << std::endl; 
    }

    try 
    {
        L->remove_end(); 
    }
    catch(const list_empty& e)
    {
        std::cerr << "remove_end():" << e.what() << std::endl; 
    }


    for(data = 10; data <= 50; data += 10)
        L->insert_end(data); 

    L->show("List L after inserting data at end:"); 

    for(data = 60; data <= 100; data += 10)
        L->insert_start(data); 

    L->show("List L after inserting data at start:"); 

    try 
    {
        L->insert_after(-100, 200); 
    }
    catch(const list_data_not_found& e)
    {
        std::cerr << e.what() << std::endl; 
    }

    try 
    {
        L->insert_before(-300, 200); 
    }
    catch(const list_data_not_found& e)
    {
        std::cerr << e.what() << std::endl; 
    }

    L->insert_after(10, 1000); 
    L->insert_before(10, 2000); 
    L->show("after: insert_after(), insert_before():"); 

    L->get_start(&start_data); 
    std::cout << "Start data:" << start_data << std::endl; 
    L->show("After get_start():"); 

    L->get_end(&end_data); 
    std::cout << "End data:" << end_data << std::endl;
    L->show("After get_end():"); 

    L->pop_start(&start_data); 
    std::cout << "Start data:" << start_data << std::endl; 
    L->show("After pop_start():"); 

    L->pop_end(&end_data); 
    std::cout << "End data:" << end_data << std::endl; 
    L->show("After pop_end():"); 

    L->remove_start(); 
    L->show("After remove_start():"); 

    L->remove_end(); 
    L->show("After remove_end():"); 

    try 
    {
        L->remove_data(-10); 
    }
    catch(const list_data_not_found& e)
    {
        std::cerr << e.what() << std::endl; 
    }

    L->remove_data(10); 
    L->show("After remove_data(10):"); 

    if(!L->empty())
        std::cout << "List is not empty (expected)" << std::endl; 
    else 
        std::cerr << "List is empty (unexpected error)" << std::endl; 

    std::cout << "L->size():" << L->size() << std::endl; 

    list* reversed_list = L->get_reversed_list(); 
    L->show("L:"); 
    reversed_list->show("Reversed version of L:"); 

    L->show("Before L->reverse():"); 
    L->reverse(); 
    L->show("After L->reverse():"); 

    delete L; 
    delete reversed_list; 
}

void test_interlist_functions()
{
    list* L1 = new list; 
    list* L2 = new list; 

    for(int data = 0; data <= 50; data = data + 10)
        L1->insert_end(data); 

    for(int data = 5; data <= 75; data = data + 10)
        L2->insert_end(data); 

    list* concatendated_list = L1->concat(L2); 
    list* merged_list = L1->merge(L2); 

    L1->show("L1:"); 
    L2->show("L2:"); 
    concatendated_list->show("Concatenated list:"); 
    merged_list->show("Merged list:"); 

    L1->append(L2);
    L1->show("After L1->append(L2):");  
    L2 = 0; 

    delete L1; 
    L1 = 0;
    
    delete concatendated_list; 
    concatendated_list = 0; 

    delete merged_list; 
    merged_list = 0; 
}
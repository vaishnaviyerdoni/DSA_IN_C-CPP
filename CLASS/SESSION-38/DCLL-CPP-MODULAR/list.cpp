#include "list.hpp"
#include "list_exceptions.hpp"

#include <iostream>
#include <cstdio>
#include <cstdlib>

//------------------CLASS NODE - START------------------//
node::node(int _data) : data(_data), prev(0), next(0)
{

}


//-------------------CLASS NODE - END-------------------//

//------------------CLASS LIST - START------------------//
list::list() 
{
    head_node = new node(0);
    head_node -> prev = head_node;
    head_node -> next = head_node;
}

list::~list()
{
    node* run_next = 0;
        
    for(node* run = head_node -> next; run != head_node; run = run_next)
    {
        run_next = run -> next;
        delete run;
    }
}

void list::insert_start(int new_data)
{
    this->generic_insert(head_node, new node(new_data), head_node -> next);
}

void list::insert_end(int new_data)
{
    generic_insert(head_node -> prev, new node(new_data), head_node);
}
     
void list::insert_after(int e_data, int n_data)
{
    node* e_node = search_node(e_data);
    if(e_node == 0)
        throw list_data_not_found("list::insert_after():invalid existing data");
        
    generic_insert(e_node, new node(n_data), e_node -> next);
}
        
void list::insert_before(int e_data, int n_data)
{
    node* e_node = search_node(e_data);
    if(e_node == 0)
        throw list_data_not_found("list::insert_after():invalid existing data");
    generic_insert(e_node->prev, new node(n_data), e_node);
}

void list::get_start(int* p_start_data)
{
    if(empty())
        throw list_empty("get_start():empty list");
    *p_start_data = head_node -> next -> data;
}

void list::get_end(int* p_end_data)
{
    if(empty())
        throw list_empty("get_end():empty list");

    *p_end_data = head_node -> prev -> data;
}

void list::pop_start(int* p_start_data)
{
    if(empty())
        throw list_empty("pop_start():list empty");

    *p_start_data = head_node -> next -> data;
    generic_delete(head_node -> next);
}

void list::pop_end(int* p_end_data)
{
    if(empty())
        throw list_empty("pop_end():list empty");

    *p_end_data = head_node -> prev -> data;
    generic_delete(head_node-> prev);
}

void list::remove_start()
{
    if(empty())
        throw list_empty("remove_start():empty list");

    generic_delete(head_node->next);
}
    
void list::remove_end()
{
    if(empty())
        throw list_empty("remove_end():empty list");

    generic_delete(head_node -> prev);
}
    
void list::remove_data(int r_data)
{
    node* r_node = search_node(r_data);
    if(r_node == 0)
        throw list_data_not_found("list::remove_data():invalid r_data");

    generic_delete(r_node);
}

std::size_t list::size() const
{
    std::size_t N = 0;
    for(node* run = head_node -> next; run != head_node; run = run -> next)
        ++N;

    return N;
}
        
bool list::empty() const
{
    return head_node -> next == head_node && head_node -> prev == head_node;
}

void list::show(const char* msg = 0)
{   
    if(msg)
        std::cout << msg << std::endl;

    std::cout << "[START] <->";
    for(node* run = head_node -> next; run != head_node; run = run -> next)
        std::cout << "[" << run-> data <<"] <->";

    std::cout << "[END]" << std::endl;
}

list* list::concat(list* other)
{
    list* concatenated_list = new list;

    for(node* run = head_node -> next; run != other->head_node; run = run -> next)
        concatenated_list -> insert_end(run -> data);
        
    for(node* run = other->head_node->next; run != head_node; run = run -> next)
        concatenated_list -> insert_end(run->data);
}
        
list* list::merge(list* other)
{
    list* merged_list = new list;

    node* run1 = head_node -> next;
    node* run2 = other -> head_node -> next;

    while(true)
    {
        if(run1 == head_node)
        {
            while(run2 != other-> head_node)
            {
                merged_list -> insert_end(run2 -> data);
                run2 = run2 -> next;
            }
            break;
        }

        if(run2 == other->head_node)
        {
            while(run1 != head_node)
            {
                merged_list -> insert_end(run1->data);
                run1 = run1 -> next;
            }
            break;
        }

        if(run1-> data <= run2->data)
        {
            data = run1 -> data;
            run1 = run1 -> next;
        }
        else
        {
            data = run2-> data;
            run2 = run2 -> next;
        }
            
        merged_list -> insert_end(data);
    }

    return merged_list;
}

void list::append(list* other)
{
    if(other->empty())
    {
        head_node -> prev -> next = other -> head_node -> next;
        other -> head_node -> next -> prev  = head_node -> prev;

        head_node ->prev = other -> head_node -> prev;
        other -> head_node -> prev -> next = head_node;
    }

    delete other -> head_node;
    free(other);//  UGLY! but thats the only hack which will work 
                    //  Move semantics will cleanly solve such problems ! 
}

list* list::to_list(int* p_arr, std::size_t N)
{
    list* list_from_arr = new list;

    for(std::size_t i = 0; i < N; ++i)
        list_from_arr->insert_end(p_arr[i]);

    return list_from_arr;
}
    
void list::to_array(int** pp_arr, std::size_t* pN)
{
    std::size_t N = size();
    *pN = N;

    int* p_arr = new int[N];
    for(node* run = head_node-> next; run != head_node; run= run -> next)
        p_arr[i++] = run->data;

    *pp_arr = p_arr;
}

list* list::get_reversed_list() const
{
    list* reversed_list = new list;
    for(node* run = head_node-> next; run != head_node; run = run -> next)
        reversed_list-> insert_start(run-> data);
    
    return reversed_list;
}
     
void list::reverse()
{

}

//------------------CLASS LIST - PRIVATE FUNCTIONS------------------//
void list::generic_insert(node* p_start, node* p_mid, node* p_end)
{
    p_mid -> next = p_end;
    p_mid -> prev = p_start;

    p_start -> next = p_mid;
    p_end -> prev = p_mid;
}
void list::generic_delete(node* p_del_node)
{
    p_del_node -> prev -> next = p_del_node -> next;
    p_del_node -> next -> prev = p_del_node -> prev;
        
}
    
node* list::search_node(int search_data)
{
    for(node* run = head_node-> next; run != head_node; run = run -> next)
        if(run -> data == search_data)
            return run;

    return 0;
}
    
//------------------CLASS LIST - PRIVATE FUNCTIONS------------------//

//-------------------CLASS LIST- END-------------------//
#ifndef LIST_HPP
#define LIST_HPP

#include "list_exceptions.hpp"
#include <iostream>

class node
{
    friend class list;

    private:
        int data;
        node* next;
        node* prev;
        node(int _data);
};

class list
{
    private:
        node* head_node;

        static void generic_insert(node* p_start, node* p_mid, node* p_end);
        static void generic_delete(node* p_del_node);
        node* search_node(int search_data);
    
    public:
        list();
        ~list();

        void insert_start(int new_data);
        void insert_end(int new_data);
        void insert_after(int e_data, int n_data);
        void insert_before(int e_data, int n_data);

        void get_start(int* p_start_data);
        void get_end(int* p_end_data);
        void pop_start(int* p_start_data);
        void pop_end(int* p_end_data);

        void remove_start();
        void remove_end();
        void remove_data(int r_data);

        std::size_t size() const;
        bool empty() const;
        void show(const char* msg = 0);

        list* concat(list* other);
        list* merge(list* other);
        void append(list* other);

        static list* to_list(int* p_arr, std::size_t N);
        void to_array(int** pp_arr, std::size_t* pN);

        list* get_reversed_list() const;
        void reverse();
};

#endif
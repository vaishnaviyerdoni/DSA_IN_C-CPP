#ifndef _LIST_HPP
#define _LIST_HPP

#include <iostream>
#include <stdexcept>

const int SUCCESS = 1;
const int TRUE = 1;
const int FALSE = 0;

typedef std::size_t len_t;

class list_data_not_found : public std::runtime_error
{
    public:
        list_data_not_found(const char* msg);
};

class list_empty : public std::runtime_error
{
    public:
        list_empty(const char* msg);
};

class node
{
    friend  class list;
    private:
        int data;
        node* next;
        node(int new_data = 0);
};

class list
{
    private:
        node* head_node;

    public:
        list();
        ~list();

        void insert_start(int new_data);
        void insert_end(int new_data);
        void insert_after(int existing_data, int new_data);
        void insert_before(int existing_data, int new_data);

        void get_start(int* p_start_data);
        void get_end(int* p_end_data);

        void pop_start(int* p_start_data);
        void pop_end(int* p_end_data);

        void remove_start();
        void remove_end();
        void remove_data(int r_data);

        bool find(int f_data) const;
        bool empty() const;
        len_t length() const;

        friend std::ostream& operator<<(std::ostream& os, const list&, list_object);
};

#endif
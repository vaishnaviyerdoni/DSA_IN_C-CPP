#include "vector.hpp"
#include <iostream>
#include <cstdlib>

Vector::Vector()
{
    this->p_arr = 0;
    this->a_size = 0;
}

Vector::~Vector()
{
    if(this->p_arr != 0)
    {   
        free(this->p_arr);
        this->p_arr = 0;
    }
}

void Vector::push_back(/*this pointer,*/ int n_data)
{
    this->p_arr = (int*)realloc(this->p_arr, (this->a_size+1)*sizeof(int));
    if(0 == this->p_arr)
    {
        std::cerr << "Vector::push_back():Out of Memory" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->a_size = this->a_size + 1;
    this->p_arr[this->a_size - 1] = n_data;
}

int Vector::get_value_at_index(/*this pointer,*/int index)
{
    if(index < 0 || index >= this->a_size)
    {
        std::cerr << "Vector::get_value_at_index():out of index range" << std::endl;
        exit(EXIT_FAILURE);
    }

    return this->p_arr[index];
}

void Vector::set_value_at_index(/*this pointer,*/int index, int n_value)
{
    if(index < 0 || index >= a_size)
    {
        std::cerr << "Vector::set_value_at_index():out of index range" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->p_arr[index] = n_value;
}

int Vector::size(/*this pointer,*/)
{
    return this->a_size;
}
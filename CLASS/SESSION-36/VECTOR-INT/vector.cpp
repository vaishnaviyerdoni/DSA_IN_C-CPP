#include "vector.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>

vector::vector()
{
    this -> p_array = 0;
    this -> a_size = 0;
}

vector::~vector()
{
    if(this->p_array != 0)
    {
        free(this->p_array);
        this->p_array = 0;
    }
}

void vector::push_back(int new_data)
{
    this -> p_array = (int*)realloc(this-> p_array, (this-> a_size + 1) * sizeof(int));
    if(0 == this-> p_array)
    {
        std::cerr << "vector::push_back():Out of Memory" << std::endl;
    }

    this->a_size = this->a_size + 1;
    this-> p_array[this->a_size -1] = new_data;
}

int vector::get_value_at_index(int index)
{
    if(index < 0 || index >= a_size)
    {
        std::cerr << "vector::get_value_at_index():out of index range" << std::endl;
        exit(EXIT_FAILURE);
    }

    return this-> p_array[index];
}

void vector::set_value_at_index(int index, int new_data)
{
    if(index < 0 || index >= a_size)
    {
        std::cerr << "vector::set_value_at_index():out of index range" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->p_array[index] = new_data;
}

int vector::size()
{
    return this->a_size;
}


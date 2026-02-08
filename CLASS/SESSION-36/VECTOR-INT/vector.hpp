#ifndef _VECTOR_HPP //huard for header file
#define _VECTOR_HPP //if header file is included twice then it makes sure, file is only included once

class vector
{
    private:
        int* p_array;
        int a_size;
    
    public:
        vector(); //constructor
        ~vector(); //destructor

        void push_back(int new_data);

        int get_value_at_index(int index);
        void set_value_at_index(int index, int value);
        int size();
};

#endif
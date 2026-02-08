#ifndef _VECTOR_HPP
#define _VECTOR_HPP

class Vector
{
    private:
        int * p_arr;
        int a_size;
    
    public:
        Vector();
        ~Vector();

        void push_back(int n_data);

        int get_value_at_index(int index);
        void set_value_at_index(int index, int value);

        int size();
};

#endif
#ifndef LIST_EXCEPTIONS_HPP
#define LIST_EXCEPTIONS_HPP

class list_data_not_found : public std::runtime_error
{
    public:
        list_data_not_found(const char* msg);
};

class list_empty:public std::runtime_error
{
    public:
        list_empty(const char* msg);
};

#endif
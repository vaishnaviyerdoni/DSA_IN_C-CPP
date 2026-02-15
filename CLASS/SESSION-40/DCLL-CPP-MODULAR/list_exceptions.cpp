#include "list_exceptions.hpp"

list_data_not_found::list_data_not_found(const char* msg) : std::runtime_error(msg)
{

}

list_empty::list_empty(const char* msg) : std::runtime_error(msg)
{
    
}
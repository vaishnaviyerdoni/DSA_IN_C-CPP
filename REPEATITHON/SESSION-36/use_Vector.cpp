#include "vector.hpp"
#include <iostream>
#include <cstdlib>

void test_vector();

int main()
{
    puts("----------------Entered Main----------------");
    test_vector();
    puts("----------------Leaving Main----------------");
    return EXIT_SUCCESS;
}

void test_vector()
{
    Vector* pVec = new Vector; //calls constructor
    int i, curr_Val;
    const char* line = "------------------------------------------------";

    //Populating Array/Vector
    for(i = 1; i < 6; ++i)
        pVec -> push_back(i * 100);
    
    //Priting Array size once it is populated
    std::cout << "pVec->size(): " << pVec->size() << std::endl;
    puts(line);

    //Printing the Populated Array using get data value function
    for(i = 0; i < pVec -> size(); ++i)
    {
        curr_Val = pVec->get_value_at_index(i);
        std::cout << "Value at index " << i << " is " << curr_Val << std::endl;
    }
    puts(line);

    //Setting array to different sizes
    std::cout << "Setting value at each index to (index + 1) * 10" << std::endl;
    for(i = 0; i < pVec->size(); ++i)
        pVec->set_value_at_index(i, (i+1)*10);    

    //Showing array after setting new values
    for(i = 0; i < pVec->size(); ++i)
    {   
        curr_Val = pVec->get_value_at_index(i);
        std::cout << "Value at index : " << i << " is " << curr_Val << std::endl;
    }
    puts(line);

    //Deleting array
    std::cout << "Deleting Vector" << std::endl;
    delete pVec; //calls destructor
    pVec = 0;
}

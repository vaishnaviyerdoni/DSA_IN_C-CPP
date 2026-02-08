#include "vector.hpp"
#include  <iostream>

void test_vector();

int main()
{
    test_vector();
    std::cout << "main():Program exited successfully" << std::endl;
    return EXIT_SUCCESS;
}

void test_vector()
{
    vector* pVec = new vector; //calling object -> object used to call the functions in the class
    int i, currentVal;

    for(i = 1; i < 6; ++i)
        pVec -> push_back(i * 100);

    std::cout << "pVec -> size():" << pVec->size() << std::endl;

    for(i = 0; i < pVec -> size(); ++i)
    {
        currentVal = pVec -> get_value_at_index(i);
        std::cout << "value at index: " << i << " is " << currentVal << std::endl; 
    }

    std::cout << "Setting value at each index to (index + 1) * 10" << std::endl;
    for(i = 0; i < pVec -> size(); ++i)
        pVec -> set_value_at_index(i, (i+1)*10);
    
    std::cout << "Showing vector after setting value at index to (index + 1)*10" << std::endl;
    for(i = 0; i < pVec -> size(); ++i)
    {
        currentVal = pVec-> get_value_at_index(i);
        std::cout << "Value at : " << i << " is " << currentVal << std::endl;
    }

    std::cout << "Deleting the vector" << std::endl;
    delete pVec;
    pVec = 0;
}
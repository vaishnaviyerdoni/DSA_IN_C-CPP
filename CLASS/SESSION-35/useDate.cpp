#include "Date.hpp"

void testDate();

int main()
{
    testDate();
    return 0;
}

void testDate()
{
    Date* pDate = allocateDate(25, 2, 2029);
    pDate->year = 19; //ERROR IN CPP, CLIENT CANNOT DIRETLY USE THE CLASS MEMBERS
}
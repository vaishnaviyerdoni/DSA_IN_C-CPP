#include <iostream>
#include "date.hpp"

int main()
{
    Date mDate(31, 1, 2026);

    mDate.show();
    mDate.setMonth(4);
    mDate.show();

    int year = mDate.getYear();
    std::cout << "Year:" << year << std::endl;

    return 0;
}

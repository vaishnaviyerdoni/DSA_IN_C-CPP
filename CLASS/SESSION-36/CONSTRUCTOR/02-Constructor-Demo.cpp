#include <iostream>

class Date
{
    public:
        Date()
        {
            std::cout << "----Entered the Date::Date()----" << std::endl;
            std::cout << "Date::Date() : Address of Object to be initialized:"
                      << std::dec << this << std::endl;
            std::cout << "----Leaving the Date::Date()----" << std::endl;
        }
};

void test();

int main()
{
    std::cout << "----Entered Main Function----" << std::endl;
    Date date1;
    Date date2;

    std::cout << "&date1:" << std::dec << &date1 << std::endl;
    std::cout << "&date2:" << std::dec << &date2 << std::endl;

    test();
    std::cout << "Leaving Main Function----" << std::endl;
    return 0;
}

void test()
{
    std::cout << "----Entered Test----" << std::endl;
    Date x,y,z;

    std::cout << "x:" << std::dec << &x << std::endl
              << "y:" << std::dec << &y << std::endl
              << "z:" << std::dec << &z << std::endl;
    std::cout << "----Leaving Test----" << std::endl;
}
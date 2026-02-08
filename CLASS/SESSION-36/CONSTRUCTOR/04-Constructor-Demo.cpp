#include <iostream>
#include <cstdlib>

//  "new" opeartor of C++ programming language enables programmer to allocate 
//  dynamic object with automated call to constructor 
//  Reason : new is a langauge operator and not a library function 
//  Therefore, compiler must take the responsibility to generate assembly code for it 
//  Therefore, compiler can generate an equivalent assembly code which in part 1 
//  invokes malloc() like function to allocate memory dynamically and in part 2 
//  places an automated call to the constructor 

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int init_day, int init_month, int init_year)
        {
            this->day = init_day;
            this->month = init_month;
            this->year = init_year;

            std::cout << "Date::Date(): Object at address: " << this
                      << "is initialized with" << init_day << "/"
                                               << init_month << "/"
                                               << init_year << " values."
                                               << std::endl;
                      
        }

        void show()
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl;
        }
};

int main()
{
    Date* pDate = new Date(31, 1, 2026);

    pDate -> show(); //Date::show(pDate);

    delete pDate;
    pDate = 0;

    return EXIT_SUCCESS;
}
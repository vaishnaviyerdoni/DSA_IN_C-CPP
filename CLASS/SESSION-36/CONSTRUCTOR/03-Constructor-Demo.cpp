#include <iostream>
#include <cstdlib>

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int init_day, int init_month, int init_year)
        {
            this -> day = init_day;
            this -> month = init_month;
            this -> year = init_year;

                    std::cout << "Date::Date(): Object at address:" << this 
                              << "is initialized with " << init_day << "/" 
                                                        << init_month << "/"
                                                        << init_year " values." 
                                                        << std::endl;
        }

        void show()
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl;
        }
};

int main()
{
    Date mdate(31, 1, 2026);

    std::cout << "main():Address of mdate:" << &mdate << std::endl;
    mdate.show();

    return EXIT_SUCCESS;
}
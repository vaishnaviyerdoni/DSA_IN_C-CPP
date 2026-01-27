//  Non-modular version of Date 

#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        void initialize(int init_day, int init_month, int init_year)
        {
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 
        }

        int get_day() 
        {
            return this->day; 
        }

        int get_month() 
        {
            return this->month; 
        }

        int get_year() 
        {
            return this->year; 
        }

        void set_day(int new_day)
        {
            this->day = new_day; 
        }

        void set_month(int new_month)
        {
            this->month = new_month; 
        }

        void set_year(int new_year) 
        {
            this->year = new_year; 
        }

        void show() 
        {
            std::cout << this->day << "/" << this->month << "/" << this->year << std::endl; 
        }
}; 

void test_date(); 

int main()
{
    test_date(); 
    return 0; 
}

void test_date() 
{
    Date myDate; 

    myDate.initialize(25, 1, 2026); 

    int day = myDate.get_day(); 
    int month = myDate.get_month(); 
    int year = myDate.get_year(); 

    std::cout << "Date Individual Components are:" << day << "/" << month << "/" << year << std::endl; 

    myDate.set_day(3); 
    myDate.set_month(5); 
    myDate.set_year(1980); 

    myDate.show(); 
}
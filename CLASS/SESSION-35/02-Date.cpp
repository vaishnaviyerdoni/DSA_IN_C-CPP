//NON MODULAR VERSION OF DATE
#include<iostream>

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

        void set_day(int n_day)
        {
            this->day = n_day;
        }

        void set_month(int n_month)
        {
            this->month = n_month;
        }

        void set_year(int n_year)
        {
            this->year = n_year;
        }

        void showDate()
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
    
    myDate.initialize(27, 1, 2026);

    int day, month, year;

    day = myDate.get_day();
    month = myDate.get_month();
    year = myDate.get_year();

    std::cout << "Date individual components are:" << day << "/" << month << "/" << year << std::endl;

    myDate.set_day(19);
    myDate.set_month(5);
    myDate.set_year(2000);

    myDate.showDate();
}

/*
    myDate.initialize(25, 1, 2026);
    => Date::initialize(&myDate, 25, 1, 2026);

    generic =>
        ObjectName.FunctionName(ActualParameterList); == ClassName::FunctionName(&ObjectName, ActualParameterList)
        type(ObjectName) == ClassName(could be ParentClass in case of inheritance)

*/
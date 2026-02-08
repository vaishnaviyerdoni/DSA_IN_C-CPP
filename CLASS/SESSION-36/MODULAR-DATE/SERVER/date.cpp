#include <iostream>
#include <date.hpp>

Date::Date(int init_day, int init_month, int init_year)
{
    this->day = init_day;
    this->month = init_month;
    this->year = init_year;
}

int Date::getDay()
{
    return this->day;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getYear()
{
    return this->year;
}

void Date::setDay(int n_day)
{
    this->day = n_day;
}

void Date::setMonth(int n_month)
{
    this->month = n_month;
}

void Date::setYear(int n_year)
{
    this->year = n_year;
}

void show()
{
    std::cout << day << "/" << month << "/" << year << std::endl;
}
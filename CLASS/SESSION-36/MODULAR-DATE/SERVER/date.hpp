#ifndef _DATE_HPP
#define _DATE_HPP

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int init_day, int init_month, int init_year);
        int getDay();
        int getMonth();
        int getYear();

        void setDay(int n_day);
        void setMonth(int n_month);
        void setYear(int n_year);

        void show();
};

#endif
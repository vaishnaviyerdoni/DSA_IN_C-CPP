// EXPERIMENTAL CODE -> NOT TO BE REPLICATED IN RAL CODE
// NOT TO BE COMPILED
// NOT TO BE RUN
#ifndef DATE_HPP
#define DATE_HPP

class Date
{
    private:
        int day;
        int month;
        int year;
    
    public:
        getDay(Date* pDate);
        getMonth(Date* pDate);
        getYear(Date* pDate);

        setDay(Date* pDate, int day);
        setMonth(Date* pDate, int month);
        setYear(Date* pDate, int year);

        void showDate(Date* pDate);
};
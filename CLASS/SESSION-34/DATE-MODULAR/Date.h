#ifndef DATE_H
#define DATE_H

#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Date* allocateDate(int init_day, int init_month, int init_year);

int getDay(struct Date* pdate);
int getMonth(struct Date* pdate);
int getYear(struct Date* pdate);

void setDay(struct Date* pdate, int n_day);
void setMonth(struct Date* pdate, int n_month);
void setYear(struct Date* pdate, int n_year);

void showDate(struct Date* pdate);

void releaseDate(struct Date** ppDate);

void testDate(void);

#endif
#include "Date.h"

struct Date* allocateDate(int init_day, int init_month, int init_year)
{
    struct Date* pDate = (struct Date*)malloc(sizeof(struct Date));
    if(NULL == pDate)
    {
        puts("Out of Memory");
        exit(EXIT_FAILURE);
    }

    pDate -> day = init_day;
    pDate -> month = init_month;
    pDate -> year = init_year;

    return(pDate);
}

int getDay(struct Date* pdate)
{
    return(pdate->day);
}

int getMonth(struct Date* pdate)
{
    return(pdate->month);
}

int getYear(struct Date* pdate)
{
    return(pdate->year);
}

void setDay(struct Date* pdate, int n_day)
{
    pdate -> day = n_day;
}

void setMonth(struct Date* pdate, int n_month)
{
    pdate -> month = n_month;
}

void setYear(struct Date* pdate, int n_year)
{
    pdate -> year = n_year;
}

void showDate(struct Date* pdate)
{
    printf("%d/%d/%d\n", pdate -> day, pdate -> month, pdate -> year);
}

void releaseDate(struct Date** ppDate)
{
    free(*ppDate);
    *ppDate = NULL;
}

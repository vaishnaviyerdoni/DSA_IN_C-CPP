#include "Date.h"

int main(void)
{
    testDate();
    return(0);
}

void testDate(void)
{
    struct Date* myDate = allocateDate(27, 1, 2026);

    int day, month, year;

    day = getDay(myDate);
    month = getMonth(myDate);
    year = getYear(myDate);

    printf("%d/%d/%d\n", day, month, year);

    setDay(myDate, 19);
    setMonth(myDate, 5);
    setYear(myDate, 2000);

    showDate(myDate);

    releaseDate(&myDate);

    puts("Date successfully destroyed!");
}
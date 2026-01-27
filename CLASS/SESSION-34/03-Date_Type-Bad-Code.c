#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Date myDate;

int main(void)
{
    myDate.day = 26;
    myDate.month = 1;
    myDate.year = 2026;

    printf("%d-%d-%d\n", myDate.day, myDate.month, myDate.year);

    return(0);
}

// 1) Mixing of client and server side code 
// Data type implementation  -> server side code
// Creation of data type instances and using them -> Client side code
// In above example lines 4 to 9 -> Server side
// Line 11, Line 15- 17,Line 19 -> Client side

// 2) Client is making use of server side knowledge.
// Client is using data type WITH THE KNOWLEDGE OF ITS INTERNAL LAYOUT 
// What is internal Layout?
//      Knowledge of names of members in structure
//      Knowledge of Types of members in structure
// In this specific case knowledge that data instance has members named
// data, month and year and knowlegde that they have int is 
// SERVER SIDE KNOWLEDGE, AND IT IS REQUIRED FOR CLIENT TO USE INSTANCES OF struct Date.
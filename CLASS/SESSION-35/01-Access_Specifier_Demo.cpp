#include <iostream>

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        int x;
        int y;
        int z;
};

int main()
{
    test();
    return 0;
}

void test()
{
    Date mydate;

    mydate.day = 1;
    mydate.month = 1;
    mydate.year = 1970;

    mydate.x = 1000;
    mydate.y = 2000;
    mydate.z = 3000;
}
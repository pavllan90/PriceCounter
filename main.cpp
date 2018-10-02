#include <iostream>
#include <cassert>
#include "purchase.h"

using namespace std;

float count(DateTime first, DateTime last, Purchase *mass, int size)
{
    float result = 0;
    int dateFirst = 10000*first.date.year+100*first.date.month+first.date.day;
    int timeFirst = 10000*first.time.hours+100*first.time.minutes+first.time.seconds;
    int dateLast = 10000*last.date.year+100*last.date.month+last.date.day;
    int timeLast = 10000*last.time.hours+100*last.time.minutes+last.time.seconds;
    for(int i = 0; i < size; i++)
    {
        if((mass[i].dateToInt() > dateFirst || (mass[i].dateToInt() == dateFirst && mass[i].timeToInt()>=timeFirst)) &&
           (mass[i].dateToInt() < dateLast || (mass[i].dateToInt() == dateLast && mass[i].timeToInt()<=timeLast)))
           result += mass[i].getSum(), mass[i].show();
    }
    return result;
}

int main()
{
    Purchase a;
    cout<<"A:"<<endl;
    a.show();
    cout<<"Checking Deafault Constructor..."<<endl;
    assert(a.getDateTime().date.day == 20 && a.getDateTime().date.month == 2 && a.getDateTime().date.year == 1998 &&
           a.getDateTime().time.hours == 12 && a.getDateTime().time.minutes == 24 && a.getDateTime().time.seconds == 53);
    cout<<"OK"<<endl;
    Purchase b(DateTime (15, 34, 2000, 11, 63, 20), 25.89);
    cout<<"B:"<<endl;
    b.show();
    cout<<"Checking Initialization Constructor..."<<endl;
    assert(b.getDateTime().date.month != 34 && b.getDateTime().time.minutes != 63 &&
           b.getDateTime().date.day == 15 && b.getDateTime().date.month == 2 && b.getDateTime().date.year == 2000 &&
           b.getDateTime().time.hours == 11 && b.getDateTime().time.minutes == 24 && b.getDateTime().time.seconds == 20);
    cout<<"OK"<<endl;
    cout<<"Making Copy... "<<endl;
    Purchase copy = b;
    cout<<"Copy: "<<endl;
    copy.show();
    cout<<"Checking Copy Constructor..."<<endl;
    assert(b.getDateTime().date.day == copy.getDateTime().date.day && b.getDateTime().date.month == copy.getDateTime().date.month
           && b.getDateTime().date.year == copy.getDateTime().date.year && b.getDateTime().time.hours == copy.getDateTime().time.hours &&
           b.getDateTime().time.minutes == copy.getDateTime().time.minutes && b.getDateTime().time.seconds == copy.getDateTime().time.seconds);
    cout<<"OK"<<endl;
    cout<<"Checking setters... "<<endl;
    a.setDateTime(321, 7, 2018, 45, 11, 89);
    assert(a.getDateTime().date.day == 20 && a.getDateTime().date.month == 7 && a.getDateTime().date.year == 2018 &&
           a.getDateTime().time.hours == 12 && a.getDateTime().time.minutes == 11 && a.getDateTime().time.seconds == 53);
    cout<<"OK"<<endl;
    Purchase mass[10];
    for(int i = 0; i< 10; i++)
    {
        mass[i].setDateTime(rand()%30, rand()%12, rand()%30+1990, rand()%60, rand()%60, rand()%60);
        mass[i].setSum(rand()%10000);
        mass[i].show();
    }
    DateTime fdt(10, 1, 1999, 2, 3, 4);
    DateTime ldt(10, 1 , 2009, 1, 2, 3);
    cout<<"Sum from fdt to ldt is "<<count(fdt, ldt, mass, 10);
    return 0;

}

#include "purchase.h"

Purchase::Purchase() : dateTime(DateTime()), sum(25.95) { }

Purchase::Purchase(DateTime _dateTime, float _sum) : dateTime(_dateTime), sum(_sum>0 ? _sum : Purchase().sum) { }

Purchase::Purchase(int _day, int _month, int _year, int _hours, int _minutes, int _seconds, float _sum) :
                  dateTime(DateTime(_day, _month, _year, _hours, _minutes, _seconds)),
                  sum(_sum > 0 ? _sum : Purchase().sum) { }

Purchase::Purchase(const Purchase &cp) : dateTime(cp.dateTime), sum(cp.sum) { }

Purchase::~Purchase() { }

float Purchase::getSum()
{
    return sum;
}

DateTime Purchase::getDateTime()
{
    return dateTime;
}

void Purchase::setSum(float _sum)
{
    sum = _sum>0 ? _sum : sum;
}

void Purchase::setDateTime(int _day, int _month, int _year, int _hours, int _minutes, int _seconds)
{
    dateTime = DateTime(_day, _month, _year, _hours, _minutes, _seconds);
}

void Purchase::showDateTime()
{
    cout<<"Date: "<<dateTime.date.day<<"/"<<dateTime.date.month<<"/"<<dateTime.date.year<<endl;
    cout<<"Time: "<<dateTime.time.hours<<":"<<dateTime.time.minutes<<":"<<dateTime.time.seconds<<endl;
}

int Purchase::dateToInt()
{
    return 10000*dateTime.date.year+100*dateTime.date.month+dateTime.date.day;
}

int Purchase::timeToInt()
{
    return 10000*dateTime.time.hours+100*dateTime.time.minutes+dateTime.time.seconds;
}

void Purchase::showSum()
{
    cout<<"Sum: "<<sum<<endl;
}

void Purchase::show()
{
    showDateTime();
    showSum();
}

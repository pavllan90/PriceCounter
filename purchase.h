#ifndef PURCHASE_H
#define PURCHASE_H
#include <iostream>

using namespace std;

struct Date
{
    Date() : day(20), month(2), year(1998) { }
    Date(int _day, int _month, int _year) :
    day(_day>0 && _day<32 ? _day : Date().day),
    month(_month>0 && _month<13 ? _month : Date().month),
    year(_year>1900 && _year<3000 ? _year : Date().year) { }
    int day;
    int month;
    int year;
};

struct Time
{
    Time() : hours(12), minutes(24), seconds(53) { }
    Time(int _hours, int _minutes, int _seconds) :
    hours(_hours<24 && _hours>=0 ? _hours : Time().hours),
    minutes(_minutes<60 && _minutes>=0 ? _minutes : Time().minutes),
    seconds(_seconds<60 && _seconds>=0 ? _seconds : Time().seconds) { }
    int hours;
    int minutes;
    int seconds;
};

struct DateTime
{
    DateTime() : date(Date()), time(Time()) { }
    DateTime(Date _date, Time _time) : date(_date), time(_time) { }
    DateTime(int _day, int _month, int _year,
             int _hours, int _minutes, int _seconds) :
             date(Date(_day, _month, _year)),
             time(Time(_hours, _minutes, _seconds)) { }
    Date date;
    Time time;
};

class Purchase
{
public:
    Purchase();
    Purchase(DateTime _dateTime, float _sum);
    Purchase(int _day, int _month, int _year, int _hours, int _minutes, int _seconds, float _sum);
    Purchase(const Purchase &cp);
    ~Purchase();
    void setSum(float _sum);
    float getSum();
    void setDateTime(int _day, int _month, int _year,
                     int _hours, int _minutes, int _seconds);
    DateTime getDateTime();
    void showDateTime();
    void showSum();
    void show();
    int dateToInt();
    int timeToInt();
private:
    float sum;
    DateTime dateTime;
};

#endif // PURCHASE_H

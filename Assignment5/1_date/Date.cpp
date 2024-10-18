#include <iostream>
#include <string>
#include "Date.h"
int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool err(int y,int m,int d);
bool leap(int year);
bool valid(int y,int m,int d);
/*
Default Constructor
*/
Date::Date()
{
    year=1900;
    month=1;
    day=1;
}

/*
Constructor using date
*/
Date::Date(int y,int m,int d)
{
    if(!valid(y,m,d)){
        std::cout<<"Error"<<endl;
        year=1900;
        month=1;
        day=1;
    }
    else{year=y;month=m;day=d;}
}
//check validity of the date
bool valid(int y,int m,int d)
{
    if(y>2900||y<1900||m<1||m>12||d<1)return 0;
    if(leap(y)&&m==2){
            if(d>29)return 0;
    }
    else{
        if(d>mon[m-1])return 0;
    }
    return 1;
}
//determines whether its a leap year
bool leap(int y)
{
    if(y%400==0)return 1;
    if(y%100==0)return 0;
    if(y%4==0)return 1;
    return 0;
}
/*
Getter: year
*/
int Date::getYear() const
{
    return year;
}
/*
Getter: month
*/
int Date::getMonth() const
{
    return month;
}
/*
Getter: day
*/
int Date::getDay() const
{
    return day;
}
//return the shortage of the month
string Mon_from_Int(int m){
    switch (m){
    case 1:
        return "Jan";
        break;
    case 2:
        return "Feb";
        break;
    case 3:
        return "Mar";
        break;
    case 4:
        return "Apr";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "Jun";
        break;
    case 7:
        return "Jul";
        break;
    case 8:
        return "Aug";
        break;
    case 9:
        return "Sep";
        break;
    case 10:
        return "Oct";
        break;
    case 11:
        return "Nov";
        break;
    case 12:
        return "Dec";
        break;
    default:
        return "";
    }
}
//return a string:dd-mmm-yyyy
string Date::toString() const{
    return std::to_string(day)+"-"+Mon_from_Int(month)+"-"+std::to_string(year);
}
//add n days
void Date::add(int n){
    day+=n;
    while(!valid(year,month,day)){
        if(leap(year)&&month==2){
            if(day>29){
                month+=1;
                day-=29;
            }
        }
        else{
            if(day>mon[month-1]){
                month+=1;
                day-=mon[month-1];
            }
        }
        if(month>12){
            month-=12;
            year+=1;
        }
        if(year>2900){
            std::cout<<"Error"<<endl;
            year=1900;
            month=1;
            day=1;
            break;
        }
    }
}
//sub n days
void Date::sub(int n){
    day-=n;
    while(!valid(year,month,day)){
        if(day<0){
            if(leap(year)&&month==3){
                day+=29;
                month=2;
            }
            else{
                if(month==1){
                    day+=31;
                    month=12;
                    year-=1;
                }
                else{
                    day+=mon[month-2];
                    month-=1;
                }
            }

        }
        if(year<1900){
            std::cout<<"Error"<<endl;
            year=1900;
            month=1;
            day=1;
            break;
        }
    }
}

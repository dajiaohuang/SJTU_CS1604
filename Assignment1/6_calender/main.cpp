#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string addzero(int);
int leap(int year);
void dateout(int year,int month, int date);
//find out the b th weekday or weekend day represented by c in the a th month
int main()
{
    int firstday1850[13];
    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    firstday1850[0]=0;
    firstday1850[1]=2;
    int month;
    for(month=2;month<13;month++)
    {
        firstday1850[month]=(firstday1850[month-1]+days[month-1])%7;
        if (firstday1850[month]==0)
            firstday1850[month]+=7;
    }
    int a,b,c,y1,y2,y,dayfirst,date;
    cin>>a>>b>>c>>y1>>y2;
    dayfirst=firstday1850[a];
    if(a<3)
    {
        for(y=1850;y<y1;y++)
        {
            dayfirst+=leap(y);
            if (dayfirst>7)
                dayfirst-=7;
        }
        for(y=y1;y<=y2;y++)
        {
            if (c<dayfirst)
            {
                date=7*b+c-dayfirst+1;
                dateout(y,a,date);
            }

            else
            {
                date=7*b-6+c-dayfirst;
                dateout(y,a,date);
            }
            dayfirst+=leap(y);
            if (dayfirst>7)
                dayfirst-=7;
        }
    }
    else
    {
        for(y=1850;y<y1;y++)
        {
            dayfirst+=leap(y+1);
            if (dayfirst>7)
                dayfirst-=7;
        }
        for(y=y1;y<=y2;y++)
        {
            if (c<dayfirst)
            {
                date=7*b+c-dayfirst+1;
                dateout(y,a,date);
            }
            else
            {
                date=7*b-6+c-dayfirst;
                dateout(y,a,date);
            }
            dayfirst+=leap(y+1);
            if (dayfirst>7)
                dayfirst-=7;
        }

    }
    return 0;
}
//decide whether a year is a leap year
//input:the year
//output:2 if leap,1 if not
int leap(int year)
{
    if(year%400==0)
        return 2;
    else
    {
        if(year%100==0)
            return 1;
        else
        {
            if(year%4==0)
                return 2;
            else
                return 1;
        }
    }
}
//determine and add 0 to numbers of one digit
//input:number
//output:string,with zero added if its one-digit
string addzero(int num)
{
    string adz;
    stringstream ss;
    ss<<num;
    ss>>adz;
    if (num>9)
        return adz;
    else
        return "0"+adz;
}
//check "overflow",and output
void dateout(int year,int month, int date)
{
    int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2)
    {
        if (leap(year)==2)
        {
            if(date>29)
            {
                cout<<"none"<<endl;
                return;
            }
            else
            {
                cout<<year<<"/"<<addzero(month)<<"/"<<addzero(date)<<endl;
                return;
            }
        }
        else
        {
            if(date>28)
            {
                cout<<"none"<<endl;
                return;
            }
            else
            {
                cout<<year<<"/"<<addzero(month)<<"/"<<addzero(date)<<endl;
                return;
            }
        }
    }
    else
    {
        if(date>days[month])
            {
                cout<<"none"<<endl;
                return;
            }
            else
            {
                cout<<year<<"/"<<addzero(month)<<"/"<<addzero(date)<<endl;
                return;
            }
    }

}

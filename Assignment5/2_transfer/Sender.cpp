//
// Created by delirio on 2022/4/30.
//
#include <string>
#include "Sender.h"

//At first, implement your constructor here
//default
Sender::Sender()
{
    originData="";
    MTU=128;
}
//only data
Sender::Sender(string d)
{
    originData=d;
    MTU=128;
}
//only mtu
Sender::Sender(int m)
{
    originData="";
    MTU=m;
}
//both
Sender::Sender(string d,int m)
{
    originData=d;
    MTU=m;
}
//getOriginData
string Sender::getOriginData() {
    //your implementation
    return originData;
}

//bitStuffing
string Sender::bitStuffing(string data) {
    //your implementation
    for(int i=0;i<data.size())-4;i++){
        if (data.substr(i,5)=="11111")
            return data.substr(0,i+5)+"0"+bitStuffing(data.substr(i+5));
    }
    return data;
}

//framing
string Sender::framing() {
    //your implementation
    string data=bitStuffing(originData);
    string res="01111110";
    while(data.size()>MTU){
        res+=data.substr(0,MTU);
        data=data.substr(MTU);
        res+="01111110";
    }
    res+=data;
    res+="01111110";
}

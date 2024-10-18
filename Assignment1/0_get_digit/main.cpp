#include <iostream>

using namespace std;
//Given a positive integer num , find out the digits in the hundreds place, the tens place and the ones place in num , respectively.
int main()
{
    int num;
    cin>>num;
    cout<<(num/100)%10<<" "<<(num/10)%10<<" "<<num%10<<endl;
    return 0;
}

#include <iostream>
using namespace std;
//read and check if an integer is a palindrome number
int main()
{
    int num;
    cin>>num;
    int s = num,x=0;
    while (s>0)
    {
        x*=10;
        x+=(s%10);
        s/=10;
    }
    if (x==num)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

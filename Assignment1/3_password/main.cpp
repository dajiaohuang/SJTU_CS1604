#include <iostream>
#include <string>
using namespace std;
//Given a four-digit number, encrypt and output it. The encryption method is to, for every digit in the number, first add 5 to it and then convert it into an capitalized English letter.
int main()
{
    int num,i=0;
    cin>>num;
    char pw[4];
    while(i<4)
    {
        pw[3-i]=char(69+num%10);
        num/=10;
        i+=1;
    }
    cout<<pw<<endl;
    return 0;
}

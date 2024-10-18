#include <iostream>

using namespace std;
//Calculate how many kilometers TA will accumulate after n days.
int main()
{
    int x;
    long n,kilo=0;
    cin>>x>>n;
    int day=x;
    while(n>0)
    {
        n-=1;
        if(x<6)
            kilo+=250;
        else
        {
            if(x>7)
            {
                x-=7;
                kilo+=250;
            }

        }
        x+=1;
    }
    cout<<kilo<<endl;
    return 0;
}

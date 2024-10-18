#include <iostream>

using namespace std;
//calculate a^n(mod 2019)
int main()
{
    int a,n,res=1,m;
    cin>>a>>n;
    m=a;
    while(n>0)
    {
        if(n%2)
            res*=m;
        res=res%2019;
        n/=2;
        m=(m*m)%2019;
    }
    cout<<res<<endl;
    return 0;
}

#include <iostream>

using namespace std;
//Enter two integers of type int (within the range of int ), output their sum. An error message should be generated in case of overflow.
int main()
{
    int int1,int2;
    cin>>int1>>int2;
    int sum = int1 + int2;
    //bool * i1=&int1,i2=&int2,s=&sum;
    bool i1=(int1>0),i2=(int2>0),s=(sum>0);
    if (i1!=i2)
        cout<<sum<<endl;
    else
    {
        if (i1==s)
            cout<<sum<<endl;
        else
            cout<<"ERROR"<<endl;
    }
    return 0;
}

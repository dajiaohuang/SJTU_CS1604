#include <iostream>

using namespace std;
int countlen(int n,int i,int j);
int outer(int n,int k);
//Calculate Taki's and Sanya's respective paths along the grid are spirals that rotate clockwise.
int main()
{
    int n,i,j;
    cin>>n>>i>>j;
    cout<<countlen(n,i,j)<<" "<<countlen(n,n-i+1,n-j+1)<<endl;
    return 0;
}
//count the length of the path from (n,n)
int countlen(int n,int i,int j)
{
    int ks[4]={i-1,n-i,j-1,n-j};
    int k=i-1;
    int t;
    for(t=1;t<4;t++)
    {
        if (k>ks[t])
            k=ks[t];
    }
    int ring;
    if(j==1+k)
        ring =n-i+1-k-1;
    else
    {
        if(i==1+k)
            ring = j+n-3*k-2;
        else
        {
            if(i==n-k)
                ring=2*n-5*k+i-3;
            else
                ring=4*n-7*k-j-4;
        }
    }
    return (outer(n,k)+ring);
}
//Calculate the length of the complete rings they go through
//input:n:size of the whole map;k:the number of complete rings
//output:the length of the complete rings
int outer(int n,int k)
{
    if(k==0)
        return 0;
    else
    {
        int ou=0;
        int t;
        for(t=0;t<k;t++)
        {
            ou+=4*(n-2*t-1);
        }
        return ou;
    }
}


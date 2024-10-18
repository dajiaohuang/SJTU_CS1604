#include <iostream>
#include <string>
using namespace std;
/*Main Program
 *Define the correlation between two strings of
 *the same length as the number of characters they
 *share at the same places.
 *Define the maximum correlation of a string in a
 *piece of text as the maximal correlation between
 *and all substrings of whose length equals that of .
 *Given a line of text and a string , return all best
 *matches of in , where abest match is defined as a
 *substring of of the same length as whose correlation
 *with equals the maximum correlation of in .
 */
int main()
{
    string l,s,space;
    getline(cin,l);
    getline(cin,s);
    int len=l.length()-s.length()+1;
    int same[len][s.length()];
    int num[len];
    int i,j,m=0,res=0;
    for(i=0;i<len;i++){
        num[i]=0;
        for(j=0;j<s.length();j++){
            if (l[i+j]==s[j]){
                same[i][j]=1;
                num[i]+=1;
            }
            else
                same[i][j]=0;
        }
    }
    for(i=0;i<len;i++){
        if(num[i]>m)
            m=num[i];
    }
    for(i=0;i<len;i++){
        space="";
        if(num[i]==m){
            for(j=0;j<i;j++){
                space+=" ";
            }
            res+=1;
            cout<<l<<endl
                <<space;
            for(j=0;j<s.length();j++){
                if (same[i][j])
                    cout<<"+";
                else
                    cout<<"-";
            }
            cout<<" "<<num[i]<<"/"<<s.length()<<endl
                <<space<<s<<endl
                <<space<<"^ col "<<i+1<<endl
                <<"---"<<endl;
        }
    }
    cout<<"Found "<<res<<" best match(es)";
    return 0;
}

#include <iostream>

using namespace std;
/*Main Program
 *determines whether a valid word is a syllabic palindrome.
 */
int main()
{
    string line,v="aeiou";
    getline(cin,line);
    bool cv[line.length()];
    int i,pos;
    if (v.find(line[line.length()-1])==line.npos){
        cout<<"NO"<<endl;
        return 0;
    }
    for(i=0;i<line.length();i++){
        if(line[i]>='a'&&line[i]<='z'){
            if(i<line.length()-1){
                if (v.find(line[i])==line.npos&&v.find(line[i+1])==line.npos){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
        else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    string rev,line_=line;
    i=line.length()-1;
    while(line_!=""){
        if(i==0){
            rev+=line_;
            line_="";
        }
        else{
            if(v.find(line[i-1])==line.npos){
                rev+=line_.substr(i-1,2);
                line_.erase(i-1,2);
                i-=2;
            }
            else{
                rev+=line_.substr(i,1);
                line_.erase(i,1);
                i-=1;
            }
        }
    }
    if(rev==line)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

#include <iostream>
#include <string>

using namespace std;
/*line-wraps a given piece of text to fit a specified
 *display width (in characters) by inserting a new-line
 *character ('\n' in C++) between words
 */
int main()
{
    string word,line,res;
    int width;
    cin>>width;
    while(cin>>word){
        if(line.length()+word.length()>width){
            if(line!=""){
                line.erase(line.length()-1,1);
                res+=line;
                res+='\n';
            }
            line=word;
            line+=" ";
            if(line.length()-1>width){
                line.erase(line.length()-1,1);
                res+=line;
                res+='\n';
                line="";
            }
        }
        else{
            line+=word;
            line+=" ";
        }
    }
    if(line!=""){
        res+=line;
        res+='\n';
    }
    res.erase(res.length()-1,1);
    cout<<res<<endl;
    return 0;
}

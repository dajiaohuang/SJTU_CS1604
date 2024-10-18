#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/* Function prototypes */
string pascal(string line);
string camel(string line);
string snake(string line);
/*Main Program*/
int main()
{
    string line,word;
    getline(cin,line);
    int i;
    for(i=0;i<line.length();i++){
        if((line[i]>='A'&&line[i]<='Z')
           ||(line[i]>='a'&&line[i]<='z')
           ||(line[i]>='0'&&line[i]<='9'));
        else{
            line[i]=' ';
        }
    }
    cout<<"PascalCase: "<<pascal(line)<<endl
        <<"camelCase:  "<<camel(line)<<endl
        <<"snake_case: "<<snake(line)<<endl;
    return 0;
}

/*produces the pascal case of the line*/
string pascal(string line){
    stringstream linestream;
    linestream<<line;
    string word,res;
    while(linestream>>word){
        if(word[0]>='a'&&word[0]<='z'){
            word[0]-=32;
        }
        res+=word;
    }
    return res;
}

/*produces the camel case of the line*/
string camel(string line){
    stringstream linestream;
    linestream<<line;
    string word,res;
    linestream>>word;
    int i;
    for(i=0;i<word.length();i++){
        if(word[i]>='A'&&word[i]<='Z'){
            word[i]+=32;
        }
    }
    res+=word;
    while(linestream>>word){
        if(word[0]>='a'&&word[0]<='z'){
            word[0]-=32;
        }
        for(i=1;i<word.length();i++){
            if(word[i]>='A'&&word[i]<='Z'){
                word[i]+=32;
            }
        }
        res+=word;
    }
    return res;
}
/*produces the snake case of the line*/
string snake(string line){
    stringstream linestream;
    linestream<<line;
    string word,res;
    int i;
    while(linestream>>word){
        for(i=0;i<word.length();i++){
            if(word[i]>='A'&&word[i]<='Z'){
                word[i]+=32;
            }
        }
        res+=word;
        res+="_";
    }
    res.erase(res.length()-1,1);
    return res;
}

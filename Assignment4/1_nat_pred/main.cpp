#include <iostream>
#include <string>
#include <Vector.h>
using namespace std;
Vector<int> pred(Vector<int> n);
Vector<int> sub(Vector<int> n, int m);
//main program
int main(){
    Vector<int> n;
    string str_n;
    int m;
    cin>>str_n>>m;
    for(int i=0;i<str_n.length();i++){
        n+=(int(str_n[i])-48);
    }
    Vector<int> res=sub(n,m);
    while(res[0]==0 && res.size()>1){res.remove(0);}
    for(int i=0;i<res.size();i++){
        cout<<res[i];
    }
    cout<<endl;
    return 0;
}
//calculates the predessor of n in nature
Vector<int> pred(Vector<int> n){
    if(n[0]==0){
        if (n.size()==1) return n;
        return pred(n.subList(1));
    }
    for(int i=n.size()-1;i>=0;i--){
        if(n[i]==0){
            return pred(n.subList(0,n.size()-1))+9;
        }
        else{
            return n.subList(0,n.size()-1)+(n[i]-1);
        }
    }
}
//calulates n-m in nature
Vector<int> sub(Vector<int> n, int m){
    Vector<int> res=n;
    for(int i=0;i<m;i++){
        res=pred(res);
    }
    return res;
}

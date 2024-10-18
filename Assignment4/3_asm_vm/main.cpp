#include <iostream>
#include <Stack.h>
#include <sstream>
#include <Grid.h>
#include <Vector.h>
#include <Map.h>
using namespace std;
//main function
int main(){
    int n;
    cin>>n;
    Grid<string> program(n,2);
    string line;
    getline(cin,line);
    Stack<int> num;
    for(int i=0;i<n;i++){
        getline(cin,line);
        stringstream line_s(line);
        line_s>>program[i][0]>>program[i][1];
    }
    Map<string,int> state;
    //Map<string,int> command={{"Add",1},{"Sub",2},{"Mul",3},{"Div",4},{"SetVar",5},{"Var",6},{"Jmp",7},{"JmpEq",8},{"JmpGt",9},{"JmpLt",10},{"Const",11},{"Print",12},{"Halt",13}};
    int i=0;
    while(i<n){
        if(program[i][0]=="Add"){
            if(num.size()<2){
                cout<<"Error"<<endl;
                break;
            }
            num.push(num.pop()+num.pop());
            i+=1;
            continue;
        }
        if(program[i][0]=="Sub"){
            if(num.size()<2){
                cout<<"Error"<<endl;
                break;
            }
            int res=num.pop()-num.pop();
            num.push(-res);
            i+=1;
            continue;
        }
        if(program[i][0]=="Mul"){
            if(num.size()<2){
                cout<<"Error"<<endl;
                break;
            }
            num.push(num.pop()*num.pop());
            i+=1;
            continue;
        }
        if(program[i][0]=="Div"){
            if(num.size()<2){
                cout<<"Error"<<endl;
                break;
            }
            int d=num.pop();
            if(d==0){
                cout<<"Error"<<endl;
                break;
            }
            num.push(num.pop()/d);
            i+=1;
            continue;
        }
        if(program[i][0]=="SetVar"){
            if(num.size()<1){
                cout<<"Error"<<endl;
                break;
            }
            state.put(program[i][1],num.pop());
            i+=1;
            continue;
        }
        if(program[i][0]=="Var"){
            if(!state.containsKey(program[i][1])){
                cout<<"Error"<<endl;
                break;
            }
            num.push(state.get(program[i][1]));
            i+=1;
            continue;
        }
        if(program[i][0]=="Jmp"){
            i=stoi(program[i][1]);
            if(i>n-1){
                cout<<"Error"<<endl;
                break;
            }
            continue;
        }
        if(program[i][0]=="JmpEq"){
            if(num.size()<2){
                cout<<"Error"<<endl;
                break;
            }
            if(num.pop()==num.pop()){
                i=stoi(program[i][1]);
                if(i>n-1){
                    cout<<"Error"<<endl;
                    break;
                }
                continue;
            }
            else{
                i+=1;
                continue;
            }
        }
        if(program[i][0]=="JmpGt"){
            if(num.size()<2){
                cout<<"Error"<<endl;
                break;
            }
            if(num.pop()<num.pop()){
                i=stoi(program[i][1]);
                if(i>n-1){
                    cout<<"Error"<<endl;
                    break;
                }
                continue;
            }
            else{
                i+=1;
                continue;
            }
        }
        if(program[i][0]=="JmpLt"){
            if(num.size()<2){
                cout<<"Error"<<endl;
                break;
            }
            if(num.pop()>num.pop()){
                i=stoi(program[i][1]);
                if(i>n-1){
                    cout<<"Error"<<endl;
                    break;
                }
                continue;
            }
            else{
                i+=1;
                continue;
            }
        }
        if(program[i][0]=="Const"){
            num.push(stoi(program[i][1]));
            i+=1;
            continue;
        }
        if(program[i][0]=="Print"){
            cout<<state.get(program[i][1])<<endl;
            i+=1;
            continue;
        }
        if(program[i][0]=="Halt")break;
        /*int c =command.get(program[i][0]);
        switch(c){
            case 1:case 2:case 3:case 4:case 8:case 9:case 10:if(num.size()<2){i=n;cout<<"ERROR"<<endl;}break;
            case 5:if(num.size()<1){i=n;cout<<"ERROR"<<endl;}break;
            case 6:case 7:case 11:case 12:case 13:break;
        }
        if(i==n)break;
        switch(c){
            case 1:num.push(num.pop()+num.pop());break;
            case 2:{int res=num.pop()-num.pop();num.push(-res);}break;
            case 3:num.push(num.pop()*num.pop());break;
            case 4:{int d=num.pop();
                if(d==0){{i=n;cout<<"ERROR"<<endl;break;}
                num.push(1/d*num.pop());}break;
            case 5:state.put(program[i][1],num.pop());break;
            case 6:num.push(state.get(program[i][1]));break;
            case 7:i=stoi(program[i][1])-1;break;
            case 8:if(num.pop()==num.pop())i=stoi(program[i][1])-1;break;
            case 9:if(num.pop()<num.pop())i=stoi(program[i][1])-1;break;
            case 10:if(num.pop()>num.pop())i=stoi(program[i][1])-1;break;
            case 11:num.push(stoi(program[i][1]));break;
            case 12:cout<<state.get(program[i][1])<<endl;
                break;
            case 13:i=n;break;
        }
        i+=1;*/
    }
    return 0;
}

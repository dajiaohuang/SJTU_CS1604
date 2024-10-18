#include <iostream>
#include <Vector.h>
#include <Grid.h>
#include <Queue.h>
using namespace std;
//main function
int main(){
    int n,m,k,h,x,y,res=0;
    cin>>n>>m>>k>>h;
    Grid<int> terrain(n,m);
    Grid<bool> flooded(n,m,0);
    Queue<pair<int,int>> q;
    for(int i=0;i<k;i++){
        cin>>x>>y;
        flooded[x][y]=1;
        q.enqueue(make_pair(x,y));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>terrain[i][j];
        }
    }
    while(!q.isEmpty()){
        pair<int,int> point = q.dequeue();
        res+=1;
        if(point.first>0&&
           flooded[point.first-1][point.second]==0&&
           terrain[point.first-1][point.second]<=h){
            flooded[point.first-1][point.second]=1;
            q.enqueue(make_pair(point.first-1,point.second));
        }
        if(point.first<n-1&&
           flooded[point.first+1][point.second]==0&&
           terrain[point.first+1][point.second]<=h){
            flooded[point.first+1][point.second]=1;
            q.enqueue(make_pair(point.first+1,point.second));
        }
        if(point.second>0&&
           flooded[point.first][point.second-1]==0&&
           terrain[point.first][point.second-1]<=h){
            flooded[point.first][point.second-1]=1;
            q.enqueue(make_pair(point.first,point.second-1));
        }
        if(point.second<n-1&&
           flooded[point.first][point.second+1]==0&&
           terrain[point.first][point.second+1]<=h){
            flooded[point.first][point.second+1]=1;
            q.enqueue(make_pair(point.first,point.second+1));
        }
    }
    cout<<res<<endl;
    return 0;
}


#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n = 9;
    int graph[9][9]={{0,0,0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0,0,0}, 
                 {0,1,0,0,1,1,0,0,0},
                 {0,1,0,0,0,0,0,1,0},
                 {0,0,1,0,0,1,0,0,0},
                 {0,0,1,0,1,0,0,0,1},
                 {0,0,0,0,0,0,0,0,0},
                 {0,0,0,1,0,0,0,0,0},
                 {0,0,0,0,0,1,0,0,0}};
    int visited[9];
    for(int i=0; i<n; i++) visited[i] = 0;
    stack<int> s;
    s.push(1);
    visited[1] = 1;
    while(!s.empty()){
        int next = s.top();
        cout <<next<<" ";
        s.pop();
        for(int i=0; i<9; i++){
            if(graph[next][i] && visited[i]==0){
                s.push(i);
                visited[i]  =1;
            }
        }
    }
    cout <<endl;
}
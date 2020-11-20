#include <iostream>
using namespace std;
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
void dfs(int idx){
    if(visited[idx]){return;}
    visited[idx] = 1;
    cout <<idx<<" ";
    for(int i=1; i<=8; i++){
        if(graph[idx][i] && !visited[i]){
            dfs(i);
        }
    }
    return;
}
int main(){
    dfs(1);
    cout <<endl;
}
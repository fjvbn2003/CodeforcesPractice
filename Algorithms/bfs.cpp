#include <iostream>
#include <queue>
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
void bfs(){
    queue <int > q;
    q.push(1);
    visited[1] = 1;
    while(q.size()){
        int cur = q.front();
        cout<< cur<<" ";
        q.pop();
        for(int i=1; i<=8; i++){
            if(graph[cur][i] && !visited[i]){
                q.push(i);
                visited[i] =1;
            }
        }
    }
    return;
}
int main(){
    bfs();
    cout <<endl;
}
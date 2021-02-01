#include <iostream>
#include <queue>
using namespace std;
vector<int> graph[32001];
int indegree[32001];
int main(){
    int n,m,a,b;
    cin>>n>>m;
    queue<int> q;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    for(int i=1; i<=n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        cout << q.front()<<" ";
        int t = q.front();
        q.pop();
        for(int i=0; i<graph[t].size(); i++){
            indegree[graph[t][i]]--;
            if(indegree[graph[t][i]] == 0){
                q.push(graph[t][i]);
            }
        }
    }
    cout <<endl;
    return 0;
    

}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

int main(){
  int a,b;
  int n,m;
  cin>>n>>m;
  vector<int> adj[n+1];
  vector<int> in_degree(n+1,0);  
  for(int i=0; i<m; i++){
    cin>>a>>b;
    adj[a].push_back(b);
    in_degree[b]++;
  }
  priority_queue<int> pq;
  vector<int> ans;
  for(int i=1; i<=n; i++){
    if(in_degree[i] == 0){
      pq.push(-i);
    }
  }
  while(!pq.empty()){
    int cur = -pq.top();
    pq.pop();
    ans.push_back(cur);
    for(int i=0; i<adj[cur].size(); i++){
      int next = adj[cur][i];
      in_degree[next]--;
      if(in_degree[next]==0){
        pq.push(-next);
      }
    }
  }
  for(auto i : ans){
    cout <<i<<" ";
  }
  cout <<endl;
  return 0;
  


}
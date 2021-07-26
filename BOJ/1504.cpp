#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<int,int> >adj[801];
int main(){
  int n,k;
  cin>>n>>k;
  int a,b,c,v1,v2;
  for(int i=0; i<k; i++){
    cin>>a>>b>>c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }
  cin>>v1>>v2;
  vector<int> dist(n+1, 1e9);
  vector<int> visited(n+1,0);
  vector<long long> answers;
  int t = n;
  int node  =1;
  long long ans = 0;
  dist[node] = 0;
  // dijkstra shortest path algorithm
  while(t--){
    if(visited[node] == 1) break;
    visited[node] = 1;
    for(int i=0; i<adj[node].size(); i++){
      int next = adj[node][i].first;
      int cost = adj[node][i].second;
      if(visited[next]==0){
        if(dist[node]+cost < dist[next]){
          dist[next] = dist[node]+cost;
        }
      }
    }
    int next_node = node;
    int next_cost = 1e9;
    for(int i=1; i<=n; i++){
      if(visited[i]==0 && dist[i]<next_cost){
        next_node = i;
        next_cost = dist[i];
      }
    }
    node = next_node;
  }
  answers.push_back(dist[v1]);
  answers.push_back(dist[v2]);
  

  for(int i=0; i<=n; i++){
    dist[i] = 1e9;
    visited[i] = 0;
  }

  t = n;
  node  =v1;
  dist[node] = 0;
  // dijkstra shortest path algorithm
  while(t--){
    if(visited[node] == 1) break;
    visited[node] = 1;
    for(int i=0; i<adj[node].size(); i++){
      int next = adj[node][i].first;
      int cost = adj[node][i].second;
      if(visited[next]==0){
        if(dist[node]+cost < dist[next]){
          dist[next] = dist[node]+cost;
        }
      }
    }
    int next_node = node;
    int next_cost = 1e9;
    for(int i=1; i<=n; i++){
      if(visited[i]==0 && dist[i]<next_cost){
        next_node = i;
        next_cost = dist[i];
      }
    }
    node = next_node;
  }
  answers.push_back(dist[v2]);
  answers.push_back(dist[n]);

  for(int i=0; i<=n; i++){
    dist[i] = 1e9;
    visited[i] = 0;
  }
  t = n;
  node  =v2;
  dist[node] = 0;
  // dijkstra shortest path algorithm
  while(t--){
    if(visited[node] == 1) break;
    visited[node] = 1;
    for(int i=0; i<adj[node].size(); i++){
      int next = adj[node][i].first;
      int cost = adj[node][i].second;
      if(visited[next]==0){
        if(dist[node]+cost < dist[next]){
          dist[next] = dist[node]+cost;
        }
      }
    }
    int next_node = node;
    int next_cost = 1e9;
    for(int i=1; i<=n; i++){
      if(visited[i]==0 && dist[i]<next_cost){
        next_node = i;
        next_cost = dist[i];
      }
    }
    node = next_node;
  }
  answers.push_back(dist[v1]);
  answers.push_back(dist[n]);
  ans = min(answers[0]+answers[2]+answers[5], answers[1]+answers[4]+answers[3]);
  // for(int i=0; i<6; i++)
  //   cout << answers[i]<<" ";
  // cout <<endl;
  if(ans>=1e9){
    cout <<-1<<endl;
  }else{
      cout <<ans<<endl;
  }
  return 0;

}
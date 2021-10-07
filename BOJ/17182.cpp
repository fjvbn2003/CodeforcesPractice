#include <iostream>
#include <vector>
#include <algorithm>
// 플로이드 워셜알고리즘 후 DFS로 최솟값 탐색.
using namespace std;

int N, K;
vector<vector<int> > graph;
vector<vector<int> > dist;
vector<bool> visited;
int ans = 123456789;

void dfs(int node, int cnt, int s){
  if(cnt == N){
    ans = min(ans, s);
    return;
  }
  for(int i=0; i<N; i++){
    if(i!= node && visited[i]==false){
      visited[i] = true;
      dfs(i, cnt+1, s+dist[node][i]);
      visited[i] = false;
    }
  }
  return;
}

int main(){
  cin>>N>>K;
  graph.resize(N, vector<int>(N, 0));
  dist.resize(N, vector<int>(N, 0));
  visited.resize(N, false);
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cin>> graph[i][j];

  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      dist[i][j] = graph[i][j];
  
  for(int k=0; k<N; k++){
    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout <<dist[i][j]<<" ";
  //   }
  //   cout <<endl;
  // }
  visited[K] = true;
  dfs(K, 1, 0);

  cout <<ans<<endl;
  return 0;
}
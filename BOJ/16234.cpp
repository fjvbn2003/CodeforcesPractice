// 어떻게든 풀어보자.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int N, L, R;
int arr[51][51];
int visited[51][51];
int D[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool bfs(int r, int c){
  vector<pair<int, int> > nodes;
  queue<pair<int, int> > q;
  // 연합 나라의 인구수 총합.
  int s =0;
  nodes.push_back({r,c});
  q.push({r,c});
  visited[r][c] = 1;
  s+= arr[r][c];
  while(!q.empty()){
    int cr = q.front().first;
    int cc = q.front().second;
    q.pop();
    for(int i=0; i<4; i++){
      int nr = cr+D[i][0];
      int nc = cc+D[i][1];
      if(nr>=N || nr<0 || nc>=N || nc<0 || visited[nr][nc] || (abs(arr[cr][cc]- arr[nr][nc])<L || abs(arr[cr][cc]- arr[nr][nc])>R) ) continue;
      s += arr[nr][nc];
      nodes.push_back({nr, nc});
      visited[nr][nc] = 1;
      q.push({nr, nc});
    }
  }


  if(nodes.size()==1){
    return false;
  }else{
    //1개 이상의 나라와 연합.
    int share = s/nodes.size();
    for(int i=0; i<nodes.size(); i++){
      arr[nodes[i].first][nodes[i].second] = share;
    }
    return true;
  }
}


int main(){
  
  cin>>N>>L>>R;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cin>> arr[i][j];
  int ans =0;
  for(int time=0; time<=2000; time++){
    bool happend = false;
    // visited 배열 초기화
    for(int i=0; i<N; i++)
      for(int j=0; j<N; j++)
        visited[i][j] = 0;

    for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
        if(visited[i][j]==0){
          happend |= bfs(i, j);
        }
      }
    }
    if(!happend){
      ans = time;
      break;
    }

  }
  cout <<ans<<endl;
  return 0;
}
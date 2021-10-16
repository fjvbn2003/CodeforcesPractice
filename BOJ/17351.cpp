#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
// BOJ 17351 3루수는 몰라.
int N;
vector<vector<char> > arr;

int dp[501][501][4];

// str =0 이면 현재까지 준비된 단어가 없음.
// str =1 이면 현재까지 준비된 단어가 M ...
// str을 상태라고 생각해보아라.
int D[2][2] = {{1,0}, {0,1}};
int dfs(int y, int x, int str){
  if(y==N-1 && x == N-1){
    if(str==3 && arr[y][x]=='A') return 1;
    else return 0;
  }
  int& ret = dp[y][x][str];
  if(ret != -1) return ret;
  

  for(int i=0; i<2; i++){
    int ny = y + D[i][0];
    int nx = x + D[i][1];
    if(ny>=N || ny<0 || nx >=N || nx<0) continue;

    if(str==3 && arr[y][x]=='A'){
      ret = max(ret, dfs(ny, nx, 0)+1);
    }else if(str ==2 && arr[y][x] =='L'){
      ret = max(ret, dfs(ny, nx, 3));
    }else if(str ==1 && arr[y][x] =='O'){
      ret = max(ret, dfs(ny, nx, 2));
    }else if(str ==0 && arr[y][x] =='M'){
      ret = max(ret, dfs(ny, nx, 1));
    }
    ret = max(ret, dfs(ny, nx, 0));
  }

  return ret;

}

int main(){
  cin>>N;
  arr.resize(N, vector<char>(N));
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin>> arr[i][j];
    }
  }
  for(int i=0; i<=N; i++)
    for(int j=0; j<=N; j++)
      for(int k=0; k<4; k++)
        dp[i][j][k] = -1;

  int ans = dfs(0,0,0);
  cout <<ans<<endl;
  return 0;

}
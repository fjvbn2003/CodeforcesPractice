#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
vector<vector<int> > arr;
int n, m;
int D[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int bfs(int r, int c){
  int maxi= 0;
  vector<vector<int> >visited(n, vector<int>(m,-1));
  queue<pair<int, int> > q;
  q.push({r,c});
  visited[r][c] = 0;
  while(!q.empty()){
    int cur_r = q.front().first;
    int cur_c = q.front().second;
    maxi = max(maxi, visited[cur_r][cur_c]);
    q.pop();
    for(int i=0; i<4; i++){
      int nr = D[i][0] + cur_r;
      int nc = D[i][1] + cur_c;
      if(nr<0 || nr>=n || nc<0 || nc>=m || arr[nr][nc]==0 || visited[nr][nc]!=-1) continue;
      q.push({nr, nc});
      visited[nr][nc] =  visited[cur_r][cur_c]+1;

    }

  }
  // cout <<"start :" <<r<<" "<<c<<endl;
  // for(int i=0; i<n; i++){
  //   for(int j=0; j<m; j++){
  //     cout <<visited[i][j]<<" ";
  //   }
  //   cout <<endl;
  // }
  return maxi;
}

int main(){
  string s;
  cin>> n>>m;
  for(int i=0; i<n; i++){
    cin>> s;
    vector<int> t;
    for(int j=0; j<m; j++){
      t.push_back((s[j]=='L')? 1 : 0);
    }
    arr.push_back(t);
  }
  int maxi = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(arr[i][j]==0) continue;
      maxi = max(maxi,bfs(i,j));
    }
  }
  cout <<maxi<<endl;
  return 0;
}
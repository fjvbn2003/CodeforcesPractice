#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int M, N;
vector<vector<int> > arr;
vector<vector<int> > visited;

int D[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},{0, 1}, {1, -1}, {1, 0}, {1,1}};
bool dfs(int y, int x){
  for(int i=0; i<8; i++){
    int ny = y+D[i][0];
    int nx = x+D[i][1];
    if(ny>=0 && ny<M && nx>=0 && nx<N && arr[ny][nx]==1 && visited[ny][nx]==0){
      //cout <<"from: "<<y<<" "<<x<<" call: "<< ny<<" "<<nx<<endl;
      visited[ny][nx] = 1;
      dfs(ny, nx);
    }
  }
  return true;
}

void print_dfs(){
  for(int i=0; i<M; i++){
    for(int j=0; j<N; j++){
      cout << visited[i][j];
    }
    cout <<endl;
  }
}
int main(){
  cin>>M>>N;
  arr.resize(M, vector<int>(N, 0));
  visited.resize(M, vector<int>(N, 0));
  
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++)
      cin>> arr[i][j];

  int ans =0;
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++){
      if(arr[i][j] && visited[i][j]==0){
        //cout <<" i, j"<<i<<" "<<j<<endl;
        //print_dfs();
        dfs(i, j);
        ans++;
      }
    }
  cout <<ans<<endl;
  return 0;
  

}
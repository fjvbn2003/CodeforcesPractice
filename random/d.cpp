#include <iostream>
#include <vector>

using namespace std;
int dy[13][3] = {{0,0,0},{-1,0,1},{-1,0,1},{-1,0,1}    ,{1,1,1},
                  {-1,0,0},{-1,-1,0},{0,1,0},{1,1,0},
                  {0,1,0},{-1,-1,0},{-1,0,0},{1,1,0}
                  };
int dx[13][3] = {{0,0,0},{1,1,1}, {-1,-1,-1},{-1,-1,-1},{-1,0,1},
                  {1,1,0},{-1,0,0},{-1,-1,0},{0,1,0},
                  {1,1,0},{0,1,0},{-1,-1,0},{-1,0,0}
              };
int N,T;

int visited[101][101][1][1];
vector<vector<int> > arr;
// x, y에 도착했을 때 방향
void brute_force(int x, int y, int dir_x, int dir_y, int times){
  if(x<=0 || y<=0 || x>N || y>=N){
    return ;
  }
  if(times>T) return;
  if(visited[])
  visited[y][x][dir_x][dir_y] = 1;
  cout <<"hihi"<<x<<" "<<y<<endl;
  int k = arr[x-1][y-1];
  //cout <<"k: "<<k<<endl;
  for(int i=1; i<=12; i++){
    if(k&(1<<i)){
      //cout <<i<<endl;
      for(int j=0; j<3; j++){
        if(dir_y == dy[i][k]){
          cout <<"hi y"<<endl;
          brute_force(x, y+dy[i][k], 0 ,dy[i][k], times+1);
          brute_force(x, y+dy[i][k], dx[i][k], 0, times+1);
        }
        if(dir_x == dx[i][k]){
          cout <<"hi x"<<endl;
          brute_force(x+dx[i][k],y, 0 ,dy[i][k], times+1);
          brute_force(x+dx[i][k], y, dx[i][k], 0, times+1);
        }
      }
    }
  }
  return ;
}
int main(){
  cin>>N>>T;
  for(int i=0; i<N; i++){
    vector<int> tt;
    for(int j=0; j<N; j++){
        int road = 0;
        int t;
        for(int k=0; k<4; k++){
          cin>>t;
          road |= (1<<t);
        }
        tt.push_back(road);
    }
    arr.push_back(tt);
  }
  brute_force(1,1,0,-1,0);
  // for(int i=0; i<arr.size(); i++){
  //   for(int j=0; j<arr[i].size(); j++){
  //     cout << arr[i][j]<<" ";
  //   }
  // }
  int cnt = 0;
  for(int i=1; i<=N; i++){
    for(int j=1; j<=N ; j++){
      if(visited[i][j]==1){
        cnt++;
        cout <<i<<" "<<j<<endl;
      }
    }
  }
  cout <<cnt<<endl;
  return 0;

}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N = 4;
int D[8][2] = {{-1,0},{-1,-1},{0,-1}, {1,-1},{1,0}, {1,1},{0,1}, {-1,1}};
// 상어가 있는 칸은 id=0, 
// 물고기가 없는 칸은 id=-1
// r,c를 먹었을 때, arr일 때 최댓 값.
int dfs(int r, int c, vector<vector<pair<int, int> > > arr){
  int ret = 0;
  // 현재 상어 위치는 r,c 
  //cout <<"call r:"<<r<<" c: "<<c<<endl;
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout << arr[i][j].first<<" "<<arr[i][j].second<<"  ";
  //   }
  //   cout <<endl;
  // }


  // 물고기 이동.
  for(int id=1; id<=16; id++){
    //arr에서 물고기를 찾기.
    for(int i=0; i<N*N; i++){
      int rr = i/N;
      int cc = i%N;
      if(arr[rr][cc].first == id){
        // 방향에 벽이 아니고, 상어가 없다면 물고기 이동.
        int dir = arr[rr][cc].second;
        for(int j=dir; j<dir+8; j++){
          int nr = rr+D[j%8][0];
          int nc = cc+D[j%8][1];
          if(nr<0 || nr>=N || nc<0 || nc>=N || arr[nr][nc].first ==0) continue;
          //cout <<"swap: "<<"rr: "<<rr<<" cc: "<<cc<<" nr: "<<nr<<" nc: "<<nc<<endl;
          arr[rr][cc].second = j%8;
          swap(arr[rr][cc], arr[nr][nc]);
          break;
        }
        break;
      }
    }
  }

  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout << arr[i][j].first<<" "<<arr[i][j].second<<"  ";
  //   }
  //   cout <<endl;
  //}
  //상어이동
  //cout <<"bottom call r:"<<r<<" c: "<<c<<endl;
  int dir = arr[r][c].second;
  //cout <<"dir: "<<dir<<endl;
  // 최대 3칸까지 갈 수 있는 경우의 수.
  for(int i=1; i<=3; i++){
    int nr = r + D[dir][0]*i;
    int nc = c + D[dir][1]*i;
    //cout <<"nr: "<<nr<<" nc: "<<nc<<endl;
    if(nr<0 || nr>=N || nc <0 || nc>=N || arr[nr][nc].first == -1) continue;

    int backup_first = arr[nr][nc].first;
    
    arr[nr][nc].first = 0;
    arr[r][c].first = -1;
    
    ret = max(ret, dfs(nr, nc, arr)+ backup_first);
    
    // 원상복귀
    arr[nr][nc].first = backup_first;
    arr[r][c].first = 0;

  }

  return ret;
}


int main(){
  int a, b;
  vector<vector<pair<int, int> > > arr(N, vector<pair<int, int> >(N, pair<int,int>()));

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      cin>>a>>b;
      arr[i][j] = {a,b-1};
    }
  }

  int ans = arr[0][0].first;
  //cout <<"first dir: "<< arr[0][0].second<<endl;
  arr[0][0].first = 0;
  ans += dfs(0, 0, arr);

  cout <<ans<<endl;
  return 0;
}
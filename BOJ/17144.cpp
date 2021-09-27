#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int R,C,T;
int D[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int aircon_r;
// 미세먼지 확산.
vector<vector<int> > spread(vector<vector<int> > & t){
  vector<vector<int> > ret(R, vector<int>(C,0));
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(t[i][j]==0) continue;
      if(t[i][j]==-1){
        ret[i][j] = -1;
        continue;
      }
      int val = t[i][j];
      int cnt = 0;
      for(int k=0; k<4; k++){
        int next_r = i+D[k][0];
        int next_c = j+D[k][1];
        if(next_r>=R || next_r <0 || next_c>=C || next_c<0 || t[next_r][next_c]==-1) continue;
        cnt++;
        ret[next_r][next_c]+= val/5;
      }
      ret[i][j] += (val - (val/5)*cnt);
    }
  }
  return ret;
}
// 공기청정기 돌리기.
vector<vector<int> > rotate(vector<vector<int> > & t){
  vector<vector<int> > ret(R, vector<int>(C,0));
  int a1 = aircon_r-1;
  int a2 = aircon_r;
  // a1위쪽의 공기를 아래로 내림.
  for(int i=a1-1; i>0; i--){
    ret[i][0] = t[i-1][0];
  }
  // 공기 왼쪽으로 한칸씩.
  for(int i=0; i<C-1; i++){
    ret[0][i] = t[0][i+1];
  }
  // 공기 위로 한 칸씩.
  for(int i=0; i<a1; i++){
    ret[i][C-1] = t[i+1][C-1];
  }
  // 공기 옆으로 한 칸씩.
  for(int i=C-1; i>1; i--){
    ret[a1][i] = t[a1][i-1];
  }
  //신선한 공기.
  ret[a1][1] = 0;
  //영향을 받지 않는 곳은 복원.
  for(int i=1; i<a1; i++){
    for(int j=1; j<C-1; j++){
      ret[i][j] = t[i][j];
    }
  }
  // a2 아래의 공기를 위로.
  for(int i=a2+1; i<R-1; i++){
    ret[i][0] = t[i+1][0];
  }
  // a2 공기 왼쪽으로
  for(int i=0; i<C-1; i++){
    ret[R-1][i] = t[R-1][i+1];
  }
  // 공기 아래로.
  for(int i=R-1; i>a2; i--){
    ret[i][C-1] = t[i-1][C-1];
  }
  // 공기 오른쪽으로
  for(int i=C-1; i>1; i--){
    ret[a2][i] = t[a2][i-1];
  }
  ret[a2][1] = 0;
  for(int i=a2+1; i<R-1; i++){
    for(int j=1; j<C-1; j++){
      ret[i][j] = t[i][j];
    }
  }
  ret[a1][0] = -1;
  ret[a2][0] = -1;

  return ret;
}

int count(vector<vector<int> > & t){
  int ret = 0;
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(t[i][j]!= -1){
        ret += t[i][j];
      }
    }
  }
  return ret;
}

int main(){
  cin>>R>>C>>T;
  vector<vector<int> > arr(R, vector<int>(C, 0));
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      cin>> arr[i][j];
      if(arr[i][j] == -1){
        aircon_r = i;
      }
    }
  }
  // arr = spread(arr);
  // arr = rotate(arr);
  // for(int i=0; i<R; i++){
  //   for(int j=0; j<C; j++){
  //     cout<< arr[i][j] <<" ";
  //   }
  //   cout <<endl;
  // }


  while(T--){
    arr = spread(arr);
    arr = rotate(arr);
    // cout <<endl;
    // for(int i=0; i<R; i++){
    //   for(int j=0; j<C; j++){
    //     cout<< arr[i][j] <<" ";
    //   }
    //   cout <<endl;
    // }
  }
  cout << count(arr)<<endl;
  return 0;
}
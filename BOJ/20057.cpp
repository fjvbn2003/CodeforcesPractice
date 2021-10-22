#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[1001][1001];
// 왼쪽, 아래, 오른쪽, 위쪽
int D[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
// 각각의 4가지 방향마다.
// 10개의 위치로 모래가 흩어짐
// [비율, dy, dx]
int BD[4][9][3]={
        // 왼쪽
        {
            {5,0,-2},
         {10,1,-1},
         {7,1,0},
         {1,1,1},
         {2,2,0},
         {10,-1,-1},
         {7,-1,0},
         {1,-1,1},
         {2,-2,0}
         },

         //아랫쪽
        {
                {5,2,0},
                {10,1,-1},
                {7,0,-1},
                {1,-1,-1},
                {2,0,2},
                {10,1,1},
                {7,0,1},
                {1,-1,1},
                {2,0,-2}
        },
        {//오른쪽
                {5,0,2},
                {10,1,1},
                {7,1,0},
                {1,1,-1},
                {2,2,0},
                {10,-1,1},
                {7,-1,0},
                {1,-1,-1},
                {2,-2,0}
            },
        {// 위쪽

                {5,-2,0},
                {10,-1,-1},
                {7,0,-1},
                {1,1,-1},
                {2,0,2},
                {10,-1,1},
                {7,0,1},
                {1,1,1},
                {2,0,-2}
        }

};

int ans = 0;
void blow(int r, int c, int dir){
    int remain_sends = arr[r][c];
    int whole =remain_sends;
    arr[r][c] = 0;
    for(int i=0; i<9; i++){
        int ratio = BD[dir][i][0];
        int ny = r+BD[dir][i][1];
        int nx = c+BD[dir][i][2];
        int tmp = (whole*ratio)/100;
        if(ny>=N || ny<0 || nx>=N || nx<0){
            ans += tmp;
        }else{
            arr[ny][nx] += tmp;
        }
        remain_sends -= tmp;
    }
    int ny = r+D[dir][0];
    int nx = c+D[dir][1];
    if(ny<0 || ny>=N || nx<0 || nx>=N){
        ans += remain_sends;
    }else{
        arr[ny][nx] += remain_sends;
    }

    return;
}
int main(){
  cin>>N;
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      cin>>arr[i][j];
  int dir = 0;
  int r = N/2;
  int c = N/2;
  int step = 1;
  int time = 0;
  int t = 0;
  for (int i=0; i<N*N; i++){
      if(r==0 && c ==0) break;
      r += D[dir][0];
      c += D[dir][1];
     // cout <<r<<" "<<c<<endl;

    blow(r,c, dir);
    t++;
    if(t==step){
      t=0;
      time++;
      dir++;
      dir%=4;
    }
    if(time==2){
      step++;
      time = 0;
    }
  }
  cout << ans<<endl;
  return 0;

}

/*
3  3
0 0 0 
0 0 0
0 0 0

*/
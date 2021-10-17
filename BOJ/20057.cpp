#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[1001][1001];
int D[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
int portion[4][9][2] = {
{{-1,1}},// 왼쪽
{},
{},
{}
};
int ans = 0;
void blow(int r, int c, int dir){


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
    r += D[dir][0];
    c += D[dir][1];
    cout <<r<<" "<<c<<endl;

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


}

/*
3  3
0 0 0 
0 0 0
0 0 0

*/
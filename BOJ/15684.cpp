#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define LEFT 1
#define RIGHT 2

int N, M, H;
vector<vector<int> > arr;
int answer = 987654321;
void brute(int idx, int cnt){
  int row = idx/N;
  int col = idx%N;
    // if(row==0 && col==2){
    //   cout <<"hi"<<endl;
    // for(int i=0; i<H; i++){
    //   for(int j=0; j<N; j++){
    //     cout << arr[i][j]<<" ";
    //   }
    //   cout <<endl;
    // }
    //}
  if(idx >=N*H){
    // test if satisfying

    for(int i=0; i<N; i++){
      int col = i;
      for(int j=0; j<H; j++){
        if(arr[j][col]==RIGHT){
          col += 1;
        }else if(arr[j][col] == LEFT){
          col -= 1;
        }else{
          continue;
        }
      }
      if(col != i) return;
    }
    // cout <<"idx: "<<idx<<" cnt:"<<cnt<<endl;
    // for(int i=0; i<H; i++){
    //   for(int j=0; j<N; j++){
    //     cout << arr[i][j]<<" ";
    //   }
    //   cout <<endl;
    // }
    answer = min(answer, cnt);
    return;
  }

  

  if(cnt==3 || (arr[row][col] != 0) || (col ==N-1) || (arr[row][col+1] == RIGHT ) ){
    brute(idx+1, cnt);
  }else{


    arr[row][col] = RIGHT;
    arr[row][col+1] = LEFT;
    brute(idx+1, cnt+1);
    arr[row][col] = 0;
    arr[row][col+1] = 0;
    brute(idx+1, cnt);
  }
  return ;
}


int main(){
  cin>> N>> M >> H;
  arr.resize(H, vector<int>(N, 0));
  int a,b;
  for(int i=0; i<M; i++){
    cin>>a>>b;
    arr[a-1][b-1] = RIGHT;
    arr[a-1][b] = LEFT;
  }
  // for(int i=0; i<H; i++){
  //   for(int j=0; j<N; j++){
  //     cout << arr[i][j]<<" ";
  //   }
  //   cout <<endl;
  // }
  brute(0, 0);

  if(answer == 987654321){
    cout << -1<<endl;
    return 0;
  }

  cout <<answer<<endl;
  return 0;
}
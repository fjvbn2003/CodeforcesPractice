/*
  BOJ: 2048(12100번 문제)
  Tier: GOLD2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, ans;
// 맵을 돌리거나 조작을 필요로 하는 연산에서 새로운 배열을 만들고,뒤에 덮어쓰는 아이디어.

// 구조체로 만드는 아이디어. rotate를 멤버함수로.
struct BOARD{
  int map[20][20];
  // 시계방향 회전
  void rotate(){
    int temp[20][20];
    for(int y=0; y<n; y++){
      for(int x = 0; x<n; x++){
        //0,2 <- 1,0   0,3 <- 0,0   1,3 <- 0,1   0,0 <- 3,0
        temp[y][x] = map[n-x-1][y];
      }
    }
    for(int y=0; y<n; y++){
      for(int x = 0; x<n; x++){
        map[y][x] = temp[y][x];
      }
    }
    return;
  }
  int get_max(){
    int ret = 0;
    for(int y=0; y<n; y++){
      for(int x = 0; x<n; x++){
        ret = max(ret, map[y][x]);    
      }
    }
    return ret;
  }

  void up(){
    int temp[20][20];
    for(int x=0; x<n; x++){
      bool flag = false;
      int target = 0;
      for(int y=0; y<n; y++){
        if(map[y][x] == 0) continue;
        if(flag && temp[target-1][x]==map[y][x]){
          temp[target-1][x] *=2;
          flag = false;
        }else{
          temp[target][x] = map[y][x];
          target++;
          flag = true;
        }
      }
      for(int tt= target; tt<n; tt++){
        temp[tt][x] = 0;
      }
    }
    for(int y=0; y<n; y++)
      for(int x=0; x<n; x++)
        map[y][x] = temp[y][x];
    return;
  }
  // void up(){
  //   int temp[20][20];
  //   for(int x=0; x<n; x++){
  //     bool flag = false;
  //     int target = -1;
  //     for(int y=0; y<n; y++){
  //       if(map[y][x] == 0) continue;
  //       if(flag && map[y][x] == temp[target][x]){
  //         temp[target][x]*=2; flag = false;
  //       }else{
  //         temp[++target][x] = map[y][x], flag = 1;
  //       }


  //     }
  //     for(++target; target<n; ++target)
  //       temp[target][x] = 0;
  //   }
  //   for(int y=0; y<n; y++)
  //     for(int x=0; x<n; x++)
  //       map[y][x] = temp[y][x];
  //   return;
  // }

};

void dfs(BOARD cur, int count){
  if(count == 5){
    int cand = cur.get_max();
    ans = max(ans, cand);
    return ;
  }
  for(int dir=0; dir<4; dir++){
    BOARD next = cur;
    next.up();
    dfs(next, count+1);
    cur.rotate();
  }
  return;
}

int main(){
  cin>>n;
  BOARD board;
  for(int y=0; y<n; y++){
    for(int x=0; x<n; x++){
      cin>> board.map[y][x];
    }
  }
  ans = 0;
  dfs(board, 0);
  cout <<ans<<endl;
  return 0;

}
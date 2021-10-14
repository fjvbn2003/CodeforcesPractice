#include <iostream>

using namespace std;

int main(){
  int A, B;
  cin>>A>>B;

  // 전체 갯수 (18, 2) -> 153개
  // 땡의 갯수 10개.
  // 끗의 갯수 -> 80개



  double ans = 0;
  double win_cnt=0;
  double lose_cnt=0;
  for(int i=1; i<=20; i++){
    for(int j=i+1; j<=20; j++){
      int first = i;
      if(first>10) first-=10;
      int second =j;
      if(second >10) second-=10;
      // 같은 패가 나오는 경우 건너뜀.
      if(first==A && second==B) continue;

      if(first==second){
        if(A==B){
          if(A>first){
            win_cnt+=1;
          }else{
            lose_cnt+=1; 
          }
        }else{
          lose_cnt+=1;
        }
      }else{
        int tmp = first+second;
        if(tmp>10) tmp-=10;
        if(A==B){
          win_cnt+=1;
        }else{
          int tt = A+B;
          if(tt>10) tt-=10;
          if(tt>tmp){
            win_cnt+=1;
          }else{
            lose_cnt+=1;
          }

        }
      }

    }
  }

  ans = (win_cnt)/(win_cnt+lose_cnt);
  cout.fixed;
  cout.precision(3);
  cout <<ans<<endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
// brute force + backtracking 으로는 TLE
// 진짜배기 실력을 키우자.
// 풀 수 있는가 없는가?
using namespace std;

int main(){
  int N,M,L;
  cin>>N>>M>>L;
  vector<int> arr(M, 0);
  for(int i=0; i<M; i++)
    cin>>arr[i];
  
  int Q;
  for(int i=0; i<N; i++){
    cin>>Q;
    // 이분탐색. start는 포함 end는 미포함.
    int start = 0;
    int end = L;
    // Mid가 최솟 값일 때 Q개로 나눌 수 있는 가 없는가.
    while(start+1 <end){
      int mid = (start+end)/2;
      int cnt = 0;
      int before = 0;
      for(int i=0; i<M; i++){
        if(before +mid <= arr[i] && arr[i]+mid<=L){
          cnt++;
          before = arr[i];
        }
      }
      // 성공
      if(cnt >=Q){
        start = mid;
      }else{//실패
        end = mid;
      }
    }
    cout << start<<endl;
  } 

  return 0;
}
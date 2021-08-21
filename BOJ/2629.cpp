#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n,k,t; 
vector<int> arr;
bool dp[31][40001];
// cnt-1 번째 숫자를 사용해서 result를 만들 수 있다.
void bf(int cnt, int result){
  if(cnt >n) return ;
  if(dp[cnt][result]) return;
  dp[cnt][result] = true;
  bf(cnt+1, result+arr[cnt]); // 사용할 때
  bf(cnt+1, result);// 사용하지 않을 때
  bf(cnt+1, abs(result-arr[cnt])); //반대쪽에 넣을 때.
}
int main(){
  
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>t;
    arr.push_back(t);
  }
  bf(0,0);
  cin>>k;
  for(int i=0; i<k; i++){
    cin>>t;
    bool ans = false;
    for(int i=1; i<31; i++){
      if(dp[i][t]) ans = true;
    }
    if(ans) cout <<"Y"<<" ";
    else cout <<"N"<<" "; 
  }
  cout <<endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
int main(){
  int n;
  cin>>n;
  vector<ll> arr(n,0);
  vector<ll> dp(n,1);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
      // 자신보다 인덱스가 작으면서 자신보다 작으면 부분수열을 만들 수 있다. (맨 뒤에 자기 자신을 붙여서)
      if(arr[j]<arr[i]){
        dp[i]+= dp[j];
        dp[i]%= 998244353;
      }
    }
  }
  for(int i=0; i<n; i++){
    cout << dp[i]<<" ";
  }
  cout <<endl;
  return 0;

}
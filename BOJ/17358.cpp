#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
#define MOD 1000000007
int main(){
  int n;
  cin>>n;
  vector<long long> dp(n/2, 0);
  dp[0] = 1;
  for(int i=1; i<n/2; i++){
    int idx = (i+1)*2;
    dp[i] = dp[i-1]*(idx-1);
    dp[i]%=MOD;
  }
  cout<< dp[n/2-1]<<endl;
  return 0;
}
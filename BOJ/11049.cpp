#include <bits/stdc++.h>

long long dp[501][501];
using namespace std;

int main(){
  int n;
  cin>>n;

  vector<pair<long long, long long> > arr(n, pair<long long,long long>());
  for(int i=0; i<n; i++)
    cin>>arr[i].first>>arr[i].second;
  // diag
  for(int i=0; i<n; i++)
    dp[i][i] = 0;
  for(int i=0; i<n-1; i++)
    dp[i][i+1] = ((long long)arr[i].first)*(arr[i].second)*(arr[i+1].second);
  for(int t=2; t<n; t++){
    for(int i=0, j=i+t; j<n; i++, j++){
      dp[i][j] = dp[i][i]+dp[i+1][j]+(arr[i].first*arr[i].second*arr[j].second);
      for(int k=i+1; k<=j; k++)
        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+(arr[i].first*arr[k].second*arr[j].second));
    }
  }
  
  // for(int i=0; i<n; i++){
  //   for(int j=0; j<n; j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  cout << dp[0][n-1]<<endl;


}
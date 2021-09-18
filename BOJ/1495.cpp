#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, m, s;
  cin>>n>>s>>m;
  vector<int> arr(n,0);
  for(int i=0; i<n; i++)
    cin>>arr[i];
  vector<vector<bool> > DP(n+1, vector<bool>(1001,false));
  DP[0][s] = true;
  for(int i=0; i<n; i++){
    for(int j=0; j<=m; j++){
      if(DP[i][j]){
        if(j+arr[i] <=m){
          DP[i+1][j+arr[i]] = true;
        }
        if(j-arr[i] >=0){
          DP[i+1][j-arr[i]] = true;
        }
      }
    }
  }
  int ans = -1;
  for(int i=0; i<=m; i++){
    if(DP[n][i]){
      ans = i;
    }
  }
  // for(int i=0; i<=n ; i++){
  //   for(int j=0; j<=m; j++){
  //     cout <<DP[i][j]<<" ";
  //   }
  //   cout <<endl;
  // }

  cout << ans<<endl;
  return 0;
}
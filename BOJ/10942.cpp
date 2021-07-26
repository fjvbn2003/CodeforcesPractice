#include <iostream>
#include <vector>
using namespace std;
int dp[2001][2001];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin>>n;
  vector<int> arr(n, 0);
  for(int i=0; i<n; i++)
    cin>>arr[i];
  for(int i=0;i<n; i++)
    dp[i][i]  =1;
  for(int k=1; k<n; k++)
    for(int i=0, j=k; j<n; i++,j++){
      if(arr[j] != arr[i]) dp[i][j] = 0;
      else{
        bool flag = true;
        // for(int t = 1; t< k/2-1; t++){
        //   if(dp[i+t][j-t] ==0){
        //     flag = false;
        //     break;
        //   }
        // }
        if(j-i >2){
          if(dp[i+1][j-1] ==0)
            flag = false;
        }
        if(flag) dp[i][j] = 1;
        else dp[i][j]  = 0;
      }
    }
  
  // for(int i=0; i<n; i++){
  //   for(int j=0; j<n; j++)
  //     cout <<dp[i][j]<<" ";
  //   cout <<endl;
  // }
  cin>>m;
  int a,b;
  vector<int> ans(m,0);
  for(int i=0; i<m; i++){
    cin>>a>>b;
    ans[i] = dp[a-1][b-1];
  }
  for(int i=0; i<m; i++)
    cout <<ans[i]<<'\n';

}   
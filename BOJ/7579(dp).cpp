#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MAX = 100*100+1;
int dp[101][10002];


int main(){
  int n,m;
  vector<int> M,C;
  cin>>n>>m;
  int t;
  for(int i=0; i<n; i++){
    cin>>t;
    M.push_back(t);
  }
  for(int i=0; i<n; i++){
    cin>>t;
    C.push_back(t);
  }
  // dp table을 만든다. i번재 앱까지 사용해서, c의 cost를 사용할 때 만들 수 있는 최대 메모리를 저장
  for(int i=1; i<=n; i++){
    int c = C[i-1];
    for(int j=0; j<=10000; j++ ){
      if(c<=j){
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-c]+M[i-1]);
      }
      dp[i][j] = max(dp[i][j], dp[i-1][j]);
    }
  }
  // for(int i=0; i<=n; i++){
  //   for(int j=0; j<20; j++){
  //     cout <<dp[i][j]<<" ";
  //   }
  //   cout <<endl;
  // }
  int ans = 0;
  for(int i=0; i<=10000; i++){
    if(dp[n][i]>=m){
      ans = i;
      break;
    }
  }
  cout <<ans<<endl;
}
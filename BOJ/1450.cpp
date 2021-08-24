#include <iostream>
#include <vector>
using namespace std;

int main(){

  int n,c;
  cin>>n>>c;
  vector<int> arr(n,0);
  for(int i=0; i<n; i++)
    cin>>arr[i];

  //dp[i][j] i번 째 물건까지 고려했을 때 j 무게로 살 수 있는 방법의 수
  //dp[i][j] = max(dp[i-1][j], dp[i-1][j-arr[i]]+1
  //탐색공간이 너무 넓다. 
  // Meet in the middle을 사용해야 한다!
  

}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define ll long long
int main(){
  ll ans;
  ans = 4;
  int n;
  cin>>n;
  for(int i=2; i<=n; i++){
    // 이전 답에서 밑변 제거, 밑변 추가(i), 옆면(2), 윗면 추가(1).
    ans = (ans-(i-1)) + i + 2 +1;
  }
  cout <<ans<<endl;
  return 0;


}
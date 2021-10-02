#include <iostream>
#include <vector>

using namespace std;

int main(){

  int n, m;
  cin>>n>>m;
  int ans = 0;
  while(n){
    ans +=n;
    n /=m;
  }
  cout << ans<<endl;
  return 0;

}
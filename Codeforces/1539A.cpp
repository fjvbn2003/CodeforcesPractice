#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int test;
  long long n,x,t;
  cin>>test;
  while(test--){
    cin>>n>>x>>t;
    long long last_full = (n-1)*x - t;
    last_full  = last_full + t%x;
    last_full = max(0ll, last_full);
    long long ans = 0;
    long long k = t/x;
    k = min(n-1, k);
    ans += (k)*(last_full/x);
    ans += ((n- last_full/x)*(n- last_full/x -1))/2;
    cout <<ans<<endl;
  }
  return 0;
}
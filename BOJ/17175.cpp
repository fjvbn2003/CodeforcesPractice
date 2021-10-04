#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007
#define ll long long
int main(){
  int n;
  cin>>n;
  vector<ll> arr(51,0);
  arr[0] = 1;
  arr[1] = 1;
  for(int i=2; i<=n; i++){
    arr[i] = (arr[i-1]+arr[i-2]+1)%MOD;
  }
  cout << arr[n]<<endl;
  return 0;
}
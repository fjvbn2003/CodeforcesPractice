#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin>>n;
  vector<long long> arr(n, 0);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  long long ans = arr[n-1];
  for(int i=n-2; i>=0; i--){
    if(arr[i]>= ans){
      ans = arr[i];
    }else{
      if(ans%arr[i]==0){
        continue;
      }else{
        ans = arr[i]*(ans/arr[i] +1);
      }
    }
  }
  cout <<ans<<endl;
  return 0;
}
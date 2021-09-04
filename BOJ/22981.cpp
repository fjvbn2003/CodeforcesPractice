#include<iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

int main(){
  long double n, k;
  cin>>n>>k;
  vector<long double> arr(n,0);
  for(int i=0; i<n; i++){
      cin>>arr[i];
  }
  sort(arr.begin(), arr.end());
  long double v1,v2;
  long double ans = (long double)ceil(k/(v1+v2));
  for(int i=1; i<n; i++){
     v1 = arr[0]*i;
     v2 = arr[i]*(n-i);
     ans = min(ans, (long double)ceil(k/(v1+v2)));
  }
  cout <<(long long)ans<<endl;
  return 0;

}
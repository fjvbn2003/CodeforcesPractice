#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int test_case;
  cin>> test_case;
  long long n,l,r;
  while(test_case--){
    cin>>n>>l>>r;
    vector<long long> arr(n);
    for(long long i=0; i<n; i++){
      cin>> arr[i];
    }
    long long ans = 0;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-1; i++){
      long long diff = upper_bound(arr.begin()+i+1, arr.end(), r-arr[i])- lower_bound(arr.begin()+i+1, arr.end(), l-arr[i]);
      ans += diff;
    }
    cout <<ans<<endl;
  }
  return 0;

}
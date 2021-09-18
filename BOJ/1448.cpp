#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> arr;
  int t;
  for(int i=0; i<n; i++){
    cin>>t;
    arr.push_back(t);
  }
  sort(arr.begin(), arr.end());
  int ans =-1;
  for(int i=arr.size()-1; i>=2; i--){
    if(arr[i] <arr[i-1]+arr[i-2]){
      ans = max(ans,arr[i]+arr[i-1]+arr[i-2]);
    }
  }
  cout<<ans<<endl;
  return 0;

}

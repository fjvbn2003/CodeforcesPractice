#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n,s;
  cin>>n>>s;
  vector<int> arr(n,0);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int left = 0;
  int right = 0;
  // tmp = arr[left]+ arr[left+1]+ ... + arr[right]
  int tmp = 0;
  int ans = n+1;
  while(left<n){
    while(tmp<s && right <n){
      tmp+= arr[right];
      right++;
    }
    if(tmp>=s){
      ans = min(ans, right-left);
    }else{
      break;
    }

    tmp-= arr[left];
    left++;
  }
  if(ans == n+1){
    cout <<0<<endl;
    return 0;
  }
  cout <<ans<<endl;

}
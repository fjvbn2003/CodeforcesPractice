#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> arr(n,0);
  for(int i=0; i<n; i++)
    cin>> arr[i];
  sort(arr.begin(), arr.end());

  int left = 0;
  int right = n-1;
  int ans = 1e9 *2 +1;
  int ans_l, ans_r;
  
  while(left <right){
    if(ans > abs(arr[left]+arr[right])){
      ans = abs(arr[left]+arr[right]);
      if(arr[left]<arr[right]){
        ans_l = arr[left];
        ans_r = arr[right];
      }else{
        ans_l = arr[right];
        ans_r = arr[left];
      }
    }
    if(arr[left]+arr[right]<0)
      left++;
    else
      right--;
  }
  cout <<ans_l<<" "<<ans_r<<endl;
  return 0;
}
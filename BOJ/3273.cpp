#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
  int n,x;
  cin>>n;
  vector<int> arr(n,0);
  for(int i=0; i<n; i++ ){
    cin>> arr[i];
  }
  cin>>x;
  sort(arr.begin(), arr.end());
  int left = 0;
  int right = arr.size()-1;
  int ans = 0;
  while(left<right){
    if(arr[left]+arr[right]>x)
      right--;
    else if(arr[left]+arr[right]<x)
      left++;
    else{
      //cout<<left<<" "<<right<<endl;
      ans++;
      left++;
    }
  }
  cout <<ans<<endl;
}
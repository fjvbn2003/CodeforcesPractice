#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin>>n;
  vector<pair<int, int> > arr(n,pair<int,int>());
  for(int i=0; i<n; i++){
    cin>> arr[i].first>>arr[i].second;
  }
  sort( arr.begin(), arr.end());
  int start = arr[0].first;
  int end = arr[0].second;
  int ans = 0;
  for(int i=1; i<n; i++){
    if(arr[i].first > end){
      ans += (end-start);
      start = arr[i].first;
      end = arr[i].second;
    }else{
      end = max(end, arr[i].second);
    }
  }
  ans += (end-start);
  cout <<ans<<endl;
  return 0;
}
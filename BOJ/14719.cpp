#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int H, W;
  cin>>H>>W;
  vector<int> arr(W);
  for(int i=0; i<W; i++){
    cin>>arr[i];
  }
  int ans = 0;
  for(int i=0; i<W; i++){
    if(i==0 || i==W-1) continue;
    int left_high = 0;
    int right_high = 0;
    for(int j=i-1; j>=0; j--){
      if(arr[j]>arr[i] && left_high<(arr[j]-arr[i]))
        left_high = arr[j]-arr[i];
    }
    for(int j=i+1; j<W; j++){
      if(arr[j]>arr[i] && right_high<(arr[j]-arr[i]))
        right_high = arr[j]-arr[i];
    }
    //cout <<"in: "<<i<<" "<< left_high<<" "<<right_high<<endl;
    ans += min(left_high, right_high);
  }
  cout <<ans<<endl;
  return 0;

}
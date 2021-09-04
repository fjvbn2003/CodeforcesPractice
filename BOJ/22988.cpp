#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

int main(){
  long double N, X;
  cin>>N>>X;
  vector<long double> arr;
  vector<long double> ans;
  long double t;
  for(int i=0; i<N; i++){
    cin>>t;
    if(t>=X) ans.push_back(t);
    else{
      arr.push_back(t);
    }    
  }
  int cnt = 0;
  sort(arr.begin(), arr.end());
  int left = 0;
  int right = arr.size()-1;
  while(left <right){
    while(left <N && arr[right]+arr[left] < X/2){
      left++;
    }
    if(left>=right) break;
    else{
      left++;
      right--;
      cnt++;
    }
  }
  cnt += max(0, (int)((arr.size()-2*cnt)/3));
  cnt += ans.size();
  cout <<cnt<<endl;
  return 0;
}
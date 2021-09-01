#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> arr(n,0);
  for(int i=0; i<n; i++)
    cin>> arr[i];
  int ans = 0;
  for(int i=0; i<n; i++){
    int cnt = 0;
    // 왼쪽으로 보기.
    double max_incle = -1000000001.0;
    for(int j=i-1; j>=0; j--){
      if(double(arr[j]-arr[i])/(i-j)>max_incle){
        max_incle =double(arr[j]-arr[i])/(i-j);
        // cout <<"i, j: "<<i<<" "<<j<<" max_incle: "<<max_incle<<endl;
        cnt++;
      }
    }
    max_incle = -1000000001.0;
    // 오른쪽으로 보기.
    for(int j=i+1; j<n; j++){
      if(double(arr[j]-arr[i])/(j-i)>max_incle){
        max_incle =double(arr[j]-arr[i])/(j-i);
        // cout <<"i, j: "<<i<<" "<<j<<" max_incle: "<<max_incle<<endl;
        cnt++;
      }
    }
    if(cnt > ans){
      ans = cnt;
    }
  }
  cout <<ans<<endl;

}
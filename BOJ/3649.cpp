#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> arr;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(1){
    long long width;
    if(cin>> width){
          width*=1e7;
    long long n;
    cin>>n;
    arr.clear();
    arr.resize(n,0);
    for(long long i=0; i<n; i++)  
      cin>>arr[i];
    sort(arr.begin(), arr.end());
    long long left = 0;
    long long right = n-1;
    long long ans_left = 0;
    long long ans_right = n-1;
    bool flag = false;
    while(left<right){
      //cout <<width<<" "<< arr[left]+arr[right]<<endl;
      if(arr[left]+arr[right] == width){
        ans_left = arr[left];
        ans_right = arr[right];
        flag = true;
        break;
      }else if(arr[left]+arr[right] <width){
        left++;
      }else if(arr[left]+arr[right] >width){
        right--;
      }
    }
    if(flag){
      cout <<"yes "<<ans_left<<" "<<ans_right<<endl;
    }else{
      cout <<"danger"<<endl;
    }
    }else{
      break;
    }

  }
}
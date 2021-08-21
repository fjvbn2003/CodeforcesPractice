#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int test_case;
  cin>>test_case;
  vector<long long> arr;
  long long i = 1;
  long long add =2;
  arr.push_back(1);
  while(true){
    i+= add;
    arr.push_back(i);
    if(i>1e10) break;
    add+=2;
  }
  while (test_case--){
    long long t;
    cin>>t;
    int idx = lower_bound(arr.begin(), arr.end(), t)  - arr.begin();
    // 2개를 살핀다.
    if(arr[idx] == t){
      cout <<idx+1<<" "<<idx+1<<endl;
    }else{
      long long diff = t-arr[idx];
      //arr[idx]~arr[idx+1] 사이에 정답이 있다.
      if(diff < idx){

      }
    }
  }
    

}
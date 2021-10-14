#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int test_case;
  cin>> test_case;
  while(test_case--){
    vector<int> arr(3);
    int maxi = -1;
    int cnt = 0;
    for(int i=0; i<3; i++){
      cin>> arr[i];
      maxi = max(maxi, arr[i]);
    }
    for(int i=0; i<3; i++){
      if(arr[i] ==  maxi){
        cnt++;
      }
    }
    for(int i=0; i<3; i++){
      if(arr[i] ==  maxi){
        if(cnt>1){
          cout <<1<<" ";
        }else{
          cout << 0<<" ";
        }
      }else{
        cout << maxi-arr[i]+1<<" ";
      }
    }
    cout <<endl;

  }
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> arr(1000+2, 0);
  arr[1] = 1;
  arr[2] = 0;
  arr[3] = 1;
  arr[4] = 1;
  arr[5] = 1;
  arr[6] = 1;
  for(int i=7; i<1002; i++){
    if(arr[i-1]==0 || arr[i-3]==0 || arr[i-4]==0){
      arr[i] = 1;
    }else{
      arr[i] = 0;
    }
  }
  if(arr[n]==1){
    cout <<"SK"<<endl;
  }else{
    cout << "CY"<<endl;
  }
  

  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int test_case;
  cin>>test_case;
  vector<int> arr;
  for(int i=1; i<1000000; i++){
    if(i%3 ==0 || i%10 ==3) continue;
    else{
      arr.push_back(i);
    }
  }
  
  while(test_case--){
    int n;
    cin>> n;
    cout <<arr[n-1]<<'\n';
  }
  return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
// Greedy
int main(){
  int test_case;
  cin>> test_case;
  while(test_case--){
    int n;
    cin>>n;
    vector<char> arr(n);
    for(int i=0; i<n; i++){
      cin>> arr[i];
    }
    string s = "";
    for(int i=0; i<n; i++){
      if(s+arr[i] <= arr[i]+s){
        s = s+arr[i];
      }else{
        s = arr[i]+s;
      }
    }
    cout << s<<endl;
  }
  return 0;

}
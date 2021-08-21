#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
  vector<int> arr(3,0);
  for(int i=0; i<3; i++)
    cin>>arr[i];
  sort(arr.begin(), arr.end());
  string s;
  cin>>s;
  for(int i=0; i<s.size(); i++){
    if(s[i] == 'A') cout <<arr[0]<<" ";
    else if(s[i] =='B') cout <<arr[1]<<" ";
    else cout <<arr[2]<<" ";
  } 
  cout <<endl;
  return 0;

}
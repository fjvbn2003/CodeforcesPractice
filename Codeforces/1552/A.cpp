#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  int test_case;
  int t;
  string s;
  cin>>test_case;
  while(test_case--){
    cin>>t;
    cin>>s;
    string ss = s;
    sort(s.begin(), s.end());
    int cnt = 0;
    for(int i=0; i<t; i++){
      if(s[i]!=ss[i]){
        cnt++;
      }
    }
    cout <<cnt<<endl;
  }
}
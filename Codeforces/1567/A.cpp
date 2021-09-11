#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  cout.tie(0);
  cin.tie(0);
  ios::sync_with_stdio(false);

  int test_case;
  cin>>test_case;
  while(test_case--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0; i<n; i++){
      if(s[i]=='U'){
        cout <<'D';
      } else if(s[i]=='D'){
        cout <<'U';
      }else{
        cout <<s[i];
      }
    }
    cout <<endl;
  }
}
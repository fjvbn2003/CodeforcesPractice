#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int  main(){
  int test_case;

  cin>>test_case;
  while(test_case--){
    int a,b,c;
    cin>>a>>b>>c;
    int rad = abs(a-b)-1;
    bool impossible = false;
    if(rad<1) impossible = true;
    if(rad+1<min(a,b)) impossible = true;
    if(impossible){
      cout <<-1<<'\n';
    }else{
      int circle = rad*2+2;
      if(c> circle){
        cout << -1<<'\n';
        continue;
      }
      int ans = (c+rad)%circle +1;
      cout <<ans<<'\n';
    }
  }
  return 0;
}
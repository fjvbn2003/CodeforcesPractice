#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int test_case;
  cin>> test_case;
      int xf,yf;
      int xa,ya,xb,yb;

  while(test_case--){
    cin>> xa>>ya>>xb>>yb>>xf>>yf;
    int ans = abs(xa-xb)+abs(ya-yb);
    if(xa == xb && xa == xf){
      //cout <<"hi"<<endl;
        if((ya <yf && yf <yb)||(ya >yf && yf >yb)){
          ans+=2;
        }
    }
    if(ya==yb && ya == yf){
      if((xa<xf && xf<xb)||(xa>xf && xf>xb)){
        ans+=2;
      }
    }
    cout <<ans<<endl;
    

  }

  return 0;
}
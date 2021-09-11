#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
unsigned int arr[300009];
int main(){
  int test_case;
  cout.tie(0);
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin>>test_case;
  arr[0] = 0;
  for(int i=1;i<300009; i++){
    arr[i] = (arr[i-1]^i);
  }
  // for(int i=0; i<10; i++){
  //   cout << arr[i]<<" ";
  // }
  cout <<endl;
  while(test_case--){
    int a,b;
    int xo =0;
    int ans = 0;
    cin>>a>>b;
    ans+=a;
    xo = arr[a-1];
    // cout <<"xo"<<xo<<endl;
    // cout <<"xo^b"<<(xo^b)<<endl;
    if(xo == b){
      cout << ans<<'\n';
    }else{
      if((xo^b) == a){
        cout << ans+2<<'\n';
      }else{
        cout <<ans+1<<'\n';
      }
    }

  }
}
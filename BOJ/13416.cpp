#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int test_case;
  int t;
  cin>>test_case;
  while(test_case--){
    int n;
    cin>>n;
    int ans = 0;
    for(int i=0; i<n; i++){
      int maxi = 0;
      for(int j=0; j<3; j++){
        cin>>t;
        maxi = max(t, maxi);
      }
      ans += maxi;
    }
    cout <<ans<<endl;
  }
      return 0;
  
}
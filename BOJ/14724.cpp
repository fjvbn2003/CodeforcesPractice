#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(){
  vector<string> circles = {"PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY"};
  int n;
  cin>>n;
  int maxi = -1;
  int maxi_idx  =0;
  int t;
  for(int i=0; i<9; i++){
    for(int j=0; j<n; j++){
      cin>>t;
      if(maxi<t){
        maxi = t;
        maxi_idx = i;
      }
    }
  }
  cout<< circles[maxi_idx]<<endl;
  return 0;

}
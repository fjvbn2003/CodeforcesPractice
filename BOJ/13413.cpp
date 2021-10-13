#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int T;
  cin>>T; 
  while(T--){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int black = 0;
    int white = 0;
    for(int i=0; i<n; i++){
      if(a[i] != b[i]){
        if(a[i] == 'B')
         black++;
        else white++;
      }
    }
    cout << max(black,white)<<endl;

  }
  return 0;

}
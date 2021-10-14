#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, K;
  cin>>N>>K;
  string s;
  int maxi = -1;
  for(int i=1; i<=K; i++){
    s = to_string(N*i);
    reverse(s.begin(), s.end());
    maxi = max(maxi, stoi(s));
  }
  cout <<maxi<<endl;
  return 0;


}
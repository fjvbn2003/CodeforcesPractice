#include <iostream>
#include <vector>

using namespace std;

int main(){

  long long n;
  cin>>n;
  int cnt = 0;
  for(long long i=1; i*i<=n; i++){
    cnt++;
  }
  cout <<cnt<<endl;
  return 0;

}
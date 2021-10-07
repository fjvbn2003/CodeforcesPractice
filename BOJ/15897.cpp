#include <iostream>
using namespace std;


int main(){
  long long n;
  long long ans = 0;
  cin>>n;
  for(long long i=1; i<=n; i++){
    ans += n/i;
    if(n%i) ans+=1;
  }
  cout <<ans<<endl;
  return 0;

}
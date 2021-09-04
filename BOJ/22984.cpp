#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<long double> arr(n,0);
  for(int i=0 ; i<n; i++)
    cin>>arr[i];
  long double ans = arr[0];
  for(int i=1; i<n; i++){
    ans+= arr[i];
    ans += (1- arr[i-1])*arr[i];
    ans += (arr[i-1])*(1-arr[i]);
  }
  cout.precision(9);
  cout.fixed;
  cout<<ans<<endl;
  return 0;


}
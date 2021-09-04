#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<double> arr(n, 0);
  for(int i=0; i<n; i++)
    cin>> arr[i];
  double ans = 0;
    ans += 2*(arr[0])*(arr[1]);
    ans += 2*(1-arr[0])*(arr[1]);
    ans += 2*(arr[0])*(1-arr[1]);
  double t = (double)4/3;
  for(int i=1; i<n-1; i++){
    ans += t*(arr[i])*(arr[i+1]);
    ans += t*(1-arr[i])*(arr[i+1]);
    ans += t*(arr[i])*(1-arr[i+1]);
    cout<<ans<<endl;
  }
  cout.precision(2);
  cout.fixed;
  cout <<ans<<endl;

}
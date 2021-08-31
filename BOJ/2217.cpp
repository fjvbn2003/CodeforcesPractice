#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> arr(n,0);
  for(int i=0; i<n; i++) 
    cin>> arr[i];
  sort(arr.begin(), arr.end());
  long long maxi = arr[n-1];
  for(int i=n-2; i>=0; i--){
    maxi = max(maxi, (long long)arr[i]*(n-i));
  }
  cout <<maxi<<endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
  long long n,k,x;
  cin>>n>>k>>x;
  vector<long long> arr(n);
  for(long long i=0ll; i<n; i++)
    cin>> arr[i];

  sort(arr.begin(), arr.end());
  vector<long long> slice;
  long long cnt = 1ll;
  for(long long i=1ll; i<n; i++)
    if(arr[i]-arr[i-1]>x){
      cnt++;
      slice.push_back(arr[i]-arr[i-1]);
    }
  sort(slice.begin(), slice.end());
  for(long long i=0; i<slice.size(); i++){
    long long need = slice[i]/x;
    if(slice[i]%x ==0) need--;
    if(k>=need){
      cnt--;
      k-=need;
    }else{
      break;
    }
  }
  cout <<cnt<<endl;
  return 0;
}
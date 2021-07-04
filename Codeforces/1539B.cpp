#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  //range query
  int n ,q;
  string s;
  cin>>n>>q;
  cin>> s;
  int l, r;
  vector<long long> arr(n,0);
  arr[0] = (s[0]-'a')+1;
  for(int i=1; i<n; i++){
    arr[i] = arr[i-1]+(s[i]-'a'+1);
  }
  while(q--){
    cin>>l>>r;
    long long ans = 0;
    if(l==1){
       ans = arr[r-1];
    }else{
      ans = arr[r-1] - arr[l-2];
    }
    cout << ans<<endl;
  }
return 0;

}
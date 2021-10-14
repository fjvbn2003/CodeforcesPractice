#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
long long gcd(int  a, int b){
  if(a<b){
    swap(a,b);
  }
  while(b !=0){
    int t = a%b;
    a = b;
    b = t;
  }
  return a;
}
int main(){
  int test_case;
  cin>> test_case;
  while(test_case--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
      cin>> arr[i];
    set<int> st;
    for(int i=0; i<n; i++)
      for(int j=i+1; j<n; j++){
        if(arr[i] == arr[j]) continue;
        st.insert(abs(arr[i]- arr[j]));
      }
        
    int ans= *st.begin();
    for(int s : st){
      //cout <<s<<endl;
      gcd(s, ans);
    }
    if(ans == 0){
      cout <<-1<<endl;
    }else{
      cout <<ans<<endl;
    }
  }
  return 0;
}
#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
  fio;
  int test_case;
  cin>> test_case;
  while (test_case--)
  {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    vector<int> tmp(n,0);
    for(int i=0; i<n; i++){
        cin>> arr[i];
        tmp[i] = arr[i];
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    unordered_map<int,int> mp;
    for(int i=0; i<tmp.size(); i++){
      mp.insert({tmp[i], i});
    }
    int cnt = 0;
    for(int i=1; i<arr.size(); i++){
      if(arr[i-1]<arr[i] && mp[arr[i-1]]+1== mp[arr[i]]){
        cnt++;
      }else{
        continue;
      }
    }
    if(cnt+k >= n){
      cout <<"YES"<<"\n";
    }else{
      cout <<"NO"<<"\n";
    }
  }
  
}
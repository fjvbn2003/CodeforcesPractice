#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll dp[200001];
ll sqr(ll x){
  if(dp[x]>0){
    return dp[x];
  }
  return dp[x] = x*x;
}

int main(){
  fio;
  int test_case;
  cin>>test_case;
  for(int t=1; t<=test_case; t++){
    ll R;
    cin>>R;
    ll cnt = 0ll;
    ll Rs = R*R;
    ll mem = R-1;
    for(ll i=1; i<R; i++){
      for(ll j=mem; j>0; j--){
          if(Rs > ((dp[i]>0)?dp[i]:sqr(i))+((dp[j]>0)?dp[j]:sqr(j))){
              cnt += j;
              mem = j;
              break;
          }
      }
    }
    cout <<"Case #"<<t<<'\n';
    cout << cnt*4 + (R-1)*4 +1<<'\n';
  }
  return 0;


}
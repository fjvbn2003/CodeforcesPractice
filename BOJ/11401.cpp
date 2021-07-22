#include <iostream>
#include <vector>
#include <unordered_map>
//map에 key로 nCk값을 저장.
// nCk = n-1Ck-1+n-1Ck
using namespace std;
using ll=long long;
ll MOD = 1e9+7ll;
ll factorial(ll a){
  ll ret = 1;
  for(ll i=1; i<=a; i++){
    ret*=i;
    ret%=MOD;
  }
  return ret;
}
ll power(ll a, ll p){
  if(p==0) return 1ll;
  if(a==1) return 1ll;
  if(p%2){
    return power(a%MOD, p-1)*a%MOD;

  }else{
    ll t = power(a%MOD,p/2)%MOD;
    return (t*t)%MOD;
  }

}
int main(){
  ll n,k;
  cin>>n>>k;
  ll ans = factorial(n)%MOD;
  ans = ans* power(factorial(n-k)*factorial(k)%MOD, MOD-2);
  ans = ans%MOD;
  cout <<ans<<endl;
  return 0;
}

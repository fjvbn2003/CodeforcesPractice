#include <iostream>
#include <vector>
using namespace std;
using ll= long long;
ll MOD = 1000000007;
typedef vector<vector<ll> > mat;
mat operator * (const mat& a,const mat& b) {
    int n = 2;
    mat c(2, vector<ll>(2));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= MOD;
            }
            c[i][j] %= MOD;
        }
    }
    return c;
}
mat mul(ll n){
  if(n==1) {
    return init;
  }
  mat t;
  if(n%2 == 0){
    t = mul(n/2);
    return t*t;
  }
  else{
    t = mul(n-1);
    return t*init;
  }
}
int main(){
  ll n;
  cin>>n;
  init[0][1] = 1;
  init[1][1] = 1;
  init[1][0] = 1;
  mat ans = mul(n-1);
  cout <<ans[1][1]%MOD<<endl;
}
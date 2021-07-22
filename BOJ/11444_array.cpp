#include <iostream>
using namespace std;
using ll= long long;
ll MOD = 1000000007;
struct mat{
  mat(){
    for(int i=0; i<2; i++)
      for(int j=0; j<2; j++)
        m[i][j] = 0;
  }
  mat(int t){
    m[0][0] = 0;
    m[1][0] = 1;
    m[0][1] = 1;
    m[1][1] = 1;
  }
  ll m[2][2];
};
mat init = mat(1);
mat* operator * (const mat& a,const mat& b) {
    int n = 2;
    mat* c = new mat;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c->m[i][j] += a.m[i][k] * b.m[k][j];
                c->m[i][j] %= MOD;
            }
            c->m[i][j] %= MOD;
        }
    }
    return c;
}

mat& mul(ll n){
  if(n==1) {
    return init;
  }
  mat t;
  if(n%2 == 0){
    t = mul(n/2);
    mat* tt = new mat;
    tt = (t*t);
    return *tt;
  }
  else{
    t = mul(n-1);
    mat* tt = new mat;
    tt = (init*t);
    return *tt;
  }
}
int main(){
  ll n;
  cin>>n;

  mat ans = mul(n-1);
  cout <<ans.m[1][1]%MOD<<endl;
}
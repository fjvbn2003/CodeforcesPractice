#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
/*
문제: 조합 0의 개수(2004번)
아이디어: nCm을 팩토리얼 표기식으로 바꾼 뒤에 그 숫자들에 포함된 2인자와 5인자의 갯수를 통해서 0의 개수를 구할 수 있다.
0은 2*5와 관련있기 때문이다.
*/
int main(){
  ll n,m;
  cin>>n>>m;
  ll two = 0;
  ll five = 0;
  for(ll i=2; i<=n; i*=2) two += n/i;
  for(ll i=5; i<=n; i*=5) five += n/i;
  
  for(ll i=2; i<=n; i*=2) two -= m/i;
  for(ll i=5; i<=n; i*=5) five -= m/i;

  for(ll i=2; i<=n; i*=2) two -= (n-m)/i;
  for(ll i=5; i<=n; i*=5) five -= (n-m)/i;

  cout <<min(two, five)<<endl;
  return 0;
  
}
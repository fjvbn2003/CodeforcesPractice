#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N= 50000;
bool isPrime[N];
vector<int> primes;

void precalc(){
  fill(isPrime+2, isPrime+N, true);
  for(int i=2; i*i<N; i++){
    for(int j=i*i ; j<N; j+=i){
      isPrime[j] = false;
    }
  }
  for(int i=2; i<N; i++){
    if(isPrime[i]){
      primes.push_back(i);
    }
  }
}
int calcPrime(int n){
  int res = 0;
  for (int i : primes){
    if(i*i >n) break;
    while(n%i == 0){
      n/=i;
      res++;
    }
  }
  if(n>1){
    res++;
  }
  return res;
}
map<int, int> decompose(int n){
  map<int, int> a;
  for(int i: primes){
    if(i*i >n){
      break;
    }
    int p = 0;
    while(n%i ==0){
      n/=i;
      p++;
    }
    if(p>0){
      a[i] = p;
    }
  }
  if(n>1){
    a[n] = 1;
  }
  return a;
}
bool check(const map<int, int> &divs,
  map<int, int>::const_iterator it,
  map<int, int> &divsA,
  map<int, int> &divsB,
  int low,
  int high,
  int k
){
  if(it == divs.end()){
    return __builtin_popcount(low <=k && k<=high);
  }
}
int main(){


}
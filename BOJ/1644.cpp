#include <iostream>
#include <vector>

using namespace std;
int main(){
  
  int n;
  cin>>n;
  vector<bool> not_prime(n+1, false);
  not_prime[1] = true;
  // for(int i=1; i<=n; i++){
  //   cout <<not_prime[i]<<" ";
  // }
  for(int i=4; i<=n; i+=2){
    not_prime[i] = true;
  }
  for(int i=3; i*i<= n; i++){
    if(not_prime[i] == false){
      //cout <<"hi: "<<i<<endl;
      for(int k=i*i; k<=n; k+=i){
        not_prime[k] = true;
        //cout<<"kk: "<<k<<endl;
      }
    }
  }
  vector< int> primes;
  for(int i=2; i<=n; i++){
    if(!not_prime[i]){
      primes.push_back(i);
    }
  }
  vector<long long> accu;
  accu.push_back(0);
  for(int i=0; i<primes.size(); i++){
    accu.push_back(accu.back()+(long long)primes[i]);
  }
  int cnt = 0;
  for(int i=0; i<accu.size(); i++){
    for(int j=i+1; j<accu.size(); j++){
      if(accu[j]-accu[i] >n) break;
      if(accu[j]-accu[i] == n){
        cnt++;
        //cout<<i<<" "<<j<<endl;
      }
    }
  }

  cout <<cnt<<endl;
  // for(int i=0; i<primes.size(); i++){
  //   cout<<primes[i]<<" ";
  // }
  // cout <<endl;
  // for(int i=0; i<accu.size(); i++){
  //   cout<<accu[i]<<" ";
  // }
  // cout <<endl;
  return 0;
}
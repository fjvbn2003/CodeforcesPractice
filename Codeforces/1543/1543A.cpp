# include <iostream>
# include <algorithm>
using namespace std;
long long gcd(long long a, long long b){
  if(a>b) swap(a,b);
  while(a != 0){
    long long t = b%a;
    b = a;
    a = t;
  }
  return b;
}

int main(){
  int test_case;
  cin>>test_case;
  long long a,b;
  long long g;
  long long alpha, beta, new_gcd;
  while(test_case--){
    cin>>a>>b;
    g = gcd(a,b);
    alpha = a/g;
    beta = b/g;
    new_gcd = g*(labs(alpha-beta));
    cout << new_gcd<<" "<< max(min(a%new_gcd,new_gcd-a%new_gcd),0ll)<<endl;

  } 
  return 0;

}
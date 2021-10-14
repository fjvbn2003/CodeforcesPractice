#include <iostream>
#include <set>
#include <cmath>
using namespace std;


long long GCD(long long a, long long b){
  if(b==0) return a;
  return GCD(b, a%b);
}

int main(){
  int test_case;
  cin>> test_case;

  while(test_case--){
    long long n;
    cin>>n;
    int result = 0;
    //소인수분해
    for(long long i=1; i*i<=n; i++){
      if(n%i !=0 ) continue;
      if(GCD(i, n/i)==1){
        result++;
      }
    }
    cout << result<<endl;
  }
  return 0;

}

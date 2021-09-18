#include <iostream>
#include <vector>

using namespace std;
# define MOD 1000000007LL
int main(){
  int test_case;
  cin>> test_case;
  vector<long long> arr(5001, 0);
  arr[0] = 0;
  arr[1] = 0;
  arr[2] = 2;
  for(int i=3; i<5001; i++){
    if(i%2 ==1) continue;
    arr[i] = arr[i-2]*2;
    arr[i]%=MOD;
  }
  
  
  while(test_case--){
    long long n;
    cin>>n;
    if(n%2 == 1){
      cout << 0<< endl;
    }
    else{
      cout << arr[n]<<endl;
    }
  }
  return 0;

}
#include <iostream>
#include <vector>
#define MOD 1000000000LL
using namespace std;

int main(){
  int n, k;
  cin>> n>>k;
  vector< vector<long long> > arr(n+1, vector<long long>(k+1, 0));
  for(int i=0; i<=k; i++)
    arr[0][i] = 1;
  for(int i=0; i<=n; i++)
    arr[i][1] = 1;
  for(int i=1; i<=n; i++){
    for(int j=2; j<=k; j++){
      arr[i][j] = (arr[i-1][j]+arr[i][j-1])%MOD;
    }
  }
  // for(int i=0; i<=n; i++){
  //   for(int j=0; j<=k; j++){
  //     cout <<arr[i][j]<< " ";
  //   }
  //   cout <<endl;
  // }
  cout << arr[n][k]%MOD<<endl;

}
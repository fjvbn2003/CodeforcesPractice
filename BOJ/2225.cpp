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
      long long t = 0;
      for(int l=0; l<=i; l++){
        t += arr[l][j-1];
        t = t%MOD;
      }
      arr[i][j] = t;
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
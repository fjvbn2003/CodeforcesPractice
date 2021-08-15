#include <iostream>
#include <vector>
#include <algorithm>
#define fio                    \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
using namespace std;
int main(){
  fio;
  long long test_case;
  cin>> test_case;
  while(test_case--){
    long long n;
    cin>> n;
    vector<long long> arr(n+1, 0);
    vector<long long> ans(n+1, 0);

    for(long long i=1; i<=n; i++)
      cin>>arr[i];
    long long real_ans = 1e9+1;

    for(long long l=1; l<=n; l++){
      for(long long r=l+1; r<=n; r++){
        for(long long i=1; i<=n; i++)
          ans[i] = arr[i];

        for(long long i=0; i<=n; i++){
          if(l+i <=n && r-i >=0)
            ans[l+i] = arr[l+i]&arr[r-i];
        }
        long long maxi = ans[1];

        for(long long i=1; i<=n; i++){
          if(maxi< ans[i])
              maxi = ans[i];
        }
        // cout <<"l: "<<l <<" r: "<<r<<endl;
        // for(int i=1; i<=n; i++){
        //   cout << ans[i]<<" ";
        // }
        // cout <<endl;

        if(real_ans>maxi){
          real_ans = maxi;
        }

      }
    }
    cout <<real_ans<<'\n';
  }
  return 0;
}
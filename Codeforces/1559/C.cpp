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
  int test_case;
  cin>> test_case;
  while(test_case--){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0; i<n;i++){
      cin>> arr[i];
    }
    if(arr[0]==1){
      cout <<n+1<<" ";
      for(int i=1; i<=n; i++)
        cout<<i<<" ";
      cout<<'\n';
    }else if(arr[n-1]==0){
      for(int i=1; i<=n+1; i++)
        cout <<i<<" ";
      cout <<'\n';
    }else{
      int check_idx = 0;
      int check = false;
      for(int i=0; i<n-1; i++){
        if(arr[i]==0 && arr[i+1]==1){
          check = true;
          check_idx = i;
        }
      }
      if(check){
        for(int i=0; i<=check_idx; i++)
          cout << i+1<<" ";
        cout <<n+1<<" ";
        for(int i=check_idx+1; i<n; i++)
          cout <<i+1<<" ";
        cout <<'\n';
      }else{
        cout <<-1<<'\n';
      }

    }
  }  
  return 0;
}
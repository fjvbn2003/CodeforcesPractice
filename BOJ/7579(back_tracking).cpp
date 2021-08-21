#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n,m;
vector<int> C;
vector<int> M;
int ans = 1e9;
void bf(int idx, int sum_m, int sum_c){
  if(idx>n) return;
  if(idx==n){
    if(sum_m>=m){
      if(ans >sum_c) {
        ans = sum_c;
        return;
        }
      else
       return;
    }
  }
  bf(idx+1, sum_m, sum_c);
  sum_m += M[idx];
  sum_c += C[idx];
  if(sum_c >=ans) return;
  if(sum_m >=m){
    if(ans > sum_c){
      ans = sum_c;
      return;
    }
    return;
  }
  bf(idx+1, sum_m, sum_c);
}

int main(){
  cin>>n>>m;
  int t;
  for(int i=0; i<n; i++){
    cin>>t;
    M.push_back(t);
  }
  for(int i=0; i<n; i++){
    cin>>t;
    C.push_back(t);
  }
  bf(0,0,0);
  cout <<ans<<endl;
}
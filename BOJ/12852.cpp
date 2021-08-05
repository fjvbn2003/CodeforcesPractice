#include <iostream>
#include <vector>

using namespace std;
vector<int> dp(1e6+1, 1e9);
vector<int> parent(1e6+1,-1);
int find(int n){
  if(n==1) return 0;
  int& ret = dp[n];
  if(ret !=1e9) return ret;
  else{
    if(n%3 ==0){
       int cand = find(n/3)+1;
       if(cand <ret){
         ret = cand;
         parent[n] = n/3;
       }

    }
    if(n%2 ==0){
       int cand = find(n/2)+1;
       if(cand <ret){
         ret = cand;
         parent[n] = n/2;
       }
       
    }
    if(n>1){
       int cand = find(n-1)+1;
       if(cand <ret){
         ret = cand;
         parent[n] = n-1;
       }
    }
  }
  return ret;
}
int main(){
  int n;
  cin>>n;
  vector<int> ans;
  ans.push_back(n);
  dp[1] = 0;
  parent[1] = 1;
  dp[2] = 1;
  parent[2] = 1;

  
  cout <<find(n)<<endl;
  int t = n;
  cout <<n<<" ";
  while(t!=1){
    cout <<parent[t]<<" ";
    t = parent[t];
  }
  cout <<endl;
}
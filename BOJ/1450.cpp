#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<int> arr;
vector<long long> cand;
long long n,c,t;
long long ans = 0;
void print_arr(vector<long long> & arr){
  for(auto t : arr)
  {
    cout << t<<" ";
  }
  cout <<endl;
  return ;
}

int dfs(int start, int end, long long s){
  if(start==end){
    cand.push_back(s);
    return 0;
  }
  dfs(start+1, end, s);
  dfs(start+1, end, s+arr[start]);
  return 0;
}
int dfs2(int start, int end, long long s){
  if(start==end){
    if(s>c) return 0;
    else{
      long long remain  = c-s;
      ans += upper_bound(cand.begin(), cand.end(), remain)-cand.begin();
      return 0;
    }
  }
  dfs2(start+1, end, s);
  dfs2(start+1, end, s+arr[start]);
  return 0;
}
int main(){
  cin>>n>>c;
  for(int i=0; i<n; i++){
    cin>>t;
    arr.push_back(t);
  }
  dfs(0, n/2, 0);
  //print_arr(cand);
  sort(cand.begin(), cand.end());
  dfs2(n/2, n, 0);
  //print_arr(cand);

  cout << ans<<endl;
  return 0;
}
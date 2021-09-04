#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N;
long long dp[11];
vector<pair<int, pair<int, int> >> graph[11];
long long gcd(long long a, long long b);
void dfs(int x, int p);
int main(){
  cin>>N;
  long long lcm = 1;
  for(int i=0; i<N-1; i++){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    graph[a].push_back({b, {c,d}});
    graph[b].push_back({a, {d,c}});
    lcm *= (c*d/ gcd(c,d));
  }
  dp[0] = lcm;  dfs(0,-1);


  long long global = dp[0];
  for(int i=1; i<N; i++){
    if(dp[i] ==0) continue;
    global = gcd(global, dp[i]);
  }
  for(int i=0; i<N; i++)
    cout <<dp[i]/global<<" ";
  cout <<endl;
  return 0;
}

long long gcd(long long a, long long b){
  if(a<b){
    swap(a,b);
  }
  while(b !=0){
    long long t = a%b;
    a = b;
    b = t;
  }
  return a;
}

void dfs(int x, int p){
  for(auto n : graph[x]){
    if(n.first == p) continue;
    dp[n.first] = (dp[x] * (long long)n.second.second)/(long long)n.second.first;
    dfs(n.first, x);
  }
  return;
}
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<tuple<int,int,long long > > edges;
  vector<long long> distance(n+1, 1e18);
  int a,b,c;
  for(int i=0; i<m; i++){
    cin>>a>>b>>c;
    edges.push_back(make_tuple(a,b,c));
  }
  distance[1] = 0;
  for(int i=1; i<=n-1; i++){
    for(auto e : edges){
      long long a,b,w;
      tie(a,b,w) = e;
      if(distance[a] == 1e18) continue;
      distance[b] = min(distance[b], distance[a]+w);
    }
    // for(int i=1; i<=n; i++){
    //   cout <<distance[i]<<" ";
    // }
    // cout <<endl;
  }
  bool nagative_cycle = false;
  for(auto e : edges){
    long long a,b,w;
    tie(a,b,w) = e;
    if(distance[a] == 1e18) continue;

    if(distance[a]+w <distance[b]){
      nagative_cycle = true;
      break;
    }
  }
  if(nagative_cycle){
    cout << -1<<endl;
  }else{
    for(int i=2; i<=n; i++){
      if(distance[i]==1e18){
        cout <<-1<<endl;
        continue;
      }
      cout <<distance[i]<<endl;
    }
  }
  return 0;

}

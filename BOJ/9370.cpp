#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);  
  int test_case;
  cin>> test_case;

  while(test_case--){
    int n,m,t, s,g,h,a,b,d;
    cin>> n>>m>>t;
    cin>> s>>g>>h;
    vector<vector<pair<int, int> > >arr(n+1, vector<pair<int, int> >());
    for(int i=0; i<m; i++){
      cin>>a>>b>>d;
      arr[a].push_back({b,d});
      arr[b].push_back({a,d});
    }
    // t를 담는 배열
    vector<int> ts(t,0);
    for(int i=0; i<t; i++)
      cin>> ts[i];
    
    // priority queue로 다익스트라 최단 거리를 구한다. s->others
    priority_queue<pair<int, int> > pq;
    vector<int> dist(n+1, 1e9);
    pq.push({0, s});
    while(!pq.empty()){
      int cost = -(pq.top().first);
      int node = pq.top().second;
      pq.pop();
      if(dist[node]> cost){
        dist[node] = cost;
        for(int i=0; i<arr[node].size(); i++){
          pq.push(make_pair(-(cost + arr[node][i].second), arr[node][i].first));
        }
      }
    }
    // g->others
    vector<int> dist_g(n+1, 1e9);
    pq.push({0,g});
    while(!pq.empty()){
      int cost = -(pq.top().first);
      int node = pq.top().second;
      pq.pop();
      if(dist_g[node]> cost){
        dist_g[node] = cost;
        for(int i=0; i<arr[node].size(); i++){
          pq.push(make_pair(-(cost + arr[node][i].second), arr[node][i].first));
        }
      }
    }
    // h->others
    vector<int> dist_h(n+1, 1e9);
    pq.push({0,h});
    while(!pq.empty()){
      int cost = -(pq.top().first);
      int node = pq.top().second;
      pq.pop();
      if(dist_h[node]> cost){
        dist_h[node] = cost;
        for(int i=0; i<arr[node].size(); i++){
          pq.push(make_pair(-(cost + arr[node][i].second), arr[node][i].first));
        }
      }
    }
    sort(ts.begin(), ts.end());
    for(int i : ts){
      if((dist[g] + dist_g[h] + dist_h[i] == dist[i]) || (dist[h] + dist_h[g] + dist_g[i] == dist[i])){
        cout <<i<<" ";
      }
    }
    cout <<endl;

  }


}
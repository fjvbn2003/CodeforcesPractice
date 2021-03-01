#include <bits/stdc++.h>


using namespace std;
vector<pair<int,int> > g[20001];
vector<int> dist;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int v,e;
    cin>> v>>e;
    dist.resize(v+1);
    int start;
    cin>> start;

    for(int i=0; i<e; i++){
        int a,b,d;
        cin>> a>>b>>d;
        g[a].push_back({b,d});
    }
    for(int i=1; i<= v; i++){
        dist[i] = 987654321;
    }
    dist[start] = 0;

    priority_queue<pair<int, int> > pq;
    pq.push({0, start});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(cost >dist[now]){
            continue;
        }
        for(auto node : g[now]){
            int nxt_cost  = cost+node.second;
            int nxt = node.first;
            if(dist[nxt]>nxt_cost){
                dist[nxt] = nxt_cost;
                pq.push({-nxt_cost, nxt});
            }

        }

    }
    for(int i=1; i<=v; i++){
        if(dist[i] == 987654321){
            cout <<"INF"<<'\n';
        }else{
            cout <<dist[i]<<'\n';
        }

    }
}
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;
vector<pair<int, int> > g[20001];
vector<int> dist(20001);
vector<int> before(20001);

int main(){
    int v,e;
    int u,k,w;
    cin>> v>> e>>x;
    int x;
    
    
    for(int i=0; i<e; i++){
        cin>> u>> k>> w;
        g[u].push_back({k,w});
    }   

    priority_queue<pair<int, int> > pq;
    for(int i=1; i<=v; i++){
        dist[i] = 123456789;
    }
    dist[start] = 0;
    pq.push({0,start });
    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(dist[here] < cost){
            continue;
        }
        for(pair<int, int> next : g[here]){
            int node = next.first;
            int ncost = cost+next.second;
            if(dist[node] > ncost){
                dist[node] = ncost;
                before[node] = here;
                pq.push({-ncost, node});
            }
        }
        // for(int i=1; i<=v; i++){
        //     cout <<dist[i]<<" ";
        // }
        // cout <<endl;
    }
    stack<int> st;
    cout << dist[end]<<'\n';
    for(int i=0; i<=e; i++){
        st.push(end);
        end = before[end];
        if(end ==start){
            break;
        }
    }
    st.push(start);

    cout << st.size()<<'\n';
    while(!st.empty()){
        cout << st.top()<<' ';
        st.pop();
    }
    cout << endl;
    return 0;
}
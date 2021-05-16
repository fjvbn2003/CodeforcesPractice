#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"

#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    #ifdef hi
    freopen("./input.txt","r",stdin);
    freopen("./output.txt","w",stdout);
    #endif 
    int test_case = 1;
    cin>> test_case;
    while(test_case--){
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
vector< vector<int> > graph(200001);
int visited[200001];
void bfs (int start){
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i : graph[cur]){
            if(!visited[i]){
                q.push(i);
                if(visited[cur] == 1){
                    visited[i] = 2;
                }else{
                    visited[i] = 1;
                }
            }
        }
    }
}


void solve(){
    int  n, m, u, v;
    cin>> n>>m;
    for(int i=0; i<m ;i++){
        cin>> u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(1);
    int one_count = 0;
    int two_count = 0;
    for(int i=1; i<=n; i++){
        if(visited[i] == 1){
            one_count++;
        }else{
            two_count++;
        }
    }
    if(one_count<two_count){
        cout << one_count<<"\n";
        for(int i=1; i<=n; i++){
            if(visited[i]==1){
                cout << i << " ";
            }
        }
        cout <<"\n";
    }else{
        cout << two_count<<"\n";
        for(int i=1; i<=n; i++){
            if(visited[i]==2){
                cout << i << " ";
            }
        }
        cout <<"\n";
    }
    // for(int i=1; i <= n; i++){
    //     for(auto j : graph[i]){
    //         cout << j<<" ";
    //     }
    //     cout <<endl;
    // }
    // for(int i=1; i<=n; i++){
    //     cout <<visited[i]<<" ";
    // }
    // cout <<endl;
    for(int i=0; i<=n; i++){
        graph[i].clear();
        visited[i] = 0;
    }
}
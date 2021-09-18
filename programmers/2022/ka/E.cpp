#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[20];
bool visited[20][1 << 20];
int ans;

void dfs(int cur, int a, int b, int visit, vector<int> &info){
    int i;
    
    if(a <= b) return;
    
    ans = max(ans, a);
    
    if(visited[cur][visit]) return;
    
    visited[cur][visit] = true;
    
    for(i = 0; i < v[cur].size(); i++){
        if(visit & (1 << v[cur][i])) dfs(v[cur][i], a, b, visit, info);
        else dfs(v[cur][i], a + !info[v[cur][i]], b + info[v[cur][i]], (visit | (1 << v[cur][i])), info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int i;
    
    for(i = 0; i < edges.size(); i++){
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    
    dfs(0, 1, 0, 1, info);
    
    return ans;
}
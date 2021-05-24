#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<pair<int, int> > arr;
vector<int> tree[10006];
vector<int> indgree;
vector<int> visited;
int dfs(int node, int selec){
    //cout <<"visit: "<<node<<endl;
    int s = 0;
    int k;
    for(int i=0; i< tree[node].size(); i++){
        k = tree[node][i];
                if(visited[k]==1) continue;

        if(abs(selec-arr[k].first)< abs(selec-arr[k].second)){
            visited[k] =1;
            s+= abs(selec-arr[k].second) + dfs(k, arr[k].second);
        }else{
            visited[k] = 1;
            s+= abs(selec-arr[k].first) + dfs(k, arr[k].first);
        }
    }
    return s;
}

int main(){
    int test_case;
    cin>> test_case;
    int n;
    int a,b;
    int ans;
    while(test_case--){
        arr.clear();
        indgree.clear();
        visited.clear();
        cin>> n;
        indgree.resize(n+1, 0);
        visited.resize(n+1, -1);
        for(int i=0; i<=n; i++)
            tree[i].clear();
        ans = -1;
        arr.push_back(make_pair(0,0));
        for(int i=0; i<n; i++){
            cin>>a>>b;
            arr.push_back(make_pair(a,b));
        }
        
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            tree[a].push_back(b);
            tree[b].push_back(a);
            indgree[a]++;
            indgree[b]++;
        }
        // for(int i=1; i<=n; i++){
        //     cout <<"indgree: "<<i<<" : "<< indgree[i]<<endl;
        // }
        //cout <<"hi"<<endl;
        for(int i=1; i<=n; i++){
            if(indgree[i]==1){
                visited[i] = 1;
                ans = max(dfs(i, arr[i].first), ans);
                visited.clear();
                visited.resize(n+1, -1);
                visited[i] =1;
                ans = max(dfs(i, arr[i].second), ans);  
                break;
            }
        }
        cout <<ans<<'\n';

    }


}
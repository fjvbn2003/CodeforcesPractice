#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    #ifdef hi
    freopen("./input.txt","r",stdin);
    #endif 
    int test_case;
    cin>> test_case;
    while(test_case--){
        solve();
    }
    return 0;
}

void solve(){
    int n,x,y;
    vector<pair<int,int>> stores;
    pair<int,int> home, rock;

    cin>>n;
    cin>> home.first>> home.second;
    stores.push_back({home.first, home.second});
    for(int i=0; i<n; i++){
        cin>> x>>y;
        stores.push_back({x,y});
    }
    cin >> rock.first>>rock.second;
    stores.push_back({rock.first, rock.second});

    vector<vector<int>> gp(n+2);
    for(int i=0; i<stores.size(); i++){
        for(int j=i+1; j<stores.size(); j++){
            if(abs(stores[i].first-stores[j].first) + abs(stores[i].second -stores[j].second) <=1000){
                gp[i].push_back(j);
                gp[j].push_back(i);
            }
        }
    }
    vector<int> visit(n+2);
    for(int i=0; i<visit.size(); i++) visit[i] = 0;
    stack<int> s;
    s.push(0);
    visit[0] = 1;
    bool flag  = false;
    while(!s.empty()){
        int next = s.top();
        s.pop();
        if(next == n+1) flag = true;
        for(int i : gp[next]){
            if(visit[i]==0){
                s.push(i);
                visit[i]  =1;
            }
        }
    }
    if(flag){
        cout << "happy"<<endl;
    }else{
        cout <<"sad"<<endl;
    }
    

}
/*
problem: BOJ 9205 맥주마시면서 걸어가기
*/
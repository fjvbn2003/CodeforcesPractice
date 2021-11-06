//
// Created by Yongju KIM on 2021/11/06.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;
int n;
vector<vector<int> >  graph;

bool possible_b(int a, int b, int k){

    queue<int> q;
    q.push(a);
    vector<bool> visited(n, false);
    visited[a]  = true;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        for(int i=0; i< graph[c].size(); i++){
            int next = graph[c][i];
            if(next == k || visited[next] == true) continue;
            if(next == b) return true;
            q.push(next);
            visited[next] = true;
        }
    }
    return false;
}

bool possible_r(int a, int b, int k, int l){
    queue<int> q;
    q.push(a);
    vector<bool> visited(n, false);
    visited[a]  = true;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        for(int i=0; i< graph[c].size(); i++){
            int next = graph[c][i];
            if((c==k && next ==l) || visited[next] == true) continue;
            if(next == b) return true;
            q.push(next);
            visited[next] = true;
        }
    }
    return false;
}


int main(){

    cin>>n;
    graph.resize(n, vector<int >());
    int a, b;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int problem;
        cin>> problem;
        if(problem ==1){
            int a, b, k;
            a--;
            b--;
            k--;
            cin>>a>>b>>k;
            if(possible_b(a,b,k)){
                cout <<"YES"<<endl;
            }else{
                cout <<"NO"<<endl;
            }
        }else{
            int a, b, k, l;
            a--;
            b--;
            k--;
            l--;
            cin>>a>>b>>k>>l;
            if(possible_r(a,b,k,l)){
                cout <<"YES"<<endl;
            }else{
                cout <<"NO"<<endl;
            }


        }


    }

}
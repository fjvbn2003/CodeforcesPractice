#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 

int main(){
  int test_case;
  cin>> test_case;
  while(test_case--){
    int v,e;
    cin>>v>>e;
    vector<vector<int> > arr(v+1, vector<int>());
    vector<int> color(v+1, 0);
    int a,b;
    for(int i=0; i<e;i++){
      cin>>a>>b;
      arr[a].push_back(b);
      arr[b].push_back(a);
    }
    bool is_bipartite = true;
    queue<int> q;
    for(int k =1; k<=v; k++){
      if(color[k] == 0){
        // 1부터 탐색
        q.push(k);
        // 1을 Red==1 로 색칠
        color[k] = 1;
        while(!q.empty()){
          int node = q.front();
          int node_color = color[node];
          q.pop();
          for(int i=0; i<arr[node].size(); i++){
            int next = arr[node][i];
            if(color[next] == node_color){
              is_bipartite = false;
              break;
            }else if(color[next]==0){
              q.push(next);
              color[next] = (node_color==1)? 2 : 1;
            }else{// 이미 방문한 노드
              continue;
            }
          }
          if(!is_bipartite) break;
        }
        if(!is_bipartite) break;
      }
      
    }

    // for(int i=1; i<=v; i++){
    //   cout<<color[i]<<" ";
    // }
    // cout <<endl;
    if(!is_bipartite){
      cout <<"NO"<<endl;
    }else{
      bool flag = false;
      for(int i=1; i<=v; i++){
        if(color[i]==0){
          cout <<"NO"<<endl;
          flag = true;
          break;
        }
      }
      if(!flag){
        cout <<"YES"<<endl;
      }
    }
       
  }

}
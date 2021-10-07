#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int> > tree;
vector<int> visited;
int even = 0;
int odd = 0;
// bfs로 탐색하면서, 리프노드를 만날 때마다 해당하는 루트까지의 거리가 짝수이면 even++, 홀수이면 odd++함.
void bfs( int start){
  visited[start] = 0;
  queue<int> q;
  q.push(start);

  while(!q.empty()){
    int node = q.front();
    q.pop();
    if(node != start && tree[node].size()==1){
      bool is_even = (visited[node]%2 ==0)? true: false;
      if(is_even) even++;
      else odd++;
    }
    for(int i=0; i<tree[node].size(); i++){
      int next = tree[node][i];
      if(visited[next]==-1){
        q.push(next);
        visited[next] = visited[node]+1;
      }
    }
  }
}

int main(){
  cin>>n;
  tree.resize(n+1, vector<int>());
  visited.resize(n+1, -1);
  int a, b;
  for(int i=0; i<n-1; i++){
    cin>>a>>b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  bfs(1);
  //cout << "even: "<<even<<" odd:"<<odd<<endl;
  // 만약 홀수인 것이 있다면 이길 수 있지만 그렇지 않다면 무조건 짐.
  // 사실 even은 구하지 않아도 됨.
  if(odd%2==1){
    cout <<"Yes"<<endl;
  }else{
    cout <<"No"<<endl;
  }
  return 0;
}
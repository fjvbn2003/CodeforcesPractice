#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> >tree_up;
vector<vector<int> >tree_down;
vector<int> levels;
int find_root(int node){
  if(tree_up[node].size()==0) return node;
  else{
    return find_root(tree_up[node][0]);
  }
}
void make_level(int root, int level){
  levels[root] = level;
  for(auto node : tree_down[root]){
    make_level(node, level+1);
  }
  return;
}
int main(){
  int test_case;
  cin>>test_case;
  int a,b;
  while(test_case--){
    int n;
    cin>>n;
    // up_tree, down_tree 초기화
    tree_up.clear();
    tree_down.clear();
    levels.clear();
    tree_up.resize(n+1, vector<int>());
    tree_down.resize(n+1, vector<int>());
    levels.resize(n+1, 0);
    for(int i=0; i<n-1; i++){
      cin>>a>>b;
      tree_up[b].push_back(a);
      tree_down[a].push_back(b);
    }
    // 최소공통 조상을 찾아야할 두 노드.
    cin>>a>>b;
    int root = find_root(1);
    // root 부터 내려오면서 노드의 레벨을 기록
    make_level(root,0);
    int a_level = levels[a];
    int b_level = levels[b];
    // 트리의 레벨을 같도록 만들어준다.
    while(a_level != b_level){
      if(a_level > b_level){
        a = tree_up[a][0];
        a_level = levels[a];
      }else if(a_level<b_level){
        b = tree_up[b][0];
        b_level = levels[b];
      }else{
        break;
      }
    }
    int ans;
    while(a !=b){
      a = tree_up[a][0];
      b = tree_up[b][0];
      if(a==b) break;
    }
    ans = a;
    cout <<a<<endl;
  }
  return 0;

}
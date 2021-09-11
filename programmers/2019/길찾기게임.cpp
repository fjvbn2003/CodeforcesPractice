#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
  int y;
  int x;
  int idx;
};
bool comp(const node& a, const node& b){
  return a.y > b.y;
}
struct tree{
  tree(){
    cur = NULL;
    left =NULL;
    right = NULL;
  }
  void insert(node* n){
    if(cur->x > n->x){
      if(left != NULL){
        left->insert(n);
      }else{
        left = new tree();
        left->cur = n;
      }
    }else if(cur->x < n->x){
      if(right != NULL){
        right->insert(n);
      }else{
        right = new tree();
        right->cur = n;
      }
    }
  }
  node* cur;
  tree* left;
  tree* right;
};
vector<int> pre;
vector<int> post;
void preorder(tree* t){
  pre.push_back(t->cur->idx);
  if(t->left != NULL)
    preorder(t->left);
  if(t->right != NULL)
    preorder(t->right);
  return;
}
void postorder(tree* t){
  if(t->left != NULL)
    postorder(t->left);
  if(t->right != NULL)
    postorder(t->right);
  post.push_back(t->cur->idx);
  return;
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
      vector<node> nodes;
  for(int i=0 ; i<nodeinfo.size(); i++){
    auto t = nodeinfo[i];
    nodes.push_back({t[1],t[0], i+1});
  }
  sort(nodes.begin(), nodes.end(), comp);
  tree tr;
  tr.cur = &nodes[0];
  for(int i=1; i<nodes.size(); i++){
    tr.insert(&nodes[i]);
  }
  preorder(&tr);
  postorder(&tr);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}
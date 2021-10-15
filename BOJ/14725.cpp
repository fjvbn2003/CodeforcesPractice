#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;
// BOJ 14725 개미굴
// dfs로 node 탐색.
struct node{
  string name;
  map<string, node*> children;
};

void dfs_print(node* cur, int level){
  if(level !=0){
    for(int i=1; i<level; i++){
      cout <<"--";
    }
    cout << cur->name<<endl;
  }
  for(pair<string, node* > next : cur->children){
    dfs_print(next.second, level+1);
  }
  return;
}

int main(){
  int N;
  cin>>N;
  node* root = new node();
  root->name = "root";
  string s;
  for(int i=0; i<N; i++){
    int k;
    cin>>k;
    vector<string> tmp(k);
    for(int j =0; j<k; j++){
      cin>> tmp[j];
    }
    node* current = root;
    for(int j=0; j<k; j++){
      if(current->children.count(tmp[j]) <=0){
        node* new_node = new node();
        new_node->name = tmp[j];
        current->children.insert({tmp[j], new_node});
                
        current = current->children[tmp[j]];

      }else{
        current = current->children[tmp[j]];
      }

    }
        //     cout <<"currunt: "<< root.name<<endl;
        //   for(pair<string, node> next : root.children){
        //   cout<< next.first<<" ";
        // }
        // cout <<endl;
  }

  // for(pair<string, node* > next : root->children){
  //   cout<< next.first<<" ";
  // }
  // cout <<endl;

  dfs_print(root, 0);

  return 0;
}
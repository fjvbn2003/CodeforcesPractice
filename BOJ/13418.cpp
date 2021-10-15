#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// BOJ 13418  학교 탐방하기
// 크루스컬 알고리즘을 이용한 Minimum Spanning tree using union-find datastructure

#define MAX 1001
int Parent[MAX];
int Find_Parent(int x){
    if(Parent[x] == x) return x;
    else return Parent[x] = Find_Parent(Parent[x]);
}
bool SameParent(int x, int y){
    x = Find_Parent(x);
    y = Find_Parent(y);
    if(x==y) return true;
    else return false;
}
void Union(int x, int y){
    x = Find_Parent(x);
    y = Find_Parent(y);
    if(x!=y){
        Parent[y] = x;
    }
}

int main(){
  int N, M;
  cin>>N>>M;

  for(int i=0; i<MAX; i++)
    Parent[i] = i;
  // find maxium & minimum _spanning_tree;
  int a,b,c;
  vector<pair<int, pair<int, int> > > arr;
  for(int i=0; i<=M; i++){
    cin>>a>>b>>c;
    arr.push_back({c, {a, b}});
  }
  sort(arr.begin(), arr.end());
  int maxi = 0;
  int cnt =0;
  // maximum_spanning_tree
  for(int i=0; i<arr.size(); i++){
    c = arr[i].first;
    a = arr[i].second.first;
    b = arr[i].second.second;
    if(SameParent(a,b)) continue;
    Union(a, b);
    cnt++;
    if(c ==0) maxi++;
    if(cnt == N) break;
  }
  // Union find 배열 초기화.
  for(int i=0; i<MAX; i++)
    Parent[i] = i;
  int mini = 0;
  cnt =0;

  // minimum_spanning_tree
  for(int i=arr.size()-1; i>=0; i--){
    c = arr[i].first;
    a = arr[i].second.first;
    b = arr[i].second.second;
    if(SameParent(a,b)) continue;
    Union(a, b);
    cnt++;
    if(c ==0) mini++;
    // 트리가 전부 만들어졌을 때.
    if(cnt == N) break;
  }
  //오르막길 갯수에 따라 피로도 계산
  maxi = maxi*maxi;
  mini = mini*mini;

  cout << maxi -mini<<endl;


  return 0;


}
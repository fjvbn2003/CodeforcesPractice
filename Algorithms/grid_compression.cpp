#include <iostream>
#include <vector>
#include <algorithm>
vector<int> a, idx;
vector<pair<int, int> > qry;
int n,m;
int getidx(int x){
  return lower_bound(idx.begin(), idx.end(), x) - idx.begin();
}

using namespace std;

int main(){
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    idx.push_back(a[i]);
  }
  for (int i=  0; i < m; i++) {
    scanf("%d%d",qry[i].first, qry[i].second);
    idx.push_back(qry[i].first);
    idx.push_back(qry[i].second);
  }
  sort(idx.begin(), idx.end());
  idx.erase(unique(idx.begin(), idx.end()), idx.end());
}
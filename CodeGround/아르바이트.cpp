#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ldb;

struct Fenwick{
  int tree[955555], C=450000;
  void init(void) {memset(tree,0, sizeof(tree));}
  void update(int x, int v){while(x<=C){ tree[x]+=v; x+=(x&-x);}}
  int query(int x){int ret=0; while(x){ret += tree[x]; x-=(x&-x);} return ret;}
  int rquery(int l, int r){ return query(r)-query(l-1);}
} T;

int n, k, q;
int init[222222], ch[222222], ps[222222], res[222222];
int whi[222222], v[222222];
vector<int> POS;

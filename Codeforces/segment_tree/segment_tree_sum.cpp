#include <iostream>
#include <vector>
using namespace std;

struct segtree{
  int size;
  vector<long long> sums;
  void init(int n){
    size  = 1;
    while(size <n) size *= 2;
    sums.assign(2*size, 0LL);
  }
  // lx는 노드 x가 담당하는 왼쪽 경계,rx는 오른쪽 경계
  // i는 우리가 생각하는 인덱스, x는 segment tree에서의 index
  void build(vector<int> &a, int x, int lx, int rx){
    if(rx-lx == 1){
      if(lx < (int)a.size())
        sums[x] = a[lx];
      return ;
    }
    int m = (lx+rx)/2;
    build(a, 2*x+1, lx,m);
    build(a, 2*x+2, m, rx);
    sums[x] = sums[2*x+1]+sums[2*x+2];
  }
  void build(vector<int> &a){
    build(a, 0,0,size);
  }
  void set(int i, int v, int x, int lx, int rx){
    if(rx - lx == 1){
      sums[x] = v;
      return ;
    }
    int mid = (lx+rx)/2;
    if(i <mid)
      set(i,v,2*x+1,lx, mid);
    else
      set(i,v,2*x+2,mid, rx); 
    sums[x] = sums[2*x+1]+sums[2*x+2];
  }
  void set(int i, int v){
    set(i,v,0,0,size);
  }
  long long sum(int l, int r, int x, int lx, int rx){
    if(l>=rx || r<=lx) return 0;
    if(l<=lx && r>=rx) return sums[x];
    int m = (lx+rx)/2;
    long long s1 = sum(l,r, 2*x+1, lx, m);
    long long s2 = sum(l,r, 2*x+2, m, rx);
    return s1+s2;
  }
  long long sum(int l, int r){
    return sum(l, r, 0, 0,  size);
  }
};


int main(){
  int n, m;
  cin>>n>>m;
  segtree st;
  st.init(n);
  vector<int> arr(n,0);
  for(int i=0; i<n; i++){
    cin>> arr[i];
  }
  st.build(arr);
  int op, a,b;
  for(int i=0; i<m; i++){
    cin>>op>>a>>b;
    if(op==1){
      st.set(a,b);
    }else{
      cout<<st.sum(a,b)<<endl;
    }
  }
  return 0;
}
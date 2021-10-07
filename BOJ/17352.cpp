#include <iostream>
using namespace std;

// Union - Find 사용.
#define MAX 300001
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
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)
    Parent[i] = i;

  int a,b;
  for(int i=0; i<n-2; i++){
    cin>>a>>b;
    Union(a,b);
  }
  int t1 = Find_Parent(1);
  for(int i=2; i<=n; i++){
    if(t1 != Find_Parent(i)){
      cout << t1<<" "<< Find_Parent(i)<<endl;
      return 0;
    }
  }

}
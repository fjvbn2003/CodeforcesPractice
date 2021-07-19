#include <iostream>
#include <vector>
using namespace std;
#define MAX 100005

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
    int test_case = 0;
    cin>> test_case;
    while(test_case--){
      int n;
      int ans = 0;
      cin>>n;
      for(int i=0; i<n+1; i++){
        Parent[i] = i;
      }
      vector<int> arr(n+1);
      for(int i=1; i<=n; i++){
        cin>> arr[i];
      }
      for(int i=1; i<n+1; i++){
        if(arr[i]+i <n+1){
          Union(i, i+arr[i]);
        }
      }
      for(int i=1; i<=n; i++){
        if(Parent[i] ==i){
          ans++;
        }
      }
      cout <<ans<<endl;
    }
    
    
    
}
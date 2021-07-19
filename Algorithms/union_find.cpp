#include <iostream>
using namespace std;
#define MAX 100001
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
    for(int i=0; i<MAX; i++){
        Parent[i] = i;
    }
    Union(0,1);
    Union(1,2);
    Union(3,4);
    Union(5,6);
    Union(0,6);
    Union(3,8);
    cout << SameParent(2,6)<<endl;
    cout << SameParent(3,6)<<endl;
    cout << SameParent(4,8)<<endl;
    cout << SameParent(1,8)<<endl;
    cout << SameParent(2,1)<<endl;
    cout << SameParent(6,8)<<endl;
    
}
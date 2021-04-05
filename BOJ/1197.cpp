#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 10001
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

    vector


}
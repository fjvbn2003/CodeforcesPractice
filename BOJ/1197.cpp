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

    int v,e,a,b,c,w;
    cin>>v>>e;
    for(int i=0; i<=v; i++){
        Parent[i] = i;
    }
    vector<pair<int, pair<int, int> > > arr;
    for(int i=0; i<e; i++){
        cin>> a>>b>>c;
        arr.push_back({c,{a,b}});
    }
    sort(arr.begin(), arr.end());
    int cnt = 0;
    long long ans = 0;
    for(int i=0; i<arr.size(); i++){
        auto t = arr[i];
        w = t.first;
        a = t.second.first;
        b = t.second.second;
        if(!SameParent(a,b)){
            Union(a,b);
            ans+= w;
            cnt++;
            if(cnt == v-1){break;}
        }
    }
    cout <<ans<<endl;
    return 0;

}
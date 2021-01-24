#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long
#define ll_MAX 1000000000000000001
using namespace std;
ll n;

multiset<ll> ms;
void brute(int idx, vector<ll> & cand){
    if(idx==n-1){
        for(int i=0; i<cand.size(); i++){
            cout <<cand[i]<<" ";
        }
        cout <<endl;
        exit(0);
    }
    if(cand[idx]%3 ==0){
        ll t = cand[idx]/3;
        if(ms.count(t)){
            cand.push_back(t);
            ms.erase(ms.find(t));
            brute(idx+1, cand);
            cand.pop_back();
            ms.insert(t);
        }
    }
    ll t = cand[idx]*2;
    if( t <ll_MAX){
        if(ms.count(t)){
            cand.push_back(t);
            ms.erase(ms.find(t));
            brute(idx+1, cand);
            cand.pop_back();
            ms.insert(t);
        }
    }
    return ;
}

int main(){
    cin>> n;
    ll t;
    for(int i=0; i<n; i++){
        cin>>t;
        ms.insert(t);
    }
    vector<ll> ans;
    for(auto it = ms.begin(); it !=ms.end(); it++){
        ans.push_back(*it);
        brute(0, ans);
        ans.pop_back();
    }
    return 0;
}
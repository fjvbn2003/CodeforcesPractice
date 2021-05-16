#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp [10001];
set<long long> s;
int main(){
    int test_case;
    cin>> test_case;
    ll x;
    for(ll i=1; i<10001; i++){
        s.insert(i*i*i);
    }
    while(test_case--){
        cin>> x;
        bool flag = false;
        for(ll i=1; i*i*i<x; i++){
            ll remain = x-i*i*i;
            if(s.count(remain)){
                flag = true;
                break;
            }
        }
        if(flag){
            cout <<"YES"<<endl;
        }else{
            cout <<"NO"<<endl;
        }
    }
}
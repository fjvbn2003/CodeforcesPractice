#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"
#define ll long long 
#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    #ifdef hi
    freopen("./input.txt","r",stdin);
    #endif 
    solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
    ll x,y,z;
    cin>> x>> y>> z;
    ll cnt =0;
    if(x>0){
        cnt += x/z;
        x %=z;
    }
    if(y>0){
        cnt += y/z;
        y %=z;
    }
    ll r = 0;
    if(x>y){
        if(x+y >=z){
            cnt++;
            r = z-x;
        }
    }else{
        if(x+y >=z){
            cnt++;
            r = z-y;
        }
    }
    cout <<cnt <<" "<< r<<endl;
}
/*
Author: fjvbn2003
Round: # 567
problem: A. 
*/
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    #ifdef hi
    freopen("./input.txt","r",stdin);
    freopen("./output.txt","w",stdout);
    #endif 
    solve();

}
int sieve [2750132];
void solve(){
    //에라토스테네스의 채
    for(int i=2; i<2750132; i++) sieve[i] = true;
    for(int i=2; i*i < 2750132; i++){
        if(sieve[i]){
            for(int k=i*i; k<2750132; k+=i){
                sieve[k] = false;
            }
        }
    }
    int k=1;
    for(int i=2; i < 2750132; i++){
        if(sieve[i]){sieve[i] = k; k++;}
    }
    long long  n,t;
    cin>> n;
    multiset<int> ms;
    vector<int> ans;
    for(int i=0; i<n*2; i++){
        cin>> t;
        ms.insert(t);
    }
    // for(auto i : ms){
    //     cout<< i<<" ";
    // }
    // cout << endl;
    while(!ms.empty()){
        t = *(--ms.end());
        //cout <<"maxt : "<<t<<endl;
        ms.erase(--ms.end());
        if(sieve[t]){
            //cout <<"prime index : "<<sieve[t]<<endl;
            ms.erase(ms.lower_bound(sieve[t]));
            ans.push_back(sieve[t]);
        }else{
            int m = 1;
            for(long long i=2; i*i<=t; i++){
                if(t%i==0){m = t/i; break;}
            }
            //cout <<"greatest divisor : "<<m<<endl;
            ms.erase(ms.lower_bound(m));
            ans.push_back(t);
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i]<<" ";
    }
    // cout <<"sieve[i]"<<endl;
    // for(int i=0; i<100; i++){
    //     cout << sieve[i]<<" ";
    // }
    cout <<endl;


}
/*
다이나믹 프로그래밍과 그리디 알고리즘으로 좋은 문제.
Author: fjvbn2003
Round: #565(Div.3)
problem: D. Recover it!
*/
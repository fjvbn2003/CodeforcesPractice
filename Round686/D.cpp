#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#define ll long long
#include <bits/stdc++.h>
using namespace std;
bool primes [500000];
vector<ll> prime;
void solve();
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    #ifdef hi
    freopen("./input.txt","r",stdin);
    #endif 
for(int i=2; i<500000; i++){
     primes[i] = true;
}
for(int i=2; i*i < 500000; i++){
    if(primes[i]){
        for(int k=i*i; k<500000; k+=i){
            primes[k] = false;
        }
    }
}
for(int i=1; i<500000; i++){
    if(primes[i]){
        prime.push_back(i);
    }
}
    int test_case = 1;
    cin>> test_case;
    while(test_case--){
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
    ll n, nt;
    cin>>n;
    nt = n;
    vector<ll> s;
    set<ll> se;
    for(int i=0; i<prime.size(); i++){
        if(prime[i]*prime[i] > n){break;}
        if((nt% prime[i]) ==0){
            while(nt%prime[i]==0){
                nt/=prime[i];
                s.push_back(prime[i]);
                se.insert(prime[i]);
            }

        }
    }
    if(nt != 1){
        s.push_back(nt);
    }
    ll idx;
    ll mani = -1;
    for(int i : se){
        cout <<i<<" ";
        if(count(s.begin(), s.end(), i) >mani){
            mani = count(s.begin(), s.end(), i);
        }
    }
    cout << "mani: "<<mani<<endl;
}


/*
Author: fjvbn2003
Round: #
problem: D.
*/
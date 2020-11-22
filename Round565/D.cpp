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
bool primes [2750132];

void solve(){
    for(int i=2; i<2750132; i++) primes[i] = true;
    for(int i=2; i*i < 2750132; i++){
        if(primes[i]){
            for(int k=i*i; k<2750132; k+=i){
                primes[k] = false;
            }
        }
        
    }
    for(int i=1; i<2750132; i++){
        if(primes[i]){
            cout << i <<" ";
        }
    }
    cout <<endl;
}
/*
다이나믹 프로그래밍과 그리디 알고리즘으로 좋은 문제.
Author: fjvbn2003
Round: #565(Div.3)
problem: D. Recover it!
*/
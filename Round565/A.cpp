#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"

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
    int test_case = 1;
    cin>> test_case;
    while(test_case--){
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
    long long n;
    int ans = 0;
    cin>>n; 
    while(n%5==0){n = (n/5)*4;ans++;}
    while(n%3==0){n = (n/3)*2;ans++;}
    while(n%2==0){n/=2;ans++;}

    if(n==1){cout <<ans<<endl;}
    else{cout <<-1<<endl;}
}
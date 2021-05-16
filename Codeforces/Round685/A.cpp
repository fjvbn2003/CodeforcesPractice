#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"

#include <bits/stdc++.h>
using namespace std;
void solve();
int dp[1000000001];
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    #ifdef hi
    freopen("./input.txt","r",stdin);
    freopen("./output.txt","w",stdout);
    #endif 
    int test_case = 1;
    cin>> test_case;
        dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    while(test_case--){
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}


int find(int t){
    if(t==1 || t<0){return 0;}
        if(dp[t]){
            return dp[t];
        }
    }
    int ans = 123456789;
    for(int i=a; i>=2; i--){
        if(t%i==0){
            ans = min(find(t/i)+1,ans);
        }
    }

    if(t<100001 ){
        dp[t] = ans;
    }
    return ans;
}
void solve(){
    int n; 
    cin>>n;
    cout <<find(n)<<endl;;
}
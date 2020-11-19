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
    int test_case = 1;
    cin>> test_case;
    while(test_case--){
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
    int i,j, ans;
    cin>>i>>j;
    if(i>j){swap(i,j);}
    ans = 0;
    ans += i*2;
    j-= i;
    if(j){
    ans += j*2;
    ans-=1;
    }
    

    cout <<ans<<endl;
}
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
    string s;
    cin>>s;
    int lb=0;
    int lc=0;
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            lb++;
        }
        else if(s[i]=='['){
            lc++;
        }
        else if(s[i]==')'){
            if(lb){
                lb--;
                ans++;
            }
        }else{
            if(lc){
                lc--;
                ans++;
            }
        }
    }   
    cout <<ans<<endl;
}
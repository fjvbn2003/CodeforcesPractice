#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"

#include <bits/stdc++.h>
using namespace std;
void solve();
int main(){
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL); 
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
    int n, q, a,b;
    string s,t;
    cin>>n>>q;
    cin>>s;
    for(int i=0; i<q; i++){
        cin>> a>> b;
        t = s.substr(a-1,b-a+1);
        int start_idx = 0;
        int count =0;
        bool chance = true;
        for(int j=0; j<t.size(); j++){
            bool flag = false;    
            for(int k = start_idx; k<n; k++){
                if(s[k] == t[j]){
                    start_idx = k+2;
                    flag = true;
                    count++;
                    break;
                }
            }
            if(!flag){start_idx++;}
        }
        if(count == t.size()){
            cout <<"YES"<<endl;
        }else{
            cout <<"NO"<<endl;
        }
    }
}
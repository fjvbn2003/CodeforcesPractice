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
    #endif 
    solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
    int n;
    string s, s1, s2;
    cin>> n>>s;
    if(s[n/2]=='0'){
            int l0  = n/2;
            int r0 = n/2;
            for(int i=n/2 -1; i>=0; i--){
                if(s[i] != '0'){
                    break;
                }else{
                    l0 =i;
                }
            }
            for(int i=n/2+1; i<n; i++){
                if(s[i] != '0'){
                    break;
                }else{
                    r0 = i;
                }
            }
            if(l0==n/2){l0 = 0;}
            if(r0==n/2){r0 = n-1;}
            int d = (r0- n/2 < n/2 - l0)? r0 : l0; 
            // cout <<l0 << " "<<r0<<endl;
            s1 = s.substr(0, d);
            s2 = s.substr(d);
    }else{
            s1 = s.substr(0, n/2);
            s2 = s.substr(n/2);
    }
    
    cout<<s<<endl;
    cout << s1<<" "<<s2<<endl;
}
/*
Author: fjvbn2003
Round: #
problem: B.
*/
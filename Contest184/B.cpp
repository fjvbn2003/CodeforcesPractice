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

        solve();
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
    int  n, x;
    string s;
    cin>> n>>x>>s;
    for(int i=0; i<n; i++){
        if(s[i]=='o'){
            x++;
        }else{
            if(x==0){
                continue;
            }else{
                x--;
            }
        }
    }
    cout <<x<<endl;
}
/*
Author: fjvbn2003
Round: #
problem: B.
*/
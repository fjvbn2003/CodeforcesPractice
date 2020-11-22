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
    
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int s = a+b+c;
    double ans =0;
    for(int i=a; i<100; i++){
        ans+= ((double)i/(i+b+c));
    }

    cout.precision(10);
    cout <<ans<<endl;
}
/*
Author: fjvbn2003
Round: #
problem: D.
*/
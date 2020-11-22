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
    int n,t, tmp;
    vector<int> arr(n);
    cin>>n>>t;
    long long s = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
         if(s+arr[i] == t){
            s+= tmp;
        }else if(s+arr[i]>t){
        
            break;
        }else{
            s+= tmp;
        }
    }

       cout <<s<<endl;
}
/*
Author: fjvbn2003
Round: #
problem: D.
*/
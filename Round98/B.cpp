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
    int n;
    int t;
    cin>>n;
    int _min = 1e9;
    int _max = -1;
    for(int i=0; i<n; i++){
        cin>>t;
        if(t>_max){_max = t;}
        if(t<_min){_min = t;}
    }
    int diff = _max - _min;
    long long mm = _max;
    long long nn = _min;
    int ans = 0;
    // for(int i=1; i<1e9; i++){
    //     mm = _max+i;
    //     nn = _min+i;
    //     if(mm%(n-1)==0){
    //         if(nn%(n-2)==0){
    //             if(nn/(n-2) == diff){
    //                 ans = nn-_min;
    //                 break;
    //             }
                
    //         }
    //     }
    // }
    for(int i=0; i<1e8; i++){
        if((_max+i)%(n-1) == 0){
            if((_min+i)%(n-2) ==0){
                if(((n-2)*diff)%(_min+i)==0){
                    ans =  i;
                    break;
                }
                
            }
        }
        
    }
    
    cout <<ans<<endl;    
    //cout<<"min: "<<_min<<" max:"<<_max<<endl;
    
}
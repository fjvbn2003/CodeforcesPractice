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
int arr[3];
void solve(){
    int n,t ;
    int ans = 0;
    memset(arr,0, sizeof(arr));
    cin>>n;
    for(int i=0;i<n; i++){
        cin>>t;
        arr[t%3]++;
    }
    ans += arr[0];
    if(arr[1]==arr[2]){
        ans+= arr[1];
    }else if(arr[1]<arr[2]){
        ans+=arr[1];
        ans+= (arr[2]-arr[1])/3;
    }else{
        ans+=arr[2];
        ans+= (arr[1]-arr[2])/3;
    }
    //cout <<arr[0]<< " "<<arr[1]<<" "<<arr[2]<<endl;
    cout <<ans<<endl;
}
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
    freopen("./ouput.txt","w",stdout);
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
    int n,m,t;
    vector<int> arr;
    bool odd = false;
    bool zero = false;
    cin>> n>>m;
    for(int i=0;i<n; i++){
        for(int j =0; j<m;j++){
            cin>>t;
            if(t == 0){zero = true;}
            if(t<0){
                odd  =  !odd;
                arr.push_back(-t);
            }else{
                arr.push_back(t);
            }
        }
    }
    sort(arr.begin(), arr.end());
    int sum = 0;
    for(int i=0; i<arr.size(); i++){sum+=arr[i];}
    if(zero){
        cout <<sum<<endl;
    }else{
        if(odd){
            sum -= 2*arr[0];
            cout<<sum<<endl;
        }else{
            cout<<sum<<endl;
        }
    }


}
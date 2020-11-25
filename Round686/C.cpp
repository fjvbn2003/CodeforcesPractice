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
    int test_case = 1;
    cin>> test_case;
    while(test_case--){
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}

void solve(){
    int n,t;
    set<int> s;
    cin>>n;
    vector<int> arr(n+1);
    vector<int> ans(n+1);
    for(int i=0; i<n; i++){
        cin>> t;
        arr[i] = t;
        s.insert(t);
        if(i==0){continue;}
        else{
            if(i==n-1){
                ans[arr[i]]--;
            }
            if(arr[i-1] != arr[i]){
                ans[arr[i]]++;
            }
        }
    }
    int mini = 1e9;
    for(int i=1; i<=n; i++){
        if(s.count(i) && mini > ans[i]){
            mini = ans[i];
        }
    }
    if(s.size() ==1){
        cout <<0<<endl;
    }else{
        cout << mini+1<<endl;
    }
}
/*
Author: fjvbn2003
Round: #686
problem: C.Sequence Transformation
*/
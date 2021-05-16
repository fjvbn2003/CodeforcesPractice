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
    int n;
    cin >>n;
    vector<int> arr;
    for(int i=1; i<=n; i++){
        arr.push_back(i);
    }
    reverse(arr.begin(), arr.end());
    if(n%2 ==1){
        swap(arr[n/2],arr[0]);
    }
    for(int i : arr){
        cout << i<<" ";
    }
    cout <<endl;
}
/*
Author: fjvbn2003
Round: #
problem: A. 
*/
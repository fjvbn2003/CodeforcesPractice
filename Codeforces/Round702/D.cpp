#include <bits/stdc++.h>

using namespace std;


void trans(int l, int r, int depth, vector<int> & arr, vector<int> & memo){
    if(l>r) return;
    int maxi = -1;
    int maxi_idx = l;

    for(int i=l; i<=r; i++){
        if(maxi <arr[i]){
            maxi = arr[i];
            maxi_idx = i;
        }
    }
    memo[maxi_idx] = depth;
    trans(l,maxi_idx-1, depth+1, arr, memo);
    trans(maxi_idx+1, r, depth+1, arr, memo);
    return ;
}

int main(){
    int test_case;
    cin>> test_case;

    while(test_case--){
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> memo(n);
        for(int i=0; i<n; i++){
            cin>> arr[i];
        }
        trans(0,n-1, 0, arr, memo);
        for(int i=0; i<n; i++){
            cout << memo[i]<<" ";
        }
        cout <<endl;
        
    }
    return 0;
}
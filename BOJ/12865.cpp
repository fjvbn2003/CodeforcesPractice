#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, w, v;
vector<pair<int, int> > arr;
int dp[101][100001];
int max_val(int idx, int remain){
    if(idx == 0 && remain <arr[idx].first) return 0;
    if(idx == 0 && remain>= arr[idx].first){
        return arr[idx].second;
    }

    if(dp[idx][remain] != -1) return dp[idx][remain];
    int & ret  = dp[idx][remain];
    if(arr[idx].first <= remain){
        ret = arr[idx].second+ max_val(idx-1, remain-arr[idx].first);   
    }
    ret = max(ret, max_val(idx-1, remain));
    return  ret;
}

int main(){
    cin>> n>>k;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            dp[i][j] = -1;
        }
    }
    for(int i=0; i<n; i++){
        cin>> w>>v;
        arr.push_back({w,v});
    }
    cout << max_val(n-1,k)<<endl;
    return 0;
}
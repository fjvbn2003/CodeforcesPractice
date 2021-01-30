#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> stairs;
int n;
int dp[301][2];
int max_val(int i, int before){
    if(i<1) return 0;
    if(i==1 ) return stairs[1];
    if(dp[i][before]) return dp[i][before];
    int& ret = dp[i][before];

    if(before==0){
        ret = max(max_val(i-2,1)+stairs[i], max_val(i-2,0)+stairs[i]);
        return ret;
    }else if(before == 1){
        ret = max(ret, max_val(i-1, 0)+stairs[i]);
        return ret;
    }else{
        ret = max(ret, max_val(i-1, 1)+stairs[i]);
        return ret;
    }
}

int main(){
    int n,t;
    cin>>n;
    stairs.push_back(0);
    for(int i=0; i<n;i++){
        cin>> t;
        stairs.push_back(t);
    }
    dp[1][0] = stairs[0];
    dp[1][1] = 0;
    dp[1][2] = 0;
    
    
    int ans = max(max_val(n,0),max_val(n, 1));

    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<2; j++){
    //         cout << dp[i][j]<< " ";
    //     }
    //     cout <<endl;
    // }
    cout <<ans<<endl;
    return 0;

}
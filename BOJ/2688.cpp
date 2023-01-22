#include <iostream>
#include <vector>
using namespace std;
int main(){

    int T;
    cin>>T;

    long long dp[66][10];
    for(int i=0; i<10; i++){
        dp[1][i] = 1LL;
    }
    for(int i=0; i<65; i++){
        dp[i][9] = 1LL;
    }
    for(int j=2; j<65; j++){
        for(int i=8; i>=0; i--){
            dp[j][i] = (long long)dp[j][i+1]+ dp[j-1][i];
        }
    }
    // for(int i=0; i<10; i++){
    //     for(int j=0; j<10; j++){
    //         cout << dp[i][j] <<" ";
    //     }
    //     cout <<endl;
    // }
    while(T--){
        int n;
        cin>>n;
        long long ans = 0;
        for(int i=0; i<10; i++){
            ans += dp[n][i];
        }
        cout <<ans<<endl;
    }

    return 0;

}
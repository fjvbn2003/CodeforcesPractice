#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dp[100001][3];

int main(){
    int test_case;
    cin>>test_case;
    string s;
    while(test_case--){
        cin>>s;
        long long ans = 0;
        for(int i=0; i<s.size(); i++){
            dp[i][0] = 0;
            dp[i][1] = 0;
            dp[i][2] = 0;
        }
        if(s[0]=='0') dp[0][0]++;
        if(s[0]=='1') dp[0][1]++;
        if(s[0]=='?') dp[0][2]++;
        for(int i=1; i<s.size(); i++){
            if(s[i] == '0'){
                if(s[i-1]=='1')
                    dp[i][0] = dp[i-1][1]+1;
                else if(s[i-1]=='?')
                    dp[i][0] = dp[i-1][1]+dp[i-1][2]+1;
            }else if(s[i] == '1'){
                if(s[i-1]=='0' )
                    dp[i][1] = dp[i-1][0]+1;
                else if(s[i-1]=='?')
                    dp[i][1] = dp[i-1][0]+dp[i-1][2]+1;
            }else{
                if(s[i-1]=='0'){
                    dp[i][1] = dp[i-1][0];
                    dp[i][2] = 1;
                }
                else if(s[i-1]=='1'){
                    dp[i][0] = dp[i-1][1];
                    dp[i][2] = 1;
                }
                else{
                    dp[i][2] = dp[i-1][1]+dp[i-1][0]+dp[i-1][2]+1;
                }
            }
        }
        for(int i=0; i<s.size(); i++){
            ans+= dp[i][0];
            ans+= dp[i][1];
            ans+= dp[i][2];
        };
        cout << ans<<'\n';

        
    }

}
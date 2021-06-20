#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int dp[200001][2];
int main(){
    int test_case;
    cin>>test_case;
    string s;
    while(test_case--){
      cin>> s;
      int n = s.size();
      for(int i=0; i<n; i++){
          dp[i][0] = 0;
          dp[i][1] = 0;
      } 
      if(s[0]=='?'){
          dp[0][0] = 1;
          dp[0][1] = 1;   
      }
      else if(s[0]=='1'){
          dp[0][1] = 1;   
      }else{
          dp[0][0] = 1;
      }
      for(int i=1; i<n; i++){
          if(s[i] == '1'){
              if(s[i-1] != '1'){
                  dp[i][1] = dp[i-1][0]+1;
              }else{
                  dp[i][1] = 1;
              }
          }else if(s[i] == '0'){
              if(s[i-1] != '0'){
                  dp[i][0] = dp[i-1][1]+1;
              }else{
                  dp[i][0] = 1;
              }
          }else{
              if(s[i-1] == '0'){
                  dp[i][1] = dp[i-1][0]+1;
                  dp[i][0] = 1;
              }else if(s[i-1] == '1'){
                  dp[i][0] = dp[i-1][1]+1;
                  dp[i][1] = 1;
              }else{
                  dp[i][1] = dp[i-1][0]+1;
                  dp[i][0] = dp[i-1][1]+1;
              }
          }
      }  
      long long ans = 0;
      for(int i=0; i<n; i++){
          ans += max(dp[i][0], dp[i][1]);
      }
      cout <<ans<<'\n';
    }

}
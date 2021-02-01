#include <iostream>
#include <vector>
using namespace std;
int n;
int ans;
vector<int> cows;
vector<int> height;
long long dp[21][1048577];
long long solve(int idx, int bitset){
    if(idx==n && bitset== (1<<n)-1){
        return 1;
    }
    if(dp[idx][bitset] != -1) return dp[idx][bitset];
    long long ret = 0;
    for(int i=0; i<height.size(); i++){
        if(((1<<i)&bitset)==0 && cows[idx]<=height[i]){
            ret += solve(idx+1, bitset|(1<<i));
        }
    }
    dp[idx][bitset] = ret; 
    return ret;
}
int main(){
    int t;
    cin>>n;
    for(int i=0; i<21; i++){
        for(int j=0; j<1048577; j++){
            dp[i][j] = -1;
        }
    }
    for(int i=0; i<n; i++){
        cin>> t;
        cows.push_back(t);
    }
    for(int i=0; i<n; i++){
        cin>> t;
        height.push_back(t);
    }
    
    cout <<solve(0,0)<<endl;

}
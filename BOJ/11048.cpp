#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1001][1001];
int dp[1001][1001];
int n,m;

int max_val(int y, int x){
    if(y<1 || y>n || x<1 || x>m ) return 0;
    if(y==1 && x==1) return arr[1][1];
    if(dp[y][x] != -1) return dp[y][x];
    int &ret = dp[y][x];
    ret = max(max_val(y-1, x)+arr[y][x], max_val(y, x-1)+arr[y][x]);
    ret = max(ret, max_val(y-1, x-1));
    return ret;
}


int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] = -1;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }
    cout <<max_val(n,m)<<endl;
    return 0;
}
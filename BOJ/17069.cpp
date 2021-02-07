#include <iostream>
#include <vector>
#define ll long long
using namespace std;
ll n;
ll arr[100][100];
ll dp[100][100][3];
ll brute(ll y, ll x, ll dir){

    if(y==n && x==n ) return 1;
    ll &ret = dp[y][x][dir];
    if(ret != -1) return ret;
    ret = 0;
    //가로
    if(dir ==0){
        if(x+1 <=n && arr[y][x+1] == 0){
            ret += brute(y,x+1, 0);
        }
        if(x+1 <=n && y+1 <=n && arr[y+1][x]==0 && arr[y][x+1]==0 && arr[y+1][x+1]==0){
            ret += brute(y+1, x+1, 2);
        }
    }else if(dir ==1){//세로
        if(y+1 <=n && arr[y+1][x] == 0){
             ret += brute(y+1, x, 1);
        }
        if(x+1 <=n && y+1 <=n && arr[y+1][x]==0 && arr[y][x+1]==0 && arr[y+1][x+1]==0){
            ret += brute(y+1, x+1, 2);
        }
    }else if(dir ==2){//대각

        if(x+1 <=n && arr[y][x+1] == 0){
            ret += brute(y,x+1, 0);
        }
        if(y+1 <=n && arr[y+1][x] == 0){
             ret += brute(y+1, x, 1);
        }
        if(x+1 <=n && y+1 <=n && arr[y+1][x]==0 && arr[y][x+1]==0 && arr[y+1][x+1]==0){
            ret += brute(y+1, x+1, 2);
        }
    }   
    return ret;
}


int main(){

    cin>>n;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            for(ll k=0; k<3; k++){
                dp[i][j][k] = -1;
            }
        }
    }
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            cin>> arr[i][j];
        }
    }
    cout <<brute(1,2,0)<<endl;
    return 0;
}

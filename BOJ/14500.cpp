#include <bits/stdc++.h>
using namespace std;
int arr[510][510];
int visit[510][510];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
int n, m;  
int dfs(int i, int j, int cnt, int s){
    if(cnt == 4){
        return s;
    }
    int ans = 0;
    for(int k = 0; k<4; k++){
        int ny = i+dy[k];
        int nx = j+dx[k];
        if( ny>=1 && ny<=n && nx>=1 && nx<=m && !visit[ny][nx]){
            visit[ny][nx] = true;
            ans = max(ans, dfs(ny,nx,cnt+1,s+arr[ny][nx]));
            visit[ny][nx]  =false;
        }
    }
    return ans;
}
int f(int i, int j){
    int cand = 0;
    // ㅗ 모양
    if(i>=2 && j<=m-2){
        cand = max(cand, arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i-1][j+1]);
    }
    // ㅜ 모양
    if(i<=n-1&& j<=m-2){
        cand = max(cand, arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]);
    }
    // ㅏ 모양
    if(i<=n-2&& j<=m-1){
        cand = max(cand, arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+1][j+1]);
    }
    // ㅓ 모양
    if(i<=n-2&& j>=2){
        cand = max(cand, arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+1][j-1]);
    }
    return cand;
}

int main(){
    cin>>n>>m; 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>> arr[i][j];
        }
    }
    int mani = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            visit[i][j] = true;
            mani = max(mani, dfs(i,j,1,arr[i][j])  );
            mani = max(mani, f(i,j));
            visit[i][j] = false;
            //cout << "i: "<< i<< " j:"<<j<<" mani: "<<mani<<endl;
        }
    }
    cout << mani<<endl;
    return 0;
}

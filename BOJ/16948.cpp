#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int r1,c1,r2,c2;
int dp[201][201];
int dy[6] = {-2,-2,0,0,2,2};
int dx[6] = {-1,1,-2,2,-1,1};

int bfs(int r, int c){
    queue<pair<int, int> > q;
    dp[r][c] = 0;
    q.push({r,c});
    
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        for(int i=0; i<6; i++){
            int y = p.first+dy[i];
            int x = p.second+dx[i];
            if(y>=0 && y<n && x>=0 && x<n && dp[y][x]==-1){
                q.push({y,x});
                dp[y][x] = dp[p.first][p.second]+1;
                if(y==r2 && x==c2){
                    return dp[y][x];
                }
            }
        }
    }
    return dp[r2][c2];

}

int main(){
    cin>> n>>r1>>c1>>r2>>c2;
    for(int i=0; i<201; i++){
        for(int j=0; j<201; j++){
            dp[i][j] = -1;
        }
    }
    int answer = bfs(r1,c1);
    cout <<answer<<endl;
    return 0;
}
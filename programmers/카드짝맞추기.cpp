#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 987654321
int D[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<int> > Board;
struct point{
    int r;
    int c;
    int cnt;
};
int bfs(point start, point end){
    bool visited[4][4];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            visited[i][j] = false;
    
    queue<point> q;
    q.push(start);
    visited[start.r][start.c]  = true;
    while(!q.empty()){
        point curr = q.front();
        q.pop();
        if(curr.r == end.r && curr.c == end.c){
            return curr.cnt;
        }
        for(int i=0; i<4; i++){
            int nr = D[i][0] + curr.r;
            int nc = D[i][1] + curr.c;
            if(nr <0 || nr>=4 || nc<0 || nc>=4  ) continue;
            if(!visited[nr][nc]){
                q.push({nr, nc, curr.cnt+1});
                visited[nr][nc] = true;            
            }
            
            for(int j=0; j<2; j++){
                if(Board[nr][nc] != 0) break;

                if(nr+D[i][0] <0 || nr+D[i][0]>=4 || nc+D[i][1]<0 || nc+D[i][1]>=4) break;

                nr += D[i][0];
                nc += D[i][1];
            }
            if(visited[nr][nc] == false){
                q.push({nr, nc, curr.cnt+1});
                visited[nr][nc] = true;
            }
        }
    }
    return INF;
    
}


int permutate(point p){
    int ret = INF;
    for(int k=1; k<=6; k++){
        vector<point> cards;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(Board[i][j] == k)
                    cards.push_back({i,j,0});
            }
        }
        if(cards.size()==0) continue;
        int one = bfs(p, cards[0]) + bfs(cards[0], cards[1]) +2;
        int two = bfs(p, cards[1]) + bfs(cards[1], cards[0]) +2;
        
        Board[cards[0].r][cards[0].c] = 0;
        Board[cards[1].r][cards[1].c] = 0;
        
        ret = min(ret,one + permutate(cards[1]));
        ret = min(ret,two + permutate(cards[0]));
        
        Board[cards[0].r][cards[0].c] = k;
        Board[cards[1].r][cards[1].c] = k;
        
    }
    if(ret == INF) return 0;
    return ret;
}
    
int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    Board = board;
    //cout << "from 1,0 to 2,3: "<< bfs({1,0,0}, {2,3,0})<<endl;
    return permutate({r,c,0});
}
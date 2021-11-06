//
// Created by Yongju KIM on 2021/11/06.
//



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;
vector<vector<int> > arr;
int DP[1000][1000][8];
int n;
int D[8][2] = {{0,1}, {1, 0}, {1,1}, {-1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}};

int main(){

    cin>>n;
    arr.resize(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> arr[i][j];
        }
    }
    // 0번 방향
    for(int dir = 0; dir<8; dir++){
        int y;
        int x;
        // 직선
        if(dir == 0 || dir == 1 || dir == 4 || dir == 5) {
            for (int i = 0; i < n; i++) {
                if (dir == 0) {
                    y = i;
                    x = 0;
                } else if (dir == 1) {
                    y = 0;
                    x = i;
                } else if (dir == 4) {
                    y = i;
                    x = n - 1;
                } else if (dir == 5) {
                    y = n - 1;
                    x = i;
                }
                int len = 0;
                do {
                    if (arr[y][x] == 1) {
                        len++;
                        // direction
                        DP[y][x][dir] = len;
                    } else {
                        len = 0;
                    }
                    //direction
                    y += D[dir][0];
                    x += D[dir][1];
                } while (y < n && x < n && y >= 0 && x >= 0);
            }

        }else{// 대각선
            // 한쪽

            for(int i=0; i<n; i++){
                int y, x;
                if(dir == 2){
                    y  = 0;
                    x = i;
                }else if(dir ==3){
                    y = i;
                    x = 0;
                }else if(dir ==6){
                    x = i;
                    y = n-1;
                }else if(dir ==7){
                    y = 0;
                    x = i;
                }
                int len = 0;
                do {
                    if (arr[y][x] == 1) {
                        len++;
                        // direction
                        DP[y][x][dir] = len;
                    } else {
                        len = 0;
                    }
                    //direction
                    y += D[dir][0];
                    x += D[dir][1];
                } while (y < n && x < n && y >= 0 && x >= 0);

            }
            for(int i = n-1; i>=0; i--){
                int y, x;
                if(dir == 2){
                    y = i;
                    x = 0;
                }else if(dir ==3){
                    y = n-1;
                    x = i;
                }else if(dir ==6){
                    y = i;
                    x = n-1;

                }else if(dir ==7){
                    y = i;
                    x = n-1;
                }
                int len = 0;
                do {
                    if (arr[y][x] == 1) {
                        len++;
                        // direction
                        DP[y][x][dir] = len;
                    } else {
                        len = 0;
                    }
                    //direction
                    y += D[dir][0];
                    x += D[dir][1];
                } while (y < n && x < n && y >= 0 && x >= 0);
            }


        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] != 2) continue;
            for(int dir =0; dir<8; dir++){
                ans = max(ans, DP[i][j][dir]);
                int cand = 1;
                int by = i - D[dir][0];
                int bx = i - D[dir][1];
                if(by >=0 && by <n && bx>=0 && bx <n){
                    cand += DP[by][bx][dir];
                }

                int ay = i + D[dir][0];
                int ax = i + D[dir][1];
                if(ay >=0 && ay <n && ax>=0 && ax <n){
                    cand += DP[ay][ax][(dir+4)%8];
                }
                ans = max(cand, ans);
            }

        }
    }
    cout <<ans<<endl;

    for(int dir = 0; dir<8; dir++){
        cout <<"dir: "<<dir<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout <<DP[i][j][dir];
            }
            cout <<endl;
        }
        cout <<endl;
    }
}
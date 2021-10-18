//
// Created by Yongju KIM on 2021/10/18.
// BOJ 21610 마법사 상어와 비바라기

#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<vector<int> > grid;
int D[8][2] = {{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
int D2[4][2] = {{-1,-1},{1,-1},{1,1},{-1,1}};

int main(){
    cin>>N>>M;
    grid.resize(N, vector<int>(N,0));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>grid[i][j];
        }
    }
    int d, s;
    vector<pair<int, int> > clouds;
    clouds.push_back(make_pair(N-1, 0));
    clouds.push_back(make_pair(N-1, 1));
    clouds.push_back(make_pair(N-2, 0));
    clouds.push_back(make_pair(N-2, 1));

    for(int times=0; times<M; times++){
        cin>>d>>s;
        d--;
        // d 방향으로 구름 이동.
        for(int i=0; i<clouds.size(); i++ ){
            clouds[i].first += s*D[d][0];
            clouds[i].second += s*D[d][1];
            while(clouds[i].first >=N) clouds[i].first-=N;
            while(clouds[i].second >=N) clouds[i].second-=N;
            while(clouds[i].first <0) clouds[i].first+=N;
            while(clouds[i].second <0) clouds[i].second+=N;
        }
//        cout<<"after 구름이동"<<endl;
//        for(int i=0; i<N; i++){
//            for(int j=0; j<N; j++){
//               cout <<grid[i][j]<<" ";
//            }
//            cout <<endl;
//        }
//        cout <<endl;


        // 대각선에 있는 물에 따라서 비 내기기. (한번에 몰아서 내려야 함)
        vector<pair<int, int> > rains;
        vector<vector<bool> > visited(N, vector<bool>(N, false));
        for(int i=0; i<clouds.size(); i++) {
            int r = clouds[i].first;
            int c = clouds[i].second;
            visited[r][c] = true;
            grid[r][c]++;
        }
        for(int i=0; i<clouds.size(); i++){
            int r = clouds[i].first;
            int c = clouds[i].second;

            for(int j=0; j<4; j++){
                int nr = r+D2[j][0];
                int nc = c+D2[j][1];
                if(nr>=N || nr<0 || nc>=N || nc<0 || grid[nr][nc]<=0) continue;
                rains.push_back(make_pair(r, c));
            }
        }

        for(int i=0; i<rains.size(); i++){
            int r = rains[i].first;
            int c = rains[i].second;
            grid[r][c]++;
        }
//        cout<<"after 비내리기"<<endl;
//        for(int i=0; i<N; i++){
//            for(int j=0; j<N; j++){
//                cout <<grid[i][j]<<" ";
//            }
//            cout <<endl;
//        }
//        cout <<endl;


        clouds.clear();
        // 구름 생성
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j]==false && grid[i][j]>=2){
                    grid[i][j]-=2;
                    clouds.push_back(make_pair(i, j));
                }
            }
        }
//        cout<<"after 구름생성"<<endl;
//        for(int i=0; i<N; i++){
//            for(int j=0; j<N; j++){
//                cout <<grid[i][j]<<" ";
//            }
//            cout <<endl;
//        }
//        cout <<endl;
    }
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ans += grid[i][j];
        }
    }
    cout <<ans<<endl;

    return 0;
}
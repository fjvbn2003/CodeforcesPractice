#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int n;
vector<vector<int> > top;
vector<vector<int> > bottom;
int D[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<int> > visited;
int score = 0;
void bfs(int y, int x){
    // 0이면 비어있는 상태
    if(bottom[y][x]==0) return;
    visited.clear();
    visited.resize(n, vector<int>(n,0));
    score = 1;
    queue<pair<int, int > > q;
    q.push({y,x});
    int val =  bottom[y][x];
    visited[y][x] = val;
    while(!q.empty()){
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = cur_y+D[i][0];
            int nx = cur_y+D[i][1];
            if(ny>=n || ny<0 || nx>=n || nx<0 || visited[ny][nx]>0 || bottom[ny][nx] != val) continue;
            visited[ny][nx] = val;
            q.push({ny, nx});
            score++;
        }
    }
    return;
}
long long relax(){
    long long ret = score;
    int up,down,left, right;
    up = -1;
    down = 30;
    left = 30;
    right = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] >0){
                up = max(up, i);
                down = min(down, i);
                left = min(left, j);
                right = max(right, j);
                bottom[i][j] = 0;
            }
        }
    }
    ret += (right-left+1)*(up-down+1);
    for(int j=0; j<n; j++){
        int start = 0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(visited[i][j]>0){
                if(start == 0) start = i;
                cnt++;
            }
        }

        //         cout <<"in visited"<<endl;
        // for(int ii=0; ii<n; ii++){
        //     for(int jj=0; jj<n; jj++){
        //       cout << visited[ii][jj]<<" ";
        //     }
        //   cout <<endl;
        // }
    
        // cout <<"start: "<<start<<endl;
        // cout<<"cnt : "<<cnt<<endl;
        if(cnt==0) continue;
        for(int i=start; i<n-cnt; i++){
            bottom[i][j] = bottom[i+cnt][j];
        }

        for(int i=n-cnt; i<n; i++){
            bottom[i][j] = 0;
        }
        // 처음 0;
        int first_zero = 0;
        for(int i=0; i<n; i++){
            if(bottom[i][j] == 0) {
                first_zero = i;
                break;
            }
        }
        int need_num = max(n, n-first_zero);
        int ccnt = 0;
        for(int i=first_zero; i<first_zero+need_num && i<n; i++){
            bottom[i][j] = top[i-first_zero][j];
            ccnt++;
        }
        for(int i=0; i<2*n-ccnt; i++){
            top[i][j] = top[i+ccnt][j];
        }
        for(int i=2*n-ccnt; i<2*n; i++){
            top[i][j] = 0;
        }
    }
    return ret;
}

int main(int argc, char** argv)
{
    cin>>n;
    // 한 턴당 최대 n*n가지 경우의 수.unique하다면 건너뛸 수 있음.
    top.resize(2*n,vector<int>(2*n,0));
    bottom.resize(n, vector<int>(n,0));
    for(int i=(2*n)-1; i>=0; i--){
        for(int j=0; j<n; j++){
            cin>>top[i][j];
        }
    }
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            cin>>bottom[i][j];
        }
    }
    // DEBUGGING
    // for(int i=0; i<2*n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << top[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }
    long long ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            auto t = top;
            auto b = bottom; 

            bfs(i, j);
            long long s = relax();


            for(int k=0; k<n; k++){
                for(int l=0; l<n; l++){
                    auto tt = top;
                    auto bb = bottom; 
                    bfs(i, j);
                    long long ss = relax();
                    for(int k=0; k<n; k++){
                        for(int l=0; l<n; l++){
                            auto ttt = top;
                            auto bbb = bottom; 
                            bfs(i, j);
                            long long sss = relax();
                            if(ans < (s+ss+sss)){
                                ans = (s+ss+sss);
                                // cout <<"s, "<<s<<" ss "<<ss<< " sss "<<sss<<endl;
                                // for(int i=0; i<2*n; i++){
                                //     for(int j=0; j<n; j++){
                                //         cout << top[i][j]<<" ";
                                //     }
                                //     cout <<endl;
                                // }
                            } 

                            top = ttt;
                            bottom = bbb;
                        }
                    }
                    top = tt;
                    bottom = bb;
                }
            }
            top = t;
            bottom = b;
        }
    }
    
    // cout <<"before"<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //       cout << bottom[i][j]<<" ";
    //     }
    //   cout <<endl;
    // }
    // bfs(1,1);
    // cout <<"after visited"<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //       cout << visited[i][j]<<" ";
    //     }
    //   cout <<endl;
    // }
    
    // long long s = relax();

    // cout <<"after bottom"<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //       cout << bottom[i][j]<<" ";
    //     }
    //   cout <<endl;
    // }
    // cout <<"after top"<<endl;
    // for(int i=0; i<2*n; i++){
    //     for(int j=0; j<n; j++){
    //       cout << top[i][j]<<" ";
    //     }
    //   cout <<endl;
    // }
    cout <<ans<<endl; 
    return 0;
}
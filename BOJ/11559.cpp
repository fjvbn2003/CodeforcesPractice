#include <iostream>
#include <vector>
#include <string>
using namespace std;
char arr[12][6];
int visited[12][6];
int visited2[12][6];

int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
//dfs를 돌면서 해당 칸과 같은 칸들을 빈칸으로 바꾸는 함수
void dfs_mark(int y, int x){
    visited2[y][x] = 1;
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny>=12 || ny<0 || nx>=6 || nx<0 || arr[ny][nx]=='.' || visited2[ny][nx] || arr[y][x] != arr[ny][nx]){
            continue;
        }
        dfs_mark(ny,nx);   
    }
    arr[y][x] = ' ';
    return;
}
// dfs를 돌면서 해당 칸과 같은 칸이 몇칸인지를 리턴하는 함수
int dfs(int y, int x){
    if(visited[y][x] || arr[y][x]=='.') return 0;
    visited[y][x] =1;
    int ret = 1;
    for(int i=0; i<4; i++){
        int ny = y+dy[i];
        int nx = x+dx[i];

        if(ny>=12 || ny<0 || nx>=6 || nx<0 || arr[ny][nx]=='.' || visited[ny][nx] || arr[y][x] != arr[ny][nx]){
            continue;
        }
        ret += dfs(ny,nx);   
    }
    return ret;
}

int main(){
    string s;
    cin.tie(0);
    for(int i=0; i<12; i++){
        cin>>s;
        for(int j=0; j<6; j++){
            arr[i][j] = s[j];
        }
    }
    bool flag = true;
    int ans =0;
    while(flag){
        flag = false;
        for(int i=0; i<12; i++){
            for(int j=0; j<6; j++){
                if(visited[i][j] || arr[i][j]=='.'){continue;}
                if(dfs(i,j) >=4 ){//만약 4칸 이상이라면 빈칸으로 칠한다.
                    dfs_mark(i,j);
                    flag =true;
                }
            }
        }
        if(!flag){break;}
        // for(int i=0; i<12; i++){
        //     for(int j=0; j<6; j++){
        //         cout <<arr[i][j];
        //     }
        //     cout <<endl;
        // }
        // 빈칸들을 만나면 한칸씩 내린다.
        for(int j=0; j<6; j++){
            for(int i=11; i>=1; i--){
                while(arr[i][j]==' '){
                    for(int k=i; k>=1; k--){
                        if(arr[k][j]=='.' && arr[k-1][j]=='.'){break;}
                        arr[k][j] = arr[k-1][j];
                        if(k==1){arr[k-1][j] = '.';}
                    }
                }
            } 
        }
        // visited, visited2 배열 초기화
        for(int i=0; i<12; i++){
            for(int j=0; j<6; j++){
                visited[i][j] = 0;
                visited2[i][j] = 0;
            }
        }
        ans++;
    }
    cout <<ans<<endl;
    return 0;
}
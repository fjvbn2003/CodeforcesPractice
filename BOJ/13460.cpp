#include <iostream>
#include <string>
#include <vector>
using namespace std;
char grid[11][11];
int n,m;
int ans = 11;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
// if return value is '0' means normal case (no one is in the hole)
// if return value is  '1' means red is hole 
// if return value is  '2' means blue is hole 

int move(int dir, pair<int,int> &red, pair<int, int> &blue){
    // blue

    int ny = blue.first + dy[dir];
    int nx = blue.second + dx[dir];
    int dist_b = 0;
    while(grid[ny][nx] != '#' && grid[ny][nx] != 'O'){
        blue.first  = ny;
        blue.second = nx;
        dist_b++;
        //cout << "blue: "<<blue.first<<" "<<blue.second<<endl;
        //cout<< grid[ny][nx]<<endl;
        ny = blue.first + dy[dir];
        nx = blue.second + dx[dir];
    }
    if(grid[ny][nx] == 'O' ){
        return 2;
    }


    // red
    ny = red.first + dy[dir];
    nx = red.second + dx[dir];
    int dist_r = 0;
    while(grid[ny][nx] != '#' && grid[ny][nx] != 'O'){
        red.first  = ny;
        red.second = nx;
        dist_r++;
        ny = red.first + dy[dir];
        nx = red.second + dx[dir];
    }
    if(grid[ny][nx] == 'O' ){
        return 1;
    }
    if(blue.first == red.first && red.second == blue.second){
        if(dist_b>dist_r){
            blue.first-= dy[dir];
            blue.second-= dx[dir];
        }else if(dist_b<dist_r){
            red.first -= dy[dir];
            red.second -= dx[dir];
        }
    }
    //cout << "red: "<<red.first<<" "<<red.second<<endl;
    return 0;

}

// times번째 dir 방향으로 기울였을 때
void bf(int times, int dir, pair<int,int> red, pair<int, int> blue){
    if(times>=10){return;}
    //cout <<"in bf: "<< "times"<<times<<" dir: "<<dir<<endl;
    int t = move(dir, red, blue);
    if(t == 0){

    }else if(t == 1){
        ans = min(ans, times+1);
        return;
    }else{
        return;
    }
    for(int i=0; i<4; i++){
        bf(times+1, i, red, blue);
    }
    return;
}

int main(){
    pair<int,int> red;
    pair<int, int> blue;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>> grid[i][j];
            if(grid[i][j] == 'R'){
                red.first = i;
                red.second=j;
                grid[i][j] = '.';
            } 
            if(grid[i][j] == 'B'){
                blue.first = i;
                blue.second = j;
                grid[i][j] = '.';
            }
        }
    }
    for(int i=0; i<4; i++){
        bf(0, i, red, blue);
    }
    if(ans == 11){
        cout <<-1<<endl;
    }else{
        cout <<ans<<endl;
    }
    return 0;
}
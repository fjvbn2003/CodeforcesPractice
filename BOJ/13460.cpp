#include <iostream>
#include <string>
#include <vector>
using namespace std;
char arr[11][11];
int n,m;
int ans = 11;
// 0: east, 1:south, 2:west, 3:north
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
pair<int, int> blue = {0,0};
pair<int, int> red = {0,0};
pair<int, int> hole = {0,0};

// 1:success 2:goal 3:dont_move 4:blue_hole
// need to implement carefully move function
int move(int dir){
    int blue_y = blue.first;
    int blue_x = blue.second;
    int red_y = red.first;
    int red_x = red.second;
    
    while(true){
        blue_y += dy[dir];
        blue_x += dx[dir];
        if(arr[blue_y][blue_x]=='#'){
            blue_y -= dy[dir];
            blue_x -= dx[dir];
            break;
        }
        if(arr[blue_y][blue_x]=='O'){
            return 4;
        }
    }
    while(true){
        red_y += dy[dir];
        red_x += dx[dir];
        if(arr[red_y][red_x]=='#'){
            red_y -= dy[dir];
            red_x -= dx[dir];
            break;
        }
        if(arr[red_y][red_x]=='O'){
            //for debugging
            for(int i=0;i<n; i++){
                for(int j=0; j<m; j++){
                    cout<<arr[i][j];
                }
                cout <<endl;
            }
            cout <<endl<<endl;
                

            return 2;
        }
    }
    if(red_y == blue_y && red_x == blue_y){
        if(dir == 0 || dir == 2){
            if(blue.second < red.second){
                blue_y -= dy[dir];
                blue_x -= dx[dir];
            }else{
                red_y -= dy[dir];
                red_x -= dx[dir];
            }
        }else{
            if(blue.first < red.first){
                blue_y -= dy[dir];
                blue_x -= dx[dir];
            }else{
                red_y -= dy[dir];
                red_x -= dx[dir];
            }
        }
    }
    if(blue.first == blue_y && blue.second == blue_x && red.first == red_y && red.second == red_x){
        return 3;
    }
    // arr[blue.first][blue.second] = '.';
    // arr[red.first][red.second] = '.';
    arr[blue_y][blue_x] = 'B';
    arr[red_y][red_x] = 'R';
    blue.first = blue_y;
    blue.second = blue_x;
    red.first = red_y;
    red.second = red_x;
    return 1;
}
void brute(int times){
    if(times>=10) return;
    int blue_y = blue.first;
    int blue_x = blue.second;
    int red_y = red.first;
    int red_x = red.second;
    for(int i=0; i<4; i++){
        int t = move(i);
        if(t==1){
            brute(times+1);
        }else if(t==2){
            if(ans>times+1) ans = times+1;
        }

        // return original position
        blue.first = blue_y;
        blue.second = blue_x;
        red.first = red_y;
        red.second = red_x;
        arr[blue_y][blue_x] = 'B';
        arr[red_y][red_x] = 'R';
    }
    return ;
}


int main(){
    string s;
    cin>>n>>m;
    for(int i=0;i<n; i++){
        cin>> s;
        for(int j=0; j<m; j++){
            arr[i][j] = s[j];
            if(s[j]=='B') blue = {i,j};
            if(s[j]=='R') red = {i,j};
            if(s[j]=='O') hole = {i,j};
        }
    }
    brute(0);
    if(ans == 11){
        cout <<-1<<endl;;
    }else{
        cout <<ans<<endl;
    }
    return 0;
}
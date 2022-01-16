#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C, K;
int cnt =0;
vector<vector<char> > arr;
vector<vector<int> > visited;
int D[4][2] = {{1,0},{0,1},{-1,0},{0, -1} };
void brute(int r, int c, int len){
    if(arr[r][c]== 'T') return;
    
    if(r==0 && c==C-1 && len==K){
        cnt++;
        return;
    }
    for(int i=0; i<4; i++){
        int nr = r+ D[i][0];
        int nc = c+ D[i][1];
        if(nr<0 || nr>=R || nc<0 || nc>=C) continue;
        if( arr[nr][nc] != 'T' && visited[nr][nc] ==0){
            visited[nr][nc]  =1;
            brute(nr, nc, len+1);
            visited[nr][nc]  = 0;
        }
    }
    return;
}


int main(){
    cin>>R>>C>>K;
    arr.resize(R, vector<char>(C));
    visited.resize(R, vector<int>(C, 0));

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cin>> arr[i][j];
    if(arr[R-1][0] != 'T'){
        visited[R-1][0] = 1;
        brute(R-1, 0, 1);
        visited[R-1][0] = 0;

    }

    // for(int i=0; i<R; i++){
    //     for(int j=0; j<C; j++){
    //         cout <<arr[i][j]<<" ";
    //     }
    //     cout <<endl;
    // }
    cout << cnt<<endl;
        
    return 0;

}
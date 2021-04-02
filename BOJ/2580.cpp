#include <iostream>
#include <vector>
using namespace std;
int row[9][10];
int col[9][10];
int arr[9][9];
int cnt = 0;

vector<pair<int, int> > zero;

bool check(int r, int c, int t){
    int j = r/3;
    int k = c/3;
    for(int l=j*3; l<j*3+3; l++ ){
        for(int m=k*3; m<k*3+3; m++){
            if(l==r && m==c) continue;
            if(arr[l][m] == t) return false;
        }
    }
    return true;
}
void dfs(int n){
    if(n==cnt){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << arr[i][j]<<" ";
            }
            cout <<endl;
        }
        exit(0);
    }
    pair<int, int> p = zero[n];
    for(int i=1; i<=9; i++){
        if(row[p.first][i] == 0 && col[p.second][i] == 0 && check(p.first, p.second, i)){
            row[p.first][i] = 1;
            col[p.second][i] = 1;
            arr[p.first][p.second] = i;
            dfs(n+1);
            arr[p.first][p.second] = 0;
            row[p.first][i] = 0;
            col[p.second][i] = 0;
        }
    }
}



int main(){
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>arr[i][j];
            
            if(arr[i][j] == 0){
                cnt++;
                zero.push_back({i,j});
            }else{
                row[i][arr[i][j]] = 1;
                col[j][arr[i][j]] = 1;
            }
        }
    }
    dfs(0);
    return 0;
   
}
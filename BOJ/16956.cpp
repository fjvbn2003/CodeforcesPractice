#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int r,c;
    char arr[501][501];
    vector<pair<int, int> > sheep;
    vector<pair<int, int> > wolves;
    
    cin>> r>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>> arr[i][j];
            if(arr[i][j]=='S'){
                sheep.push_back({i,j});
            }
            if(arr[i][j]=='W'){
                wolves.push_back({i,j});
            }
        }
    }
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,-1,1};
    bool flag  = false;
    for(int i=0; i<sheep.size(); i++){
        auto t = sheep[i];
        
        for(int j=0; j<4; j++){
            int ny = t.first +dy[j];
            int nx = t.second+dx[j];
            if(ny>=0 && ny<r && nx>=0 && nx <c && arr[ny][nx]=='W'){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    if(!flag){
        for(int i=0; i<wolves.size(); i++){
            auto t = wolves[i];
        
            for(int j=0; j<4; j++){
                int ny = t.first +dy[j];
                int nx = t.second+dx[j];
                if(ny>=0 && ny<r && nx>=0 && nx <c && arr[ny][nx] !='W'){
                arr[ny][nx] = 'D';
                }
            }
        }
        cout <<1<<endl;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout << arr[i][j];
            }
            cout <<'\n';
        }
        return 0;
    }
    else{
        cout <<0<<endl;
        return 0;
    }

}
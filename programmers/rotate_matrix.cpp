#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int mini = 1e9;
vector<int> answer;
vector<vector<int> > arr;
int move_one(pair<int,int> start, pair<int, int> end, int last){
    int ret = arr[end.first][end.second];
    mini = min(mini, ret);
    mini = min(mini, last);

    if(start.first == end.first){
        if(start.second<end.second){
            for(int i=end.second-1; i>= start.second+1; i--){
                mini = min(mini,arr[start.first][i]);
                arr[start.first][i+1] = arr[start.first][i];
            }
            arr[start.first][start.second+1] = last;
        }else{
            for(int i=end.second+1; i<= start.second-1; i++){
                mini = min(mini,arr[start.first][i]);
                arr[start.first][i-1] = arr[start.first][i];
            }
            arr[start.first][start.second-1] = last;
        }

    }else if(start.second ==  end.second){
        if(start.first<end.first){
            for(int i=end.first-1; i>= start.first+1; i--){
                mini = min(mini, arr[i][start.second]);
                arr[i+1][start.second] = arr[i][start.second];
            }
            arr[start.first+1][start.second] = last;
        }else{
            for(int i=end.first+1; i<= start.first-1; i++){
                mini = min(mini, arr[i][start.second]);
                arr[i-1][start.second] = arr[i][start.second];
            }
            arr[start.first-1][start.second] = last;
        }

    }else{
        cout<< "not matching point"<<endl;
        return 0;
    }
    return ret;

}

int rotate(int y1, int x1, int y2, int x2){
    pair<int,int> p1,p2,p3,p4;
    // p1 p2 p3 p4는 시계방향
    if(x1<x2){
        p1 = {y1,x1};
        p3 = {y2,x2};
        if(y1<y2){
            p2 = {y1,x2};
            p4 = {y2,x1};          
        }else{
            p2 = {y2,x1};
            p4 = {y1,x2};
        }
    }else{
        p1 = {y2,x2};
        p3 = {y1,x1};
        if(y1<y2){
            p2 = {y1,x2};
            p4 = {y2,x1};          
        }else{
            p2 = {y2,x1};
            p4 = {y1,x2};
        }
    }
    int last = move_one(p1, p2, arr[p1.first][p1.second]);
    last = move_one(p2, p3, last);
    last = move_one(p3, p4, last);
    last = move_one(p4, p1, last);
    return mini;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    arr.resize(rows, vector<int>(columns,0));
    int cnt = 1;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            arr[i][j] = cnt;
            cnt++;
        }
    }
    for(auto query : queries ){
        mini = 1e9;
        answer.push_back(rotate(query[0]-1,query[1]-1,query[2]-1,query[3]-1 ));
    }

    return answer;
}
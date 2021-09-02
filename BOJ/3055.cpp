#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int r, c;
vector<vector<char> >arr;
pair<int, int> start;
pair<int, int> dest;
queue<pair<int, int> > water_queue;
vector<vector<int> > water_map;
int D[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void make_water_map(){
  while(!water_queue.empty()){

    int cur_r = water_queue.front().first;
    int cur_c = water_queue.front().second;
    water_queue.pop();
    for(int i=0; i<4; i++){
      int nr = cur_r+D[i][0];
      int nc = cur_c+D[i][1];
      if(nr <0 || nr>=r || nc<0 || nc>=c || arr[nr][nc]!='.' || water_map[nr][nc] != 1e9) continue;
      water_queue.push({nr, nc});
      water_map[nr][nc] = water_map[cur_r][cur_c]+1;
    }
  }
}

int main(){
  string s;
  cin>> r>>c;
  arr.resize(r, vector<char> (c,'.'));
  water_map.resize(r, vector<int>(c,1e9));

  // input map
  for(int i=0; i<r; i++){
    cin>> s;
    for(int j=0; j<c; j++){
      arr[i][j] = s[j];
      if(s[j]=='*'){
        water_queue.push({i,j});
        water_map[i][j] = 0;
      }else if(s[j] == 'S'){
        start.first = i;
        start.second = j;
      }else if(s[j] == 'X'){
        continue;
      }else if(s[j] == 'D'){
        dest.first = i;
        dest.second = j;
      }else{// s[c] == '.'
        continue;
      } 
    }
  }
  // make water map
  make_water_map();
  // for(int i=0; i<r; i++){
  //   for(int j=0;j<c; j++){
  //     cout <<water_map[i][j]<<" ";
  //   }
  //   cout <<endl;
  // }
  vector<vector<int> > visited(r, vector<int>(c,1e9));
  queue<pair<int, int> > q;
  q.push({start.first, start.second});
  visited[start.first][start.second] = 0;
  while(!q.empty()){
    int cur_r = q.front().first;
    int cur_c = q.front().second;
    q.pop();
    if((cur_r == dest.first) && (cur_c == dest.second) ){
      // cout << "cur_r: "<<cur_r<<" cur_c: "<<cur_c<<" "<<visited[cur_r][cur_c]<<endl;
      break;
    }
    for(int i=0; i<4; i++){
      int nr = cur_r + D[i][0];
      int nc = cur_c + D[i][1];
      // cout <<"nr: "<< nr<<" nc: "<<nc<<endl;
      if(nr <0 || nr>=r || nc<0 || nc>=c || arr[nr][nc]=='X' || water_map[nr][nc] <= visited[cur_r][cur_c]+1 || visited[nr][nc] != 1e9) continue;
      // if((nr == dest.first) && (nc == dest.second) ){
      //   // cout <<"push dest in: "<<cur_r<<" "<<cur_c<<endl;
      //   // cout <<"nr: "<< nr<<" nc: "<<nc<<endl;
      //   // cout <<"D[i][0]: "<<D[i][0]<<"  D[i][1]: "<<D[i][1]<<endl;
      // }
      q.push({nr, nc});
      visited[nr][nc] = visited[cur_r][cur_c]+1;
    }
  }
  // for(int i=0; i<r; i++){
  //   for(int j=0;j<c; j++){
  //     cout <<visited[i][j]<<" ";
  //   }
  //   cout <<endl;
  // }
  if(visited[dest.first][dest.second] == 1e9){
    cout <<"KAKTUS"<<endl;
  }else{
    cout <<visited[dest.first][dest.second]<<endl;
  }
  return 0;
  

}
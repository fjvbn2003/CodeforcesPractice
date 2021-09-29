#include <iostream>
#include <vector>

using namespace std;
int D[4][2] = {{0,1},{-1,0}, {0, -1},{1, 0}};

vector<int> dragon_find(int dir, int gener){
  vector<int> ret;
  ret.push_back(dir);
  while(gener--){
    int n = ret.size();
    for(int i=n-1; i>=0; i--){
      ret.push_back((ret[i]+1)%4);
    }
  }
  return ret;
}


int main(){
  int n;
  int x,y,d,g;
  cin>>n;
  vector<vector<int> > arr (101, vector<int>(101, 0));
  for(int i=0; i<n; i++){
      cin>>x>>y>>d>>g;
      vector<int> dir = dragon_find(d, g);
      //cout <<"hi"<<endl;
      arr[y][x] =1;
      int ny =y;
      int nx = x;
      for(int i=0; i<dir.size(); i++){
        ny += D[dir[i]][0];
        nx += D[dir[i]][1];
        arr[ny][nx] = 1;
      }
  }
  // for(int i=0; i<10; i++){
  //   for(int j=0;j<10; j++){
  //     cout <<arr[i][j]<<" ";
  //   }
  //   cout <<endl;
  // }
  int ans = 0;
  for(int i=0; i<100; i++){
    for(int j=0;j<100; j++){
      if(arr[i][j]  && arr[i][j+1] && arr[i+1][j] && arr[i+1][j+1]){
        ans++;
      }
    }
  }
  cout <<ans<<endl;
}
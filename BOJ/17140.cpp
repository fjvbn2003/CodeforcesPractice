#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<vector<int> > row;
vector<vector<int> > col;
bool comp(const pair<int, int> &a , const pair<int, int> &b){
  if(a.first == b.first)
    return a.second<b.second;
  return a.first> b.first;
}
int main(){
  int r,c,k;
  row.resize(3, vector<int>(3,0));
  col.resize(3, vector<int>(3,0));
  // 초깃 값;
  r--;
  c--;
  int ans = 0;
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin>> row[i][j];
      cin>> col[j][i];
    }
  }
  do{
    if(row[r][c] == k){
      break;
    }
    int m_r = col.size();
    int m_c = row.size();
    
    if(m_r >= m_c){
      // row 행렬을 조작.
      // 부족한 부분 채우기.
      for(int i=0; i<m_r; i++){
        //배열 초기화
        vector<pair<int, int> > m(101, {0,0});
        for(int i=0; i<101; i++) m[i].second = i;
        for(int j=0; j< row[i].size(); j++){
          m[row[i][j]].first++;
        }
        // 정렬.
        sort(m.begin(), m.end(), comp);
        row[i].clear();
        for(int i=0; i<m.size(); i++){
          if(m[i].first ==0) break;
        }

      }


    }else{
      // col 행렬을 조작.
      // 부족한 부분 채우기.

    }
    ans++;
  }while(ans<100);

  if(ans != 100){
    cout << ans<<endl;
  }else{
    cout << -1 << endl;
  }
  return 0;
}
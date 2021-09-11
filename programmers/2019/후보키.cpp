#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int row, col;

bool possible(int key, vector<vector<string> > &rel){
  // 모든 쌍을 검사
  for(int i=0; i<row; i++){
    for(int j=i+1; j<row; j++){
      // 다른게 하나라도 있어야 한다.
      bool all_same = true;
      for(int k=0; k<col; k++){
        if((1<<k)&key){
          if(rel[i][k] != rel[j][k]){
            all_same = false;
            break;
          }
        }
      }
      if(all_same == true){
        return false;
      }
    }   
  }
  return true;
}
int bit_count(int key){
  int ret = 0;
  while(key){
    ret += key%2;
    key/=2;
  }
  return ret;
}
int solution(vector<vector<string>> relation) {
    int answer = 0;
    row = relation.size();
  col = relation.front().size();;
  vector<pair<int, int> > cand;
  for(int key =1; key < (1<<col); key++){
    if(possible(key, relation)){
      cand.push_back({bit_count(key),key});
    }
  }
  sort(cand.begin(), cand.end());
  for(vector<pair<int, int> >::iterator it = cand.begin(); it != cand.end(); it++){
    int t = (*it).second;
    auto j = it;
    for(++j; j !=cand.end();){
      //cout << "from: "<<t<<" compare:"<<(*j).second<<endl;
      if((((*j).second)& t )== t){
        //cout << "from: "<<(*it).second<<" erase:"<<(*j).second<<endl;
        cand.erase(j);
      }else{
        ++j;
      }
    }
   // cout <<"finish "<<(*it).second<<endl;
  }
 return cand.size();
}
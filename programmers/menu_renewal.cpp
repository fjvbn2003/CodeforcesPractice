#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
multiset<string> ms;
vector<int> course;
void comb(string s, int idx, string ret){
  if(s.size()==idx){
    for(int i=0; i<course.size(); i++)
    if(ret.size() == course[i]){
      ms.insert(ret);
      return;
    }
    return;
  };
  comb(s, idx+1, ret+s[idx]);
  comb(s, idx+1, ret);
  return;
}

int main(){
  course.push_back(2);
  course.push_back(3);
  course.push_back(4);
  vector<string> order = {"ABCFG","AC", "CDE","ACDE", "BCFG","ACDEH"};
  for(string s : order){
    sort(s.begin(), s.end());
    comb(s, 0, "");
  }
  for(auto s : ms){
    cout <<s<<endl;
  }
}
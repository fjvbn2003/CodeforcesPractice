#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
unordered_map<string, int> um;
vector<int> course;
vector<int> course_max;
void comb(string s, int idx, string ret){
  if(s.size()==idx){
    for(int i=0; i<course.size(); i++)
      if(ret.size() == course[i]){
        if(um.count(ret)){
          um[ret]++;
          course_max[i] = max(course_max[i], um[ret]);
        }
        else{
          um.insert({ret,1});
          course_max[i] = max(course_max[i], um[ret]);
        }
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
  course.push_back(5);
  course_max.resize(course.size(),0);
  vector<string> order = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
  for(string s : order){
    sort(s.begin(), s.end());
    comb(s, 0, "");
  }
  vector<string> ans;
  for(auto s : um){
    for(int i=0; i<course.size(); i++){
      if(s.first.size() == course[i] && s.second == course_max[i] && s.second>=2){
        ans.push_back(s.first);
      }
    }
  }
  sort(ans.begin(), ans.end());
  for(int i=0; i<ans.size(); i++){
    cout << ans[i]<<" ";
  }
}
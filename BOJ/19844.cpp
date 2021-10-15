// 본질을 추구하자.
// 단 것을 줄이자.

#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
  string s;
  getline(cin, s);
  vector<string> arr;
  vector<string> post = {"c", "j", "n", "m", "t", "s", "l", "d", "qu"};
  vector<char> vowels = {'a','e','i','o','u', 'h'};
  
  int start = 0;
  while(true){
    int cand1 = s.find(" ", start);
    int cand2 = s.find("-", start);
    //cout <<"cand1 "<<cand1<<" cand2:"<<cand2<<endl;
    if(cand1== s.npos && cand2== s.npos){
      arr.push_back(s.substr(start));
      break;
    }
    if(cand2==s.npos){
      arr.push_back(s.substr(start, cand1-start));
      start = cand1+1;
    }else if(cand1 ==s.npos){
      arr.push_back(s.substr(start, cand2-start));
      start = cand2+1;
    }else if(cand1 < cand2){
      arr.push_back(s.substr(start, cand1-start));
      start = cand1+1;
    }else{
      arr.push_back(s.substr(start, cand2-start));
      start = cand2+1;
    }
  }
  int ans = arr.size();
  for(int i=0; i<arr.size(); i++){
    string tmp = arr[i];
    int start = 0;
    for(int j=0; j<tmp.size(); j++){
      if(tmp[j] == '\''){
        if((j-start !=1 && j-start !=2)  || j==tmp.size()-1) continue;
        // post단어에 있는것인지 탐색
        bool flag1 = false;
        for(int k=0; k<post.size(); k++){
          if(tmp.substr(start, j-start) == post[k]){
            flag1 = true;
            break;
          }
        }

        if(!flag1){
          start=j+1;
          continue;
        }

        bool flag2 = false;
        for(int k=0; k<vowels.size(); k++){
          if(tmp[j+1] == vowels[k]){
            flag2 = true;
            break;
          }
        }
        if(!flag2){
          start=j+1;
          continue;
        }

        ans++;
        //cout <<"find substr: "<<tmp.substr(start, j-start)<<" findvowels: "<<tmp[j+1]<<endl;
        start = j+2;
      }
    }
  }
  cout <<ans<<endl;
  return 0;
}
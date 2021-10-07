#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
  int n;
  vector<pair<int, string> > arr;
  vector<pair<int, string> > arr2;
  
  cin>>n;
  string s;
  for(int i=0; i<n; i++){
    cin>>s;
    arr.push_back({i, s});
    string tmp = "";
    // 문자열의 맨 앞, 맨 뒤만 잘라서 따로 배열을 만든다.
    tmp+=s.front();
    tmp+=s.back();
    arr2.push_back({i, tmp});
  }
  sort(arr2.begin(), arr2.end());
  
  int min_change = 123456789;
  vector<int> ans(n, 0);
  // 모든 경우의 수 계산.
  do{
    vector<char> tmp(n*2,' ');
    for(int i=0; i<arr2.size(); i++){
      tmp[i*2] = (arr2[i].second)[0];
      tmp[i*2+1] = (arr2[i].second)[1];
    }
    char before = tmp[0];
    int cnt = 0;
    for(int i=1; i<n*2; i++){
      if(before != tmp[i]) cnt++;
      before = tmp[i];
    }
    if(cnt< min_change){
      min_change = cnt;
      for(int i=0; i<n; i++){
        ans[i] = arr2[i].first;
      }
    }
  }while(next_permutation(arr2.begin(), arr2.end()));

  string ans_str = "";
  for(int i=0; i<n; i++){
    ans_str += arr[ans[i]].second;
  }
  char before = ans_str[0];
  int cnt =0;
  for(int i=1; i<ans_str.size(); i++){
    if(before != ans_str[i]) cnt++;
    before = ans_str[i];
  }

  cout <<cnt<<endl;
  return 0;
}
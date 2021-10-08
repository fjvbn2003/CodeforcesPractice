#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
// 정렬 함수를 제대로 작성하지 않아서 틀렸다.
// 그냥 정렬하면, a-123. a-4 중에 a-123이 앞에온다.
// 우리가 원하는 것은 a-4가 앞에 오는 것이기 때문에 정렬을 위한 compare 함수를 재정의 해줘야한다. 
bool comp( const string &a, const string &b){
  if(a[0] == b[0]){
    return stoi(a.substr(2)) < stoi(b.substr(2));
  }
  return a[0] <b[0];
}
int main(){
  int n;
  cin>>n;
  vector<string> arr;
  vector<string > arr2;
  string s;
  n*=5;
  for(int i=0; i<n; i++){
    cin>>s;
    arr.push_back(s);
    arr2.push_back(s);
  }
  sort(arr2.begin(), arr2.end(), comp);
  for(int i=0; i<arr2.size(); i++){
    cout <<arr2[i]<<" ";
  }
  cout <<endl;

  unordered_map<string, int> um;

  for(int i=0; i<arr2.size(); i++){
    um[arr2[i]] = i;
  }

  stack<int> st;
  bool flag = true;
  int cnt = 0;
  for(int i=0; i<arr.size(); i++){
    // 만약 원하는 숫자라면 바로 입장
    if(um[arr[i]] == cnt){
      cnt++;
      continue;
    }

    // 스택이 비어있으면 넣을 수 밖에 없음
    if(st.empty()){
      st.push(um[arr[i]]);
    }else{
      int idx = um[arr[i]];
      while(!st.empty() && st.top()==cnt){
        cnt++;
        st.pop();
      }
      if(idx == cnt){
        cnt++;
        continue;
      }
      if(!st.empty() && st.top()< idx){
        flag = false;
        break;
      }
      st.push(idx);
    }
  }
  if(flag==false){
    cout <<"BAD"<<endl;
    return 0;
  }
  while(!st.empty()){
    if(cnt != st.top()){
      flag = false;
      break;
    }
    cnt++;
    st.pop();
  }
  if(flag==false){
    cout <<"BAD"<<endl;
  }else{
    cout <<"GOOD"<<endl;
  }
  return 0;
}
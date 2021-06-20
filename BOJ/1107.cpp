#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
  int n;
  int m;
  int t;
  vector<int> btn;
  vector<int> goal;
  bool avail_button[10];
  cin>> n>>m;

  for(int i=0; i<10; i++) avail_button[i] = true;
  for(int i=0; i<m; i++){
    cin>>t;
    avail_button[t] = false;
  }
  
  for(int i=0; i<10; i++)
    if(avail_button[i])
      btn.push_back(i);
  t = n;
  while(t){
    goal.push_back(t%10);
    t/=10;
  }
  int ans = abs(n-100);
  reverse(goal.begin(), goal.end());
  // three case.
  // 작은게 있을 때는 계속 큰걸로
  // 큰게 있을 때는 계속 작은 걸로
  // 같다면 최대한 같도록 가기.
  
  // for(int i=0; i<goal.size(); i++){
  //   cout<<goal[i]<<" ";
  // }
  // cout <<endl;

  if(btn.size() == 0){
    cout <<ans<<endl;
    return 0;
  }
  bool small = false;
  bool big  = false;
  vector<int> cand1;
  // small 먼저
  for(int i=0; i<goal.size(); i++){
    int tmp = btn[0];
    if(small==false){
      for(int j=0; j<btn.size(); j++){
        if(btn[j]<=goal[i]) tmp = btn[j];
      }
    }else{
      //최댓값으로 넣어줌
      tmp = btn[btn.size()-1];
    }
    if(tmp <goal[i]) small  = true;
    // cout <<tmp<<endl;
    cand1.push_back(tmp);
  }
  // for(int i=0; i<goal.size(); i++){
  //   cout<<goal[i]<<" ";
  // }
  // cout <<endl;
  // for(int i=0; i<cand1.size(); i++){
  //   cout<<cand1[i]<<" ";
  // }
  // cout <<endl;
  vector<int> cand2;
  for(int i=0; i<goal.size(); i++){
    int tmp = btn.back();
    if(big ==false){
      for(int j=btn.size()-1; j>=0; j--){
        if(btn[j]>=goal[i]) tmp = btn[j];
      }
    }else{
      // 최솟값으로 넣어줌
      tmp = btn[0];
    }
    if(tmp >goal[i]) big  = true;
    cand2.push_back(tmp);
  }
  // for(int i=0; i<cand2.size(); i++){
  //   cout<<cand2[i]<<" ";
  // }
  // cout <<endl;
  int tmp = 0;
  for(int i=0; i<cand1.size(); i++){
    if(cand1[i]==0){
      cand1.erase(cand1.begin());
    }else{
      break;
    }
  }

  reverse(cand1.begin(), cand1.end());
  for(int i=0; i<cand1.size(); i++){
    tmp += pow(10,i)*cand1[i];
  }
  t = cand1.size();
  ans = min(ans, abs(n-tmp)+t );
  tmp = 0;
  reverse(cand2.begin(), cand2.end());
  for(int i=0; i<cand2.size(); i++){
    tmp += pow(10,i)*cand2[i];
  }
  t = cand2.size();
  ans = min(ans, abs(n-tmp)+ t);
  cout <<ans<<endl;
  return 0;
}
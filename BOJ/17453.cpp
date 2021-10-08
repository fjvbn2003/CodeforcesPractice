#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//-> 비트마스크로 풀려고 했지만 실패.

int bit_count(int bit){
  int t = bit;
  int ret = 0;
  while(t){
    ret += t%2;
    t/=2;
  }
  return ret;
}

int main(){
  int n, m;
  cin>>n>>m;
  vector<bool> arr(n);
  int original = 0;
  vector<vector<bool> > doors(m, vector<bool>(n, false));
  char bit;
  for(int i=0; i<n; i++){
    cin>> bit;
    arr[i] = (bit=='0') ?false: true;
    if(arr[i])
      original |= (1<<i);
  }

  for(int i=0; i<m; i++){
    for(int j=0; j<n; j++){
      cin>>bit;
      doors[i][j] = (bit=='0') ?false: true;
    }
  }
  // -n, -n+1 -n+2 .. 0 +1 +2 .. +n
  // ans[i] ==  i를 만들기 위해서 필요한 스위치 동작.
  vector<int> ans(2*n+1, -1);
  
  for(int i=0; i< (1<<m); i++){
    // m번 비트가 켜져있다면 스위치를 누름.
    //cout <<"i: "<<i<<endl;
    int tmp = original;
    for(int j=0; j<m; j++){
      // 만약 j번 비트가 켜져있다면 누른다.
      if(i&(1<<j)){
        //cout <<"hi j: "<<j<<endl;
        for(int k=0; k<doors[j].size(); k++){
          if(doors[j][k]){
            tmp ^= (1<<k);
            //cout <<"tmp: "<<tmp<<endl;
          }
        }
      }      
    }
    int one_cnt = bit_count(tmp);
    int val = one_cnt-(n-one_cnt)+n;
    // cout <<"one_count: "<<one_cnt<<endl;
    // cout <<"val: "<<val<<endl;
    // cout <<"tmp: "<<tmp<<endl;
    if(ans[val] ==-1){
      ans[val] = i;
    }else{
      continue;
    }
    // cout <<"hi"<<endl;
  }
  // for(int i=0; i<ans.size(); i++){
  //   cout <<"i: "<<i<<" ans[i]: "<<ans[i]<<endl;
  // }
  for(int i=0; i<ans.size(); i++){
    if(ans[i] == -1){
      cout <<-1<<endl;
    }else{
      cout <<bit_count(ans[i])<<" ";
      for(int j=0; j<n; j++){
        if(ans[i] & (1<<j)){
          cout << (j+1)<<" ";
        }
      }
      cout <<endl;
    }
  }

  return 0;





  // for debugging
  // for(int i=0; i<n; i++){
  //   cout << arr[i]<<" ";
  // }

    
  


}
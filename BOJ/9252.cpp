#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string a;
string b;

void m_find(int b_idx, int a_idx, vector<vector<int> > & arr , vector<char> & ans){


  if(a_idx==0 && b_idx==0) {
    if(b[b_idx]== a[a_idx] && (max(arr[b_idx][a_idx-1],arr[b_idx-1][a_idx])-1 == arr[0][0]) ){
      ans.push_back(a[a_idx]);
    }
    return;
  }
  else if(a_idx==0){
    if(arr[b_idx-1][a_idx]+1 == arr[b_idx][a_idx]){
        ans.push_back(a[a_idx]);
    }
    m_find(b_idx-1, a_idx, arr, ans);
  }else if(b_idx==0){
    if(arr[b_idx][a_idx-1]+1 == arr[b_idx][a_idx]){
      ans.push_back(a[a_idx]);
    }
    m_find(b_idx, a_idx-1, arr, ans);
  }else{
    if(arr[b_idx][a_idx-1] >= arr[b_idx-1][a_idx]){
      if(arr[b_idx][a_idx-1]+1 == arr[b_idx][a_idx]){
        ans.push_back(a[a_idx]);
      }
      m_find(b_idx, a_idx-1, arr, ans);
    }else{
      if(arr[b_idx-1][a_idx]+1 == arr[b_idx][a_idx]){
        ans.push_back(a[a_idx]);
      }
      m_find(b_idx-1, a_idx, arr, ans);
    }
  }
  return;
}

int main(){
  
  cin>>a;
  cin>>b;

  int na = a.size();
  int nb = b.size();
  vector< vector<int> > arr(nb, vector<int>(na, 0));

  for(int i=0; i<na; i++){
    if(a[i]==b[0]){
      arr[0][i] =1;
    }
  }
  for(int i=0; i<nb; i++){
    if(a[0]==b[i]){
      arr[i][0] =1;
    }
  }

  for(int i=1; i<nb; i++){
    for(int j=1; j<na; j++){
      if(b[i] == a[j]){
        arr[i][j] = max(max(arr[i-1][j] , arr[i][j-1]), arr[i-1][j-1]+1);
      }else{
        arr[i][j] = max(arr[i-1][j] , arr[i][j-1]);
      }
    }
  }
  for(int i=0; i<nb; i++){
    for(int j=0; j<na; j++){
      cout <<arr[i][j]<<" ";
    }
    cout <<endl;
  }

  if(arr[nb-1][na-1]==0){
    cout <<0<<endl;
  }else{
    cout << arr[nb-1][na-1]<<endl;
    // vector<char> ans;
    // m_find(nb-1, na-1, arr, ans);
    // for(int i=ans.size()-1; i>=0; i--){
    //   cout << ans[i];
    // }
    // cout <<endl;

  }
}
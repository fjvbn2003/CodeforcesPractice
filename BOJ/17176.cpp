#include <iostream>
#include <vector>
#include <string>
using namespace std;
// ignore를 반드시 해야함!
int main(){

  //freopen("input.txt","r", stdin);
  int n;
  cin>>n;
  vector<int> arr(53,0);
  vector<int> arr2(53,0);
  
  int t;
  for(int i=0 ; i<n; i++){
    cin>>t;
    arr[t]++;
  }
    
  // getline 사용법 반드시 기억하기.
  cin.ignore();
  string s;
  getline(cin, s);

  for(int i=0; i<s.size(); i++){
    if(s[i]>='A' && s[i]<='Z'){
      arr2[s[i]-'A'+1]++;
    }else if(s[i]>='a' && s[i]<='z'){
      arr2[s[i]-'a'+27]++;
    }else{
      arr2[0]++;
    }
  }
  // for(int i=0; i<53; i++){
  //   cout <<arr[i]<<" ";
  // }  
  // cout <<endl;
  // for(int i=0; i<53; i++){
  //   cout <<arr2[i]<<" ";
  // }  
  // cout <<endl;

  bool flag = true;
  for(int i=0; i<53; i++){
    if(arr[i] != arr2[i]){
      flag = false;
      break;
    }
  }
  if(flag){
    cout <<"y"<<endl;
  }else{
    cout <<"n"<<endl;
  }
  return 0;
}

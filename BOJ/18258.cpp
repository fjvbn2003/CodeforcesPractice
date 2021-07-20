#include <string>
#include <iostream>
#include <queue>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  string s;
  queue<int> q;
  int t;
  while(n--){
    cin>>s;
    if(s =="push"){
      cin>>t;
      q.push(t);
    }else if(s=="pop"){
      if(q.empty()){
        cout << -1<<'\n';
      }else{
        cout <<q.front()<<'\n';
        q.pop();
      }
    }else if(s=="size"){
      cout <<q.size()<<'\n';
    }else if(s=="empty"){
      cout <<q.empty()<<'\n';
    }else if(s=="front"){
      if(q.empty()){
        cout << -1<<'\n';
      }else{
        cout <<q.front()<<'\n';
      }
    }else if(s=="back"){
      if(q.empty()){
        cout << -1<<'\n';
      }else{
        cout <<q.back()<<'\n';
      }
    }
  }
return 0;


}
#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
  int test_case;
  string s,s2;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>> test_case;
  while(test_case--){
    deque<int> dq;
    cin>>s;
    int n;
    cin>>n;
    cin>>s2;
    int psum = 0;
    int digit = 1;
    for(int i=s2.size()-2; i>=0; i--){
      if(s2[i]>='0' && s2[i]<='9'){
        psum += digit*(s2[i]-'0');
        digit*=10;
      }else{
        if(psum>0){
          dq.push_front(psum);
          psum=0;
          digit = 1;
        }
      }
    }
    bool pop_front = true;
    bool error = false;
    for(int i=0; i<s.size(); i++){
      if(s[i]=='R'){
        pop_front = !pop_front;
        //cout <<"hi"<<pop_front<<endl;
      }else{
        if(dq.empty()){
          error = true;
          break;
        }else{
          if(pop_front){
            dq.pop_front();
          }else{
            dq.pop_back();
          }
        }
      }
    }
    if(error){
      cout <<"error"<<'\n';
    }else{
      if(pop_front){
        cout<<'[';
        if(dq.size()>0){
          for(int i=0; i<dq.size()-1; i++){
            cout <<dq[i]<<',';
          }
        }
        if(dq.size()>0){
          cout <<dq[dq.size()-1]<<']'<<endl;
        }else{
          cout <<']'<<endl;
        }
      }else{
        cout<<'[';
        if(dq.size()>0){
          for(int i=dq.size()-1; i>0; i--){
            cout <<dq[i]<<',';
          }
        }

        if(dq.size()>0){
          cout <<dq[0]<<']'<<endl;
        }else{
          cout <<']'<<endl;
        }
      }
    }
  }
  return 0;


}
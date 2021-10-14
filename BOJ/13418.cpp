#include <iostream>
#include <string>

using namespace std;

int main(){
  int n;
  cin>>n;
  string s;
  for(int j=0; j<n; j++){
    cin>>s;
    if(s.size()%2 == 0){
      for(int i=0; i<s.size(); i+=2){
        cout << s[i];
      }
      cout <<endl;
      for(int i=1; i<s.size(); i+=2){
        cout << s[i];
      }
      cout <<endl;
    }else{
      s = s+s;
      for(int i=0; i<s.size(); i+=2){
        cout << s[i];
      }
      cout <<endl;
      for(int i=1; i<s.size(); i+=2){
        cout << s[i];
      }
      cout <<endl;
    }
  }
  return 0;


}
#include <iostream>
#include <string>

using namespace std;

int main(){
  int test;
  cin>>test;
  while(test--){
    string s;
    int n;
    cin>>n;
    cin>>s;
    bool flag = false;
    int l=-1;
    int r =-1;
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        int a = 0;
        int b = 0;
        for(int k=i; k<=j; k++){
          if(s[k]=='a') a++;
          else b++;
        } 
        if(a==b) {
          flag = true;
          l = i;
          r = j;
          break;
        }
        if(flag) break;
      }
      if(flag) break;
    }
    if(flag){
      cout <<l+1<< " "<<r+1<<endl;
    }else{
      cout <<l<<" "<<r<<endl;
    }
  }

}
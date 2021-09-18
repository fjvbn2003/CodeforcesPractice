#include <iostream>
#include <string>

using namespace std;

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  if(s[n-1] =='o'){
    cout <<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  return 0;

}
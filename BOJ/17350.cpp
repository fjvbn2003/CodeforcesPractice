#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){
  int n;
  cin>>n;
  string s;
  bool flag = false;
  for(int i=0; i<n; i++){
    cin>>s;
    if(s =="anj"){
      flag = true;
    }
  }
  if(flag){
    cout << "뭐야;"<<endl;
  }else{
    cout <<"뭐야?"<<endl;
  }
  return 0;

}
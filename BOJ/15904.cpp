#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  getline(cin, s);
  char arr[4] = {'U', 'C', 'P', 'C'};
  int idx = 0;
  bool flag = true;
  for(int i=0; i<4; i++){
    idx = s.find(arr[i], idx);
    if(idx ==-1){
      flag = false;
      break;
    }
  }
  if(flag){
    cout <<"I love UCPC"<<endl;
  }else{
    cout <<"I hate UCPC"<<endl;
  }
  return 0;
  
}
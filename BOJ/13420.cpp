#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
  int n;
  cin>>n;
  cin.ignore();
  for(int i=0; i<n; i++){
    string s;
    getline(cin, s);
    stringstream ss(s);
    long long a,b,c;
    char t1, t2;
    ss>>a>>t1>>b>>t2>>c;
    long long ans;
    if(t1 == '*'){
      ans = a*b;
    }else if(t1 == '+'){
      ans = a+b;
    }else if(t1 == '-'){
      ans = a-b;
    }else if(t1 == '/'){
      ans = a/b;
    }
    if(c == ans){
      cout << "correct"<<endl;
    }else{
      cout <<"wrong answer"<<endl;
    }
  }

  return 0;
}
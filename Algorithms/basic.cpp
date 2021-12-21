#include <iostream>

using namespace std;
int main(){

  int a; // a라는 변수 선언 (정수) integer 
  a = 10;
  // 10
  a = a+ 20;
  cout << "a: "<<a <<endl;

  if( a == 40){
    cout<< "a는 40 입니다."<<endl;
  }else{
    cout<< "a는 40이 아닙니다."<<endl;
  }
}
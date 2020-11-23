#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printBinary(unsigned int n){
  vector<int> binary;
  while(n){
    binary.push_back(n%2);
    n/=2;
  }
  reverse(binary.begin(), binary.end());
  for(auto i : binary){
    cout <<i;
  }
  cout <<endl;
  return;
}
int main() {
  unsigned int a = 42;
  unsigned int b = 61;
  cout << "a의 10진법: "<<a<<" , 2진법: ";
  printBinary(a);
  cout << "b의 10진법: "<<b<<" , 2진법: ";
  printBinary(b);
  // a의 비트를 반전
  cout << "~a 의 결과 10진법: "<<~a<< " , 2진법: ";
  printBinary(~a);
  // a AND b
  unsigned int c = a&b;
  cout<< "a&b의 결과 10진법: "<<c<< " , 2진법: ";
  printBinary(c);
  // a OR b
  c = a|b;
  cout<< "a|b의 결과 10진법: "<<c<< " , 2진법: ";
  printBinary(c);
  // a XOR b
  c = a^b;
  cout<< "a^b의 결과 10진법: "<<c<< " , 2진법: ";
  printBinary(c);
  //왼쪽으로 한 칸 시프트, 곱하기2 42*2 = 84
  c = (a << 1);
  cout << " a << 1의 결과 10진법 "<<c<<" , 2진법: ";
  printBinary(c);
  //오른쪽으로 한 칸 시프트, 나누기2 42/2 = 21
  c = (a >> 1);
  cout << " a >> 1의 결과 10진법 "<<c<<" , 2진법: ";
  printBinary(c);
  return 0;
}
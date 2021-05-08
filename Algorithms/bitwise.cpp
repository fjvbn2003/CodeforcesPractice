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
  
  
  //공집합과 꽉찬 집합 구하기
  int fullPizza = (1<<20) -1;
  // 원소 추가
  int p = 3
  int toppings |= (1<<p);
  //원소 포함 여부 확인
  if(toppings & (1<<p)) cout << "pepperoni is in"<<endl;
  //원소의 삭제
  toppings &= ~(1<<p);
  //원소의 토글
  toppings ^= (1<<p);

  int a = 3;
  int b = 6
  
  //두 집합에 대해 연산하기.
  int added = (a|b);
  int intersection = (a&b);
  int removed = (a & ~b);
  int toggle = (a^b);

  //0의 갯수를 구하려면, __builtin_ctz(tppings)를 사용하면 된다.
  //최소 원소 찾기
  int firstTopping = (toppings & -toppings);
  // 최소원소 지우기
  toppings &= (toppings - 1);

  //모든 부분집합 순회하기
  for(int subset = pizza; subset;subset = ((subset-1)&pizza)){
    //subset은 pizza의 부분집합. 공집합은 순회하지 않음.
    
  }

  return 0;
}
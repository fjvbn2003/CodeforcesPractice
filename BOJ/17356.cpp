#include <iostream>
#include <cmath>
using namespace std;

int main(){
  double A,B;
  cin>>A>>B;
  double M = (B-A)/400;
  double ans = 1/(1+ pow(10, M));
  cout <<ans<<endl;
  return 0;

}
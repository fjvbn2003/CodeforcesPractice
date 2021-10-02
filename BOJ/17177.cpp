#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){

  vector<double> arr;
  int t;
  for(int i=0; i<3; i++){
    cin>>t;
    arr.push_back(t);
  }
  
  double d = arr[0];
  double a = d*d - arr[1]*arr[1];
  double b = d*d - arr[2]*arr[2];
  if(a<=0 || b <=0){
    cout <<-1<<endl;
    return 0;
  }
  a = sqrt(a);
  b = sqrt(b);
  double x = (a*b-arr[1]*arr[2]) /d;
  if(x <=0){
    cout << -1<<endl;  
    return 0;  
  }
  cout << round(x)<<endl;
  return 0;
}
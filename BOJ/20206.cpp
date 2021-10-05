#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
double A, B, C;
double y(double tt){
  return -(A/B)*tt -(C/B);
}
double x(double tt){
  return -(B/A)*tt -(C/A);
}

int main(){
  double x1,x2,y1,y2;
  cin>>A>>B>>C>>x1>>x2>>y1>>y2;
  bool flag = false;

  if(A==0){
    double t1 = -C/B;
    if(y1<t1 && t1<y2){
      flag = true;
    }    
  }else if(B==0){
    double t1 = -C/A;
    if(x1<t1 && t1<x2){
      flag = true;
    }
  }else{
    double t1 = y(x1);
    double t2 = y(x2);
    double t3 = x(y1);
    double t4 = x(y2);
    if( y1 <t1 && t1<y2){
      flag = true;
    }
    if( y1 <t2 && t2<y2){
      flag = true;
    }
    if(x1 <t3 && t3<x2){
      flag = true;
    }
    if(x1<t4 && t4<x2){
      flag = true;
    }
  }
  if(flag){
    cout <<"Poor"<<endl;
  }else{
    cout <<"Lucky"<<endl;
  }
  return 0;
}
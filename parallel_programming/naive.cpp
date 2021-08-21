#include <omp.h>
#include <ctime>
#include <iostream>
using namespace std;
int main(){
  int a[10000];
  int b[10000];
  int c[10000];
  clock_t start, finish;

  start = clock();
  for(int i=0; i<10000; i++){
    for(int i=0; i<10000; i++){
      c[i] = a[i]+b[i];
    }
  }
  finish = clock();
  cout << "Naive C++: "<<(double)(finish-start)<<endl;

  return 0;
}
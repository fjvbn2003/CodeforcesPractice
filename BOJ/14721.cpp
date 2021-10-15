#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin>>N;
  vector<pair<long long, long long> > arr(N, pair<long long, long long>());
  
  for(int i=0; i<N; i++){
    cin>> arr[i].first>>arr[i].second;
  }  

  long long min_rse = 1e18;
  long long a, b;
  for(long long i=1; i<=100; i++){
    for(long long j=1; j<=100; j++){
      long long tmp = 0;
      for(int k=0; k<arr.size(); k++){
        tmp += pow(arr[k].second - (arr[k].first*i+j),2);
      }
      if(tmp < min_rse){
        min_rse = tmp;
        a = i;
        b = j;
      }
    }
  }
  cout <<a<<" "<<b<<endl;
  return 0; 
}
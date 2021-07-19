#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int test_case;
  cin>>test_case;
  int n;
  while(test_case--){
    cin>>n; 
    vector<int> a(n+1);
    vector<int> b(n+1);
    int s_a = 0;
    int s_b = 0;
    for(int i=1; i<n+1; i++){
      cin>>a[i];
      s_a+= a[i];
    }
    vector<int> diff(n+1);
    int minus_cnt = 0;
    for(int i=1; i<n+1; i++){
      cin>>b[i];
      s_b+=b[i];
      diff[i] = a[i]-b[i];
      if(diff[i]<0) minus_cnt-= diff[i];
    }
    if(s_a != s_b){
      cout <<-1<<endl;
      continue;
    }
    cout <<minus_cnt<<endl;
    for(int t=0; t<minus_cnt; t++){
      int a,b;
      for(int i=1; i<n+1; i++){
        if(diff[i]<0){
          diff[i]++;
          b = i;
          break;
        }
      }
      for(int i=1; i<n+1; i++){
        if(diff[i]>0){
          diff[i]--;
          a = i;
          break;
        }
      }
      cout <<a<<" "<<b<<endl;
    }
      

    
    
  }

}
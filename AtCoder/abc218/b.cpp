#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  char t;
  
  for(int i=0; i<26; i++){
    int k;
    cin>>k;
    k--;
    t = k+'a';
    cout <<t;
  }
  cout <<endl;
}
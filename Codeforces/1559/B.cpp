#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fio                    \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);
using namespace std;
int main(){
  fio;
  int test_case;
  cin>> test_case;
  while(test_case--){
    int n;
    cin>> n;
    string s;
    cin>>s;
    for(int i=0; i<n; i++){
      if(s[i] == '?'){
        int left = i;
        int right = i;
        bool blue = true;
        for(int j=left+1; j<n; j++){
          if(s[j] !='?'){
            right = j;
            if(s[j]=='R')
              blue = false;
            break;
          }
        }
        if(right != left){
          for(int j=right-1; j>=left; j--){
            if(blue){
              s[j] = 'R';
              blue = !blue;
            }else{
              s[j] = 'B';
              blue = !blue;
            }
          }
        }else{
          if(left>0){
            blue = (s[left-1]=='B')? true : false;
          }
          for(int j=left; j<n; j++){
            if(blue){
              s[j] = 'R';
              blue = !blue;
            }else{
              s[j] = 'B';
              blue = !blue;
            }
          }
        }
      }
    }
    cout <<s<<'\n';

  }
  return 0;

}
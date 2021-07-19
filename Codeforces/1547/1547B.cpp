#include <iostream>
#include <string>
using namespace std;
// two pointer method
int main(){
  int test_case;
  string s;
  cin>> test_case;
  while(test_case--){
    cin>>s;
    int left = 0;
    int right = s.size()-1;
    char c = 'a'+right;
    bool flag = false;
    while(left<=right){
      if(s[left] != c && s[right] != c){
        flag = true;
        break;
      }
      if(s[left] == c)
        left++;
      else if(s[right] == c){
        right--;
      }else{
        flag = true;
        break;
      }

      c--;
    }
    if(flag){
      cout <<"NO"<<endl;
    }else{
      cout <<"YES"<<endl;
    }
  }
}
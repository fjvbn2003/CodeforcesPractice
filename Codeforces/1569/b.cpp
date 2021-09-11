#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
  int test;
  cin>>test;
  while(test--){
    string s;
    int n;
    cin>>n;
    cin>>s;
    vector<vector<char> > arr(n, vector<char>(n, ' '));
    for(int i=0; i<n; i++)
      arr[i][i] = 'X';
    bool success = true;
    for(int i=0; i<n; i++){
      if(s[i]=='2'){
        for(int j=0; j<n; j++){
          if(arr[i][j] == '+') break;
          if(arr[i][j]== ' ' && s[j] =='2'){
            arr[i][j] = '+';
            arr[j][i] = '-';
            break;
          }
        }
        for(int j=0; j<n; j++){
          if(arr[i][j] == ' '){
            arr[i][j] = '-';
            arr[j][i] = '+';
          }
        }
      }
    }
    for(int i=0; i<n; i++){
      if(s[i]=='2'){
        bool flag = false;
        for(int j=0; j<n; j++){
          if(i==j) continue;
          if(arr[i][j] =='+'){
            flag = true; 
            break;
          }
        }
        if(!flag){
          success = false;
          break;
        }
      }else if(s[i] == '1'){
        bool flag = true;
        for(int j=0; j<n; j++){
          if(i==j) continue;
          if(arr[i][j] =='-'){
            flag = false; 
            break;
          }else if(arr[i][j]==' '){
            arr[i][j] = '=';
            arr[j][i] = '=';
          }
        }
        if(!flag){
          success = false;
          break;
        }
      }
    }


    if(!success){
      cout <<"NO"<<endl;
    }else{
      cout <<"YES"<<endl;
      for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
          cout <<arr[i][j];
        }
        cout <<endl;
      }
    }
    
  }

}
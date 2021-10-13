#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin>>n;
  int t = 1;
  int row = 0;
  for(int i=1; i<n; i++){
    row++;
    if(row == t){
      t++;
      row = 0;
    }
  }  
  //cout << t<<" "<<row<<endl;
  cout << t-row <<" "<<row+1<<endl;
  return 0;
}
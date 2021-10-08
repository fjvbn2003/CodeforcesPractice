#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  double a,b;
  vector<pair<double, int> > arr; 
  for(int i=0; i<3; i++){
    cin>>a>>b;
    b*=10;
    a*=10;
    if(a>=5000) a-=500;
    arr.push_back({b/a, i});
  }
  sort(arr.begin(), arr.end());
  auto ans = arr[2];
  if(ans.second == 2){
    cout <<"U"<<endl;
  }else if(ans.second == 1){
    cout <<"N"<<endl;
  }else if(ans.second == 0){
    cout <<"S"<<endl;
  }
  return 0;

}
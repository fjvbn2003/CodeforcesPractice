#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, int> > arr;
int square(int a){
  return a*a;
}
int dist(pair<int, int> &a, pair<int, int> b){
  return square(a.first-b.first)+square(a.second-b.second);
}
// return closest pair between start end
int div_con(int start, int end){
  if(end-start == 1) return dist(arr[start],arr[end]);
  int m = (start+end)/2;
  int d = min(div_con(start,m), div_con(m,end));
  vector<pair<int, int> > t;
  for(int i=start; i<=end; i++){
    if(square(arr[i].first - arr[m].first)<d){
        t.push_back({arr[i].second, arr[i].first});
    }
  }
  sort(t.begin(), t.end());
  for(int i=0; i<t.size(); i++){
    for(int j=i+1; j<t.size(); j++){
      if(square(t[j].first - t[i].first)>=d)
        break;
      d = min(dist(t[i],t[j]), d);
    }
  }
  //cout <<"start, end, d"<<start<<" "<<end<<" "<<d<<endl;
  return d;
}
int main(){
  int n,a,b;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>a>>b;
    arr.push_back({a,b});
  }
  sort(arr.begin(), arr.end());
  cout << div_con(0, n-1)<<endl;

}
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<double,int> &a, pair<double, int> &b){
  if(a.first == b.first){
    return a.second< b.second;
  }
  return a.first>b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<int> stag(N+2, 0);
    vector<int> clear(N+2, 0);
    for(int i=0; i< stages.size(); i++){
        stag[stages[i]]++;
        for(int j=1; j<=stages[i]; j++){
            clear[j]++;
        }
    }

    vector<pair<double, int> > tt;
    for(int i=1; i<=N; i++){
        if(clear[i] ==0){
            tt.push_back({0,i});
            continue;
        }
      tt.push_back({(double)stag[i]/clear[i],i});
    }
    sort(tt.begin(), tt.end(), comp);
    for(int i=0; i<tt.size(); i++){
        answer.push_back(tt[i].second);
    }
    return answer;
}
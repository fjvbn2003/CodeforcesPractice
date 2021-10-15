#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  //플로이드워셜 알고리즘.
  int test_case;
  cin>> test_case;
  while(test_case--){
    int N,M,K,a,b,c;
    cin>>N>>M;
    vector<vector<int> > graph(N, vector<int>(N,123456789));
    for(int i=0; i<N; i++) graph[i][i] = 0;
    for(int i=0; i<M; i++){
      cin>>a>>b>>c;
      graph[a-1][b-1] = c;
      graph[b-1][a-1] = c;
    }
    cin>>K;
    vector<int> friends(K);
    for(int i=0; i<K; i++){
      cin>> friends[i];
    }
    // 플로이드 워셜
    for(int k=0; k<N; k++){
      for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
          graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
        }
      }
    }
    int min_idx =-1;
    int min_dist = 1234567890;
    for(int i=0; i<N; i++){
      // i번 방으로 모일 때의 거리
      int tmp = 0;
      for(int j=0; j<friends.size(); j++){
        tmp +=  graph[friends[j]-1][i];
      }
      //cout <<"i: "<<i<<" tmp: "<<tmp<<endl;
      if(tmp<min_dist){
        min_idx = i;
        min_dist = tmp;
      }
    }

    cout << min_idx+1<<endl;

  }  
  return 0;
}
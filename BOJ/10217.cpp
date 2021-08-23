#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Data{
  int to, cost, time;
};
struct QueueItem{
  int v, cost, time;
};
struct comp{
  bool operator()(const QueueItem &a, const QueueItem &b) const{
    return a.time>b.time;
  }
};
int t;
const int INF = 987654321;
int dist[101][10001] = {0};

int main(){
  scanf("%d", &t);
  while(t--){
    int ans  =INF;
    int n,m,k;
    scanf("%d%d%d", &n, &m, &k);
    vector<vector<Data>> adj;
    for(int i=1; i<=n; i++)
      for(int j=0; j<=m; j++)
        dist[i][j] = INF;
    
    adj.resize(n+1);

    for(int i=0; i<k; i++){
      int from;
      Data item;
      scanf("%d%d%d%d", &from, &item.to, &item.cost, &item.time);
      adj[from].push_back(item);
    }
    // dp[정점비용][사용한비용]
    priority_queue<QueueItem, vector<QueueItem>, comp> pq;// 시간 오름차순
    dist[1][0] = 0;
    QueueItem start;
    start.v = 1;
    start.cost = 0;
    start.time = 0;
    // 인천공항에서의 시간과 비용은 모두 0이다.
    pq.push(start);
    // 큐가 빌때까지 반복.
    // 내가 궁금한 것은 priority_queue에서 추천한 값이 가장 짧은 거리라는 것은 인정하지만 그 값이 최대 M원의 비용을 만족하는 최단거리일까>?
    while(!pq.empty()){
      QueueItem cur = pq.top(); pq.pop();
      // 그 도시와 인접한 도시를 모두 순회한다.
      for(Data item : adj[cur.v]){
        QueueItem next;
        next.v = item.to;
        // 다음 도시까지 걸리는 시간은 기존 시간 더하기 다음 시간.
        next.time = dist[cur.v][cur.cost]+item.time;
        // 다음 도시까지 소요되는 금액은 현재 금액 더하기 도시간의 이동 비용
        next.cost = cur.cost+item.cost;
        // 만약 비용이 m원 이상이라면 탐색 하지 않기.
        if(next.cost >m) continue;
        // 만약 기존의 저장되어있는 시간보다 작다면, 큐에 추가. (다익스트라 최단 시간)
        if(dist[next.v][next.cost]>next.time){
          dist[next.v][next.cost] = next.time;
          pq.push(next);
        }
      }
    }
    for(int i=0; i<=m; i++)
      ans = min(ans, dist[n][i]);
    if(ans!=INF){
      printf("%d\n", ans);
    }else{
      printf("Poor KCM\n");
    }

  }
  return 0;
}
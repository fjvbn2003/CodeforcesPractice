#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
int arr[1001][1001];
int visited[1001][1001][2];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
// BFS
int BFS()
{
  //{{y좌표, x좌표},거리}
  queue<pair<pair<int, int>, int>> q;
  q.push({{0,
           0},
          1});
  visited[0][0][1] = 1;

  while (!q.empty())
  {
    pair<pair<int, int>, int> p = q.front();
    q.pop();
    if (p.first.first == n - 1 && p.first.second == m - 1)
    {
      return visited[n - 1][m - 1][p.second];
    }
    for (int i = 0; i < 4; i++)
    {
      int ny = p.first.first + dy[i];
      int nx = p.first.second + dx[i];
      int power = p.second;

      if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx][power])
      {
        continue;
      }
      else
      {
        if (power && arr[ny][nx] == 1)
        {
          q.push({{ny,
                   nx},
                  power - 1});
          visited[ny][nx][power - 1] = visited[p.first.first][p.first.second][power] + 1;
        }
        if (arr[ny][nx] == 0)
        {
          q.push({{ny,
                   nx},
                  power});
          visited[ny][nx][power] = visited[p.first.first][p.first.second][power] + 1;
        }
      }
    }
  }
  return -1;
}

int main()
{
  string s;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    cin >> s;
    for (int j = 0; j < m; j++)
    {
      arr[i][j] = s[j] - '0';
    }
  }

  cout << BFS() << endl;
}
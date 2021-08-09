#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100000000;
int n;
vector<pair<int, int>> v;
vector<pair<int, int>> tv;
bool visited[10];
long long ans;
int dx[8] = {0, 1, 2, 3, 3, 2, 1, 0};
int dy[8] = {0, -1, -1, 0, 1, 2, 2, 1};

void check()
{
  long long s, e, mid;
  int x, y;
  int i;
  long long nx, ny;
  long long sum;
  vector<int> ttv;

  for (i = 0; i < 8; i++)
  {
    ttv.push_back(tv[i].first - n * dx[i]);
  }

  sort(ttv.begin(), ttv.end());

  x = ttv[3];

  ttv.clear();

  for (i = 0; i < 8; i++)
  {
    ttv.push_back(tv[i].second - n * dy[i]);
  }

  sort(ttv.begin(), ttv.end());

  y = ttv[3];

  sum = 0;
  for (i = 0; i < 8; i++)
  {
    nx = x + n * dx[i];
    ny = y + n * dy[i];

    sum += abs(nx - tv[i].first) + abs(ny - tv[i].second);
  }

  ans = min(ans, sum);
}

void recur(int cur)
{
  int i;

  if (cur == 8)
  {
    check();

    return;
  }

  for (i = 0; i < 8; i++)
  {
    if (visited[i])
      continue;

    tv.push_back(v[i]);
    visited[i] = true;
    recur(cur + 1);
    tv.pop_back();
    visited[i] = false;
  }
}

int main()
{
  int t, T;
  int i;
  int a, b;

  cin.tie(NULL);
  ios::sync_with_stdio(false);

  cin >> T;
  for (t = 1; t <= T; t++)
  {
    v.clear();

    cin >> n;
    for (i = 0; i < 8; i++)
    {
      cin >> a >> b;

      v.push_back(make_pair(a, b));
    }

    ans = 1LL << 60;
    recur(0);

    cout << "Case #" << t << '\n';
    cout << ans << '\n';
  }
}
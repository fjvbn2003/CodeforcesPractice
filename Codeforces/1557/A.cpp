#include <bits/stdc++.h>
#define fio                    \
  ios::sync_with_stdio(false); \
  cin.tie(0);                  \
  cout.tie(0);

using namespace std;

int main()
{
  fio;
  cout << fixed;
  cout.precision(9);
  int test_case;
  cin >> test_case;
  while (test_case--)
  {
    int n;
    cin >> n;
    vector<long long> arr(n, 0);
    long long t = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    vector<long long> s(n, 0);
    sort(arr.begin(), arr.end());
    s[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
      s[i] = arr[i] + s[i - 1];
    }
    // for (int i = 0; i < n; i++)
    // {
    //   cout << s[i] << " ";
    // }
    // cout << endl;
    double ans = double(s[n - 2]) / (n - 1) + arr[n - 1];
    cout << ans << "\n";
  }
}
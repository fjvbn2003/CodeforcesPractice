#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int n;
  cin >> n;

  double x;
  double s_x = 0;   // sum of square of x
  double sum_x = 0; // square of x

  for (int i = 0; i < n; i++)
  {
    cin >> x;          // x
    s_x = s_x + x * x; // x^2
    sum_x += x;        // x
  }
  double bun_ja = s_x - (sum_x * sum_x) / (double)n;
  bun_ja = bun_ja / (n - 1);
  double ans = sqrt(bun_ja);

  cout << "답: " << ans << endl;
  return 0;
}
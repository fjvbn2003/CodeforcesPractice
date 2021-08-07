#include <iostream>
using namespace std;

int comb[1001][1001];

void calc_combination()
{
  comb[0][0] = 1;
  for (int i = 1; i <= 1000; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j == 0)
      {
        comb[i][j] = 1;
      }
      else
      {
        comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 1000007;
      }
    }
  }
}

int main()
{
  calc_combination();

  int q;
  cin >> q;

  while (q--)
  {
    int n, r;
    cin >> n >> r;
    cout << comb[n][r] << "\n";
  }
  return 0;
}
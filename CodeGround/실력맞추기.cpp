#include <bits/stdc++.h>

using namespace std;

int main()
{
  int test_case;
  cin >> test_case;
  while (test_case--)
  {
    int n;
    cin >> n;
    vector<int> A(n, 0);
    vector<int> B(n, 0);
    for (int i = 0; i < n; i++)
      cin >> A[i];
    for (int i = 0; i < n; i++)
      cin >> B[i];
  }
}
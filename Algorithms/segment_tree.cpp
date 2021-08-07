#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class SegmentTree
{
public:
  typedef int dtype;
  vector<dtype> tree;
  int s;
  SegmentTree(int n)
  {
    for (s = 1; s < n; s *= 2){}
    tree.resize(s * 2);
    for (int i = 1; i < s * 2; i++)
      tree[i] = INT_MAX;
  }

  void insert(vector<dtype> &d)
  {
    for (int i = s; i < s + d.size(); i++)
      tree[i] = d[i - s];
    for (int i = s - 1; i >= 1; i--)
      tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
  }

  dtype getMin(int Left, int Right)
  {
    int l = Left + s - 1, r = Right + s - 1;
    dtype rval = INT_MAX;
    while (l <= r){
      if (l % 2 == 0)
        l /= 2;
      else{
        rval = min(rval, tree[l]);
        l = (l / 2) + 1;
      }
      if (r % 2 == 1)
        r /= 2;
      else{
        rval = min(rval, tree[r]);
        r = (r / 2) - 1;
      }
    }
    return rval;
  }
};

int main()
{
  int n, m;
  cin >> n;
  SegmentTree t(n);
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  t.insert(v);
  cin >> m;
  while (m--){
    int a, b;
    cin >> a >> b;
    cout << t.getMin(a, b) << endl;
  }
}

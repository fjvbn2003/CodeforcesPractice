/*
ID: fjvbn201
TASK: transform
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int N;

bool noChange(vector<char> before, vector<char> after)
{
  for (int i = 0; i < N * N; i++)
  {
    if (before[i] != after[i])
      return false;
  }
  return true;
}
void turn(vector<char> &arr)
{
  vector<char> tmp = arr;
  for (int i = 0; i < N * N; i++)
  {
    int row = i / N;
    int col = i % N;
    arr[col * N + N - row - 1] = tmp[i];
  }
  return;
}

void reflect(vector<char> &arr)
{
  vector<char> tmp = arr;
  for (int i = 0; i < N * N; i++)
  {
    int row = i / N;
    int col = i % N;
    arr[row * N + N - col - 1] = tmp[i];
  }
  return;
}
bool rotation(vector<char> before, vector<char> after, int degree)
{
  int times = degree / 90;
  for (int i = 0; i < times; i++)
  {
    turn(before);
  }
  return noChange(before, after);
}

bool reflection(vector<char> before, vector<char> after)
{
  reflect(before);
  return noChange(before, after);
}

bool combination(vector<char> before, vector<char> after)
{
  reflect(before);
  for (int i = 0; i < 3; i++)
  {
    turn(before);
    if (noChange(before, after))
      return true;
  }
  return false;
}

int main()
{
  ofstream fout("transform.out");
  ifstream fin("transform.in");
  fin >> N;
  vector<char> before(N * N);
  vector<char> after(N * N);

  for (int i = 0; i < N * N; i++)
  {
    fin >> before[i];
  }
  for (int i = 0; i < N * N; i++)
  {
    fin >> after[i];
  }

  if (rotation(before, after, 90))
  {
    fout << 1 << endl;
  }
  else if (rotation(before, after, 180))
  {
    fout << 2 << endl;
  }
  else if (rotation(before, after, 270))
  {
    fout << 3 << endl;
  }
  else if (reflection(before, after))
  {
    fout << 4 << endl;
  }
  else if (combination(before, after))
  {
    fout << 5 << endl;
  }else if (noChange(before, after))
  {
    fout << 6 << endl;
  }
  else
  {
    fout << 7 << endl;
  }
  return 0;
}
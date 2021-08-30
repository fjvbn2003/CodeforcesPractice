/*
ID: fjvbn201
TASK: milk2
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  ofstream fout ("milk2.out");
  ifstream fin ("milk2.in");
  int n;
  fin>>n;
  vector<pair<int, int> > arr(n, pair<int, int>());
  for(int i=0; i<n; i++){
    fin>> arr[i].first>>arr[i].second;
  }
  sort(arr.begin(), arr.end());
  int milk_start = arr[0].first;
  int milk_end = arr[0].second;
  int longest_milk = milk_end - milk_start;
  int longest_nocow = 0;

  for(int i=1; i<n; i++){
    if(arr[i].first <= milk_end){
      milk_end = max(milk_end, arr[i].second);
      longest_milk = max(longest_milk, milk_end - milk_start);
    }else{
      longest_nocow = max(longest_nocow, arr[i].first - milk_end);
      milk_start = arr[i].first;
      milk_end = arr[i].second;
      longest_milk = max(longest_milk, milk_end - milk_start);
    }
  }
  fout<<longest_milk<<" "<<longest_nocow<<endl;

  return 0;
}
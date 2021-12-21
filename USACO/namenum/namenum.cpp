/*
ID: fjvbn201
TASK: namenum
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <fstream>
using namespace std;

char D[8][3] = {{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
vector<string> candidate;
set<string> st;

void brute(string &s, int idx, string t){
  if(s.size() == idx){
    if(st.find(t) != st.end()){
      candidate.push_back(t);
    }
    return;
  }
  int num = s[idx]-'2';
  for(int i=0; i<3; i++){
    brute(s, idx+1, t+ D[num][i]);
  }
  return;
}

int main(){

    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream dict("dict.txt");
    while(!dict.eof()){
      string s;
      dict>> s;
      st.insert(s);
    }
    string serial;
    fin>> serial;
    brute(serial, 0, "");
    sort(candidate.begin(), candidate.end());
    for(int i=0; i<candidate.size(); i++){
      fout<< candidate[i]<<"\n";
    }
    if(candidate.size() == 0){
      fout<<"NONE"<<endl;
    }
    fout.close();
    return 0;
}
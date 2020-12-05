/*
ID: fjvbn201
TASK: gift1
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    map<string, int> m;
    vector<string> arr;
    int n, money, d;
    string s,f;
    fin>> n;
    for(int i=0; i<n; i++){
        fin>> s;
        m.insert({s,0});
        arr.push_back(s);
    }
    for(int i=0; i<n; i++){
        fin>> s;
        fin>> money>>d;
        if(d>0){
            int r = money%d;
            int each = money/d;
            m[s] -=money;
            m[s] +=r;
            for(int j=0; j<d; j++){
                fin>> f;
                m[f]+=each;
            }
        }


    }

    for(auto i : arr){
        fout << i <<" "<< m[i]<<"\n";
    }

    return 0;
}
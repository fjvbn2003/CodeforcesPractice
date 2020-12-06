/*
ID: fjvbn201
TASK: beads
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n;
    string s;
    fin>> n >>s;
    s  = s+s ;
    int ans = 0;
    for(int i=1; i<2*n-1; i++){
        // left search
        int l_tmp = 0;
        int r_tmp = 0;
        char l = s[i-1];
        char r = s[i];

        if(l=='w'){
            for(int j=i-1; j>=0; j--){
                if(s[j] != 'w'){
                    l=s[j];
                    break;
                }
            }
        }
            // left search
        for(int j=i-1; j>=0; j--){
            if(l == s[j] || s[j]=='w'){
                l_tmp++;
            }else{
                break;
            }
        }
        

        if(r=='w'){
            for(int j=i; j<2*n; j++){
                if(s[j] != 'w'){
                    r=s[j];
                    break;
                }
            }
        }
        for(int j=i; j<2*n; j++){
            if(r == s[j] || s[j]=='w'){
                r_tmp++;
            }else{
                break;
            }
        }
        ans = max(ans, l_tmp+r_tmp);
    }
    ans = min(n,ans);
    fout <<ans<<endl;
}
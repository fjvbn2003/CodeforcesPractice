/*
ID: fjvbn201
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string com, sup;
    fin>> com>>sup;
    int com_p,sup_p;
    com_p = sup_p  =1;
    for(char a : com){
        com_p*=(a-'A'+1);
        com_p%=47;
    }
    for(char a : sup){
        sup_p*=(a-'A'+1);
        sup_p%=47;
    }
    if(com_p == sup_p){
        fout << "GO"<<endl;
    }else{
        fout <<"STAY"<<endl;
    }


    return 0;
}
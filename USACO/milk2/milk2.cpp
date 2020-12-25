/*
ID: fjvbn201
TASK: milk2
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    vector< pair<int,int> > arr;
    int n,a,b;
    fin>> n;
    for(int i=0; i<n; i++){
        fin>> a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(), arr.end());
    int milked_time = 0;
    int rest_time = 0;
    for(int i=0; i<n; i++){
        int end = arr[i].second;
        int tmp = arr[i].second- arr[i].first;
        //cout <<"tmp "<<tmp <<endl;
        for(int j=i+1; j<n; j++){
            if(arr[j].first<= end){
                //cout <<"tmp: "<< tmp<<endl;
                tmp += arr[j].second- end;
                end = arr[j].second;
            }
            else{
                break;
            }
        }
        milked_time = max(tmp, milked_time);
        for(int j=i+1; j<n; j++){
            if(arr[i].second < arr[j].first){
                rest_time = max(arr[j].first-arr[i].second , rest_time);    
                break;
            }else{
                break;
            }
        
        }
    }
    fout <<milked_time<<" "<<rest_time<<endl;
    return 0;
}
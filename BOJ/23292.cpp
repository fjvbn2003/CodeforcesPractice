//
// Created by Yongju KIM on 2021/11/05.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

bool comp(pair<int, string> & a, pair<int, string> & b){
    if( a.first == b.first){
       return  a.second<b.second;
    }
    return a.first>b.first;

}

int main(){
    string birth_day;
    cin>> birth_day;
    int n;
    cin>>n;
    vector<pair<int, string> > arr;
    string t;


    for(int i=0; i<n; i++){
        cin>> t;
        int yyyy = 0;
        int mm =0;
        int dd = 0;
        for(int j=0; j<4; j++){
            yyyy += pow((int)(birth_day[j] - t[j]) , 2);
        }
        for(int j=4; j<6; j++){
            mm +=  pow((int)(birth_day[j] - t[j]) , 2);
        }
        for(int j=6; j<8; j++){
            dd +=  pow((int)(birth_day[j] - t[j]) , 2);
        }
        //cout <<"yyyy "<<yyyy<<" mm"<<mm<<" dd"<<dd<<endl;
        arr.push_back(make_pair(yyyy*mm*dd, t));
    }
    sort(arr.begin(), arr.end(), comp);

//    for(int i=0; i<n; i++){
//        cout << arr[i].second<<endl;
//    }
    cout << arr[0].second<<endl;
    return 0;



}
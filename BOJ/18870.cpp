#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> comp(n);
    vector<pair<int, int> > arr;
    int t;
    for(int i=0; i<n; i++){
        cin>> t;
        arr.push_back({t,i});
    }
    sort(arr.begin(), arr.end());
    int idx = 0;
    for(int i=0; i<arr.size(); i++){
        if(i==0){
            comp[arr[i].second] = idx;
        } 
        else{
            if(arr[i].first == arr[i-1].first){
                comp[arr[i].second] = idx;
                //cout <<"hi"<<endl;
            }else{
                idx++;
                comp[arr[i].second] = idx;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << comp[i]<<" ";
    }
    cout <<endl;
    return 0;
}
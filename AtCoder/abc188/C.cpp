#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<pair<int, int> > arr;
int main(){
    int n,t;
    cin>>n;
    int ex = pow(2,n);
    for(int i=1; i<=ex; i++){
        cin>>t;
        arr.push_back({t,i});
    }
    sort(arr.begin(), arr.begin()+ex/2);
    sort(arr.begin()+ex/2, arr.end());
    if(arr[ex/2 -1].first < arr[ex-1].first){
        cout << arr[ex/2 -1].second<<endl;
    }else{
        cout << arr[ex -1].second<<endl;
    }

    return 0;
    
    
}
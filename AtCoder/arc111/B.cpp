#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr2[400001];
int main(){
    int n,a,b;
    vector<pair<int, pair<int,int> > > arr(400001,{0,{0,0}});
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        arr2[a]++;
        arr2[b]++;
        arr[a].first++;
        arr[b].first++;
    }
    sort(arr.begin(), arr.end());
    
    int cnt = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i].first>0){
            if(arr2[arr[i].second.first] <arr2[arr[i].second.second]){
                arr2[arr[i].second.first] = 0;
                cnt++;
            }else{
                arr2[arr[i].second.second] = 0;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}
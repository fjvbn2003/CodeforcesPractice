#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int test_case;
    int n;
    int t;
    int sum =0;
    vector<pair<int,int> > arr;
    cin>> test_case;
    while(test_case--){
        arr.clear();
        sum = 0;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>> t;
            sum+= t;
            arr.push_back({t, i+1});
        }
        sort(arr.begin(), arr.end());
        if(sum/2 < arr[n-1].first){
            cout << "majority winner "<<arr[n-1].second<<'\n';
        }else if(arr[n-1].first == arr[n-2].first){
            cout <<"no winner"<<'\n';
        }else{
            cout << "minority winner "<<arr[n-1].second<<'\n';
        }
    }
    return 0;

}
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    int test_case;
    cin>> test_case;
    while(test_case--){
        int n;

        cin>>n;
        vector<pair<int, int> > arr(n);
        vector<int> accu(n,0);
        vector<int > arr2;
        
        
        for(int i=0; i<n; i++){
            cin>> t;
            arr[i] = {t,i+1};
        }
        
        sort(arr.begin(), arr.end());
        accu[0] = arr[0].first;
        for(int i=1; i<n; i++){
            accu[i] = accu[i-1]+arr[i].first;
        }
        // for(int i=0; i<n; i++){
        //     cout <<"accu: "<<i<<" "<<accu[i]<<" ";
        // }
        // cout <<endl;

        for(int i=0; i<n-1; i++){
            if(accu[i]>= arr[i+1].first){
                arr2.push_back(arr[i].second);
                //cout <<"push "<<arr[i].second<<endl;
            }   //cout <<accu[i]<<" hi"<<arr[i+1].first<<endl;
        }
        arr2.push_back(arr[n-1].second);
        sort(arr2.begin(), arr2.end());
        cout << arr2.size()<<'\n';
        for(int i=0; i<arr2.size(); i++){
            cout <<arr2[i]<<" ";
        }
        cout <<'\n';
    }
    return 0;
}
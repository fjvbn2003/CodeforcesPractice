#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int T, tmp, n, t, ans;
    vector<int> arr;
    cin>>T;
    for(int test_case=1; test_case<=T; test_case++){
        cin>>n;
        arr.clear();
        for(int i=0; i<n; i++){
            cin>>t;
            arr.push_back(t);
        }
        sort(arr.begin(), arr.end());
        ans = 0;
        int maximum = 0;
        for(int i=0; i<n; i++){
            maximum = max(maximum, arr[i]+n-i);
        }

        for(int i=n-1; i>=0; i--){
            if(maximum <= arr[i]+n){
                ans++;
            }
        }
        cout << "Case #"<<test_case<<endl;
        cout <<ans<<endl;
    }
    return 0;
}
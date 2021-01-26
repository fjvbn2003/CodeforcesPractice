#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int test_case, n,l, t;
    int left, right;
    int mid = 100000000;
    int mid2 = 100000000;
    vector<int> arr;
    cin>>test_case;
    for(int T=0; T<test_case; T++){
        arr.clear();
        cin>>l>>n;
        bool odd = (l%2)==0? false : true;
        double mid = l/2;
        double mid_min = 100000000;
        int mid_idx = 0;
        for(int i=0; i<n; i++){
            cin>>t;
            //cout <<"t "<<t<<endl;
            if(mid_min > fabs(mid-t)){
                mid_min = fabs(mid-t);
                mid_idx = t;
            }
            arr.push_back(t);
        }
        sort(arr.begin(), arr.end());
        left = arr[0];
        right = arr[n-1];
        cout <<min(mid_idx, l-mid_idx )<<" "<<max(right, l-left)<<endl;
    }
    return 0;
}
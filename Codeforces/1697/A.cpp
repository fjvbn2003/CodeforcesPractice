#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main(){

    int test_case;
    cin>>test_case;
    while(test_case--){
        int n, m;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin>> arr[i];
        cout << max(accumulate(arr.begin(), arr.end(), 0)-m, 0)<<endl;

    }

}
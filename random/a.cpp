#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> arr = {1,5,3,2,4,5,1,2,5,6,6,78,8,1};
    sort(arr.begin(), arr.end());
    cout<<upper_bound(arr.begin(), arr.end(), 100) - arr.begin()<<endl;


}
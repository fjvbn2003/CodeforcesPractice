#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool comp(int a, int b){
    a = abs(a);
    b = abs(b);
    return a<b;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int a,b;
    sort(arr.begin(), arr.end(), comp);
    int res = 1000000001;
    for(int i=0; i<n-1; i++){
        // 인접한 원소끼리 더해서 절댓값이 작을 때 그 두수를 저장한다.
        if(res> abs(arr[i]+arr[i+1])){
            res = abs(arr[i]+arr[i+1]);
            //오름차순
            if(arr[i]<arr[i+1]){
                a = arr[i];
                b= arr[i+1];
            }else{
                a = arr[i+1];
                b= arr[i];
            }
        }
    }
    cout << a<<" "<<b<<endl;
    return 0;
}
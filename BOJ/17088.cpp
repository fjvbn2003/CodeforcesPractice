#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int d[3] = {0,1,-1};
int n;
vector<int> arr;

int min_possible(int idx, int diff, int last){
    if(idx==n-1){
        if(last-arr[idx] ==diff){return 0;}
        if(last-arr[idx] ==diff-1){return 1;}
        if(last-arr[idx] ==diff+1){return 1;}
        return 1234567890;
    }
    int ret = 1234567890;
    if(last-arr[idx] ==diff){
        ret = min(ret, min_possible(idx+1, diff, arr[idx]));
    }
    if(last-arr[idx] ==diff-1){
        ret = min(ret,1+ min_possible(idx+1, diff, arr[idx]-1));
    }
    if(last-arr[idx] ==diff+1){
        ret = min(ret,1+ min_possible(idx+1, diff, arr[idx]+1));
    }
    return ret;
}

int main(){
    int t;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>> t;
        arr.push_back(t);
    }
    if(n==1 || n==2){
        cout << 0<<endl;
        return 0;
    }
    
    int ans = 1234567890;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int t = 2;
            if(i==0) t--;
            if(j==0) t--;
            int diff = (arr[0]+d[i])-(arr[1]+d[j]);
            ans = min(ans, t+min_possible(2,diff, arr[1]+d[j]));
        }
    }
    if(ans <1234567890){
        cout <<ans<<endl;
    }else{
        cout <<-1<<endl;
    }
    return 0;


}
//
// Created by Yongju KIM on 2021/11/05.
//

#include <iostream>
#include <vector>

using namespace std;

bool possible(vector<vector<int> > & arr, int k, int n, long long s){
    long long ss = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ss += min(arr[i][j], k);
        }
    }
    if(ss >= s){
        return true;
    }else{
        return false;
    }

}

int main(){
    int n;
    cin>>n;
    vector<vector<int> > arr(n, vector<int>(n, 0));
    long long s = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            s += arr[i][j];
        }
    }
    if(s%2 ==0){
        s/=2;
    }else{
        s = s/2+1;
    }
    int left = 0;
    int right = 10000000;
    while(left <right){
        int mid = (left+right)/2;
        if(possible(arr, mid, n, s)){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    cout << left<<endl;


}
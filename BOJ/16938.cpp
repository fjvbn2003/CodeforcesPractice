#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n,l,r,x, t;
    vector<int> arr;
    cin>> n>>l>>r>>x;
    for(int i=0; i<n; i++){
        cin>> t;
        arr.push_back(t);
    }
    int ans = 0;
    int questions  = (1<<n)-1;
    for(int subset = questions; subset; subset = (subset-1)&questions){
        int temp = subset;
        int sum = 0;
        int max = -1;
        int min = 1234567890;
        int idx = 0;
        while(temp){
            if(temp%2 == 1){
                sum+= arr[idx];
                if(min>arr[idx]){min = arr[idx];}
                if(max<arr[idx]){max = arr[idx];}
            }
            temp/=2;
            idx++;
        }
        if(max-min >=x && l<=sum && sum <=r){
            ans++;
        }
    }
    cout <<ans<<endl;
    return 0;
}
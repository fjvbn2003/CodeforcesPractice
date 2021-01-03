#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m,t;
    vector<int> arr;
    vector<int> bi;
    cin>> n>> m;
    for(int i=0;i<n; i++){
        cin>>t;
        arr.push_back(t);
    }
    for(int i=0; i<n-3; i++){
        bi.push_back(0);
    }
    for(int i=0; i<3; i++){
        bi.push_back(1);
    }
    sort(bi.begin(), bi.end());
    int best = -1;
    do{
        int s = 0;
        for(int i=0; i<n; i++){
            if(bi[i]==1){
                s+=arr[i];
            }
    }
    if(s<=m){
        best = max(best, s);
    }
}
while(next_permutation(bi.begin(), bi.end()));
cout <<best<<endl;

}
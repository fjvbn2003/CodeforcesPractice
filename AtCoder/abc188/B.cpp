#include <iostream>
using namespace std;
int arr[100001];
int main(){
    int n;
    cin>>n;
    long long ans = 0;
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    int t;
    for(int i=0; i<n; i++){
        cin>> t;
        ans += (long long)arr[i]*t;
    }
    if(ans ==0)
        cout <<"Yes"<<endl;
    else{
        cout <<"No"<<endl;
    }

    return 0;
}
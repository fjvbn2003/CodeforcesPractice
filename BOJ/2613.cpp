#include <iostream>
#include <vector>
using namespace std;
int arr[301];
int ans = 300000;
int n,m;
bool is_possible(int s){
    int cnt = 1;
    int tsum = 0;
    for(int i=0; i<n; i++){
        if(tsum+arr[i] >s){
            cnt++;
            tsum= arr[i];
            continue;
        }
        tsum+=arr[i];
    }
    if(cnt<=m){
        return true;
    }else{
        return false;
    }
}
void print_possible(int s){
    int cnt = 1;
    int tsum = 0;
    int idx = 0;
    bool flag = false;
    for(int i=0; i<n; i++){
        idx++;
        if(tsum+arr[i] >s){
            cnt++;
            cout<<idx-1<<" ";
            m--;
            idx= 1;
            tsum= arr[i];
            if(n-i == m){flag =  true; break;}
            continue;
        }

        tsum+=arr[i];
    }
    if(!flag && idx != 1){
        cout <<idx;
    }
    if(flag){
        while(m--){
            cout <<1<<" ";
        }
    }
    return ;
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int left = 0;
    int right = 300000;
    int mid;
    while(left<right){
        mid = (left+right)/2;
        if(is_possible(mid)){
            right = mid;
        }else{
            left = mid+1;
        }
    }

    cout << left<<endl;
    print_possible(left);
    return 0;
}
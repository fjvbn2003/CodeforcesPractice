#include <iostream>
using namespace std;
int arr[4] = {1,5,10, 50};
bool memo[1001];
int n;
// idx, 현재 인덱스, rome 이전 로마문자, 
int brute(int idx, int rome, int sum){
    if(idx ==n){
        if(memo[sum]){
            return 0;
        }else{
            memo[sum] = 1;
            return 1;
        }
    }
    int ret = 0;
    for(int i=rome; i<4; i++){
        ret += brute(idx+1, i, sum+arr[i]);
    }
    return ret;
}

int main(){
    cin>>n;
    cout << brute(0, 0, 0)<<endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

bool is_palin(int n){
    vector<int> arr;
    while(n){
        arr.push_back(n%10);
        n/=10;
    }
    for(int i=0; i<arr.size()/2; i++){
        if(arr[i] != arr[arr.size()-1-i])
            return false;
    }
    return true;
}

int main(){
    int n;
    while(1){
        cin>>n;
        if(n ==0) break;
        if(is_palin(n)){
            cout <<"yes"<<endl;
        }else{
            cout << "no"<<endl;
        }

    }
    return 0;
}
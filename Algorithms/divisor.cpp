#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n = 60;
    vector<int> arr;
    for(int i=1; i*i<n; i++){
        if(n%i ==0){
            arr.push_back(i);
            arr.push_back(n/i);
        }
    }
    sort(arr.begin(), arr.end());
    cout << n<<" 의 약수들은 아래와 같습니다."<<endl;
    for(auto i: arr){
        cout<< i<< " ";
    }
    cout <<endl;
}
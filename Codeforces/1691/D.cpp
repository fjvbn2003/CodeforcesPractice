#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    ifstream cin("input.txt");
    int test_case;
    cin >> test_case;
    cin.tie(0);
    while(test_case--){
        int n; 
        bool ans = true;
        cin>> n;
        vector<long long> arr(n);
        vector<long long> s(n);
        for(int i=0; i<n; i++){
            cin>> arr[i];
        }
        long long max_num = arr[0];
        s[0] =  arr[0];
        for(int i=1; i<n; i++){
          if(s[i-1]<0){
              max_num = arr[i];
          }else{
            s[i] = s[i-1]+arr[i];
            max_num = max(max_num, arr[i]);
          }
        cout<<"max_num: "<<max_num<<endl;
          if(max_num <s[i]){
              ans = false;
              break;
          }
        }
        for(int i=0; i<n; i++){
            cout << arr[i]<<" ";
        }
        cout <<endl;
        if(ans){
            cout << "YES"<<endl;
        }else{
            cout << "NO"<<endl;
        }

    }
    return 0;
}
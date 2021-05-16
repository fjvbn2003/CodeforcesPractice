#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int test_case;
    cin>> test_case;
    int n;
    string s;
    vector<pair<int, int> > arr;
    while(test_case--){
        arr.clear();
        cin>> n;
        
        for(int i=0; i<n; i++){
            cin>> s;
            for(int j=0; j<s.size(); j++){
                if(s[j]=='*'){
                    arr.push_back({i,j});
                }
            }
        }
        sort(arr.begin(), arr.end());
        if(arr[0].first == arr[1].first){
            if(arr[0].first == n-1){
                arr.push_back({arr[0].first -1, arr[0].second});
                arr.push_back({arr[0].first -1, arr[1].second});
            }else{
                arr.push_back({arr[0].first +1, arr[0].second});
                arr.push_back({arr[0].first +1, arr[1].second});

            }
        }else if(arr[0].second ==  arr[1].second){
            if(arr[0].second == n-1){
                arr.push_back({arr[0].first, arr[0].second-1});
                arr.push_back({arr[1].first, arr[0].second -1});
            }else{
                arr.push_back({arr[0].first, arr[0].second+1});
                arr.push_back({arr[1].first , arr[0].second+1});

            }
        }else{
            arr.push_back({arr[0].first, arr[1].second});
            arr.push_back({arr[1].first, arr[0].second});
        }
        bool flag = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                flag = false;
                for(int k=0; k<4; k++){
                    if(i== arr[k].first && j==arr[k].second){
                        cout <<'*';
                        flag = true;
                    }
                }
                if(flag){
                    continue;
                }else{
                    cout<<'.';
                }
            }
            cout <<'\n';
        }
    }
    return 0;

}
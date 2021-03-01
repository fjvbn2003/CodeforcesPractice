#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(int a, int b)
{
    return a>b;
}
int main(){
    int test_case;
    cin>> test_case;
    int tmp = 1;

    while(tmp <=test_case){
        int n,k;
        cin>> n>>k;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>> arr[i];
        }    
        sort(arr.begin(), arr.end(), comp);
        int s = 0;
        // for(int i=0; i<n; i++){
        //     cout<< arr[i] <<" ";
        // }    
        for(int i=0; i<k; i++){
            s += arr[i];
        }
        cout <<"Case #"<<tmp<<'\n';
        cout <<s<<'\n';
        tmp++;
    }
    return 0;


}
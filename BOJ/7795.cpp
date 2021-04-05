#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int test_case;
    cin>>test_case;
    int n,m,t;

    vector<int> arra,arrb;

    while(test_case--){
        cin>> n>> m;
        arra.clear();
        arrb.clear();

        for(int i=0; i<n; i++){
            cin>>t;
            arra.push_back(t);
        }
        for(int i=0; i<m; i++){
            cin>>t;
            arrb.push_back(t);
        }
        sort(arra.begin(), arra.end());
        sort(arrb.begin(), arrb.end());
        int answer = 0;
        for(int i=0; i<arra.size(); i++){
            t = arra[i];
            int idx = lower_bound(arrb.begin(), arrb.end(), t)- arrb.begin();
            answer+= idx;
            //cout <<arra[i]<<" hi "<<idx<<endl;
        }
        cout <<answer<<endl;

    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        int n; 
        cin>>n;
        if(n==0) return 0;
        else if(n<4){
            cout <<"no solution"<<endl;
        }
        else{
            // 집합 S
            vector<int> S(n);
            // permutation 생성을 위한 bool 배열생성
            vector<bool> V(n-3, false);
            V.insert(V.end(), 3, true);
            for(int i=0; i<n; i++){
                cin>> S[i];
            }
            // sort(V.begin(), V.end());
            sort(S.begin(), S.end());
            int ans = -1234567890;
            do{
                int tmp = 0;
                for(int i=0; i<n; i++){
                    if(V[i]) tmp+= S[i];
                }
                // cout << "tmp: "<<tmp<<endl;
                // for(int i=0; i<S.size(); i++){
                //     cout <<S[i]<<" ";
                // }
                // cout <<endl;
                if(binary_search(S.begin(), S.end(), tmp)){
                    // cout <<"find!!"<<endl;
                    ans = max(ans, tmp);
                }
            }while(next_permutation(V.begin(), V.end()));
            if(ans != -1234567890){
                cout << ans<<endl;
            }else{
                cout <<"no solution"<<endl;
            }
        }

    }


}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a, int b){
    if(b>a){
        swap(a,b);
    }
    while(b !=0){
        int t = b;
        b = a%b;    
        a = t;
    }
    return a;
}

int main(){
        int t;
        cin>>t;
        int n;
        int tmp;
        while(t--){
            cin>>n;
            long long ans = 0;
            vector<int> even;
            vector<int> odd;
            for(int i=0; i<n; i++){
                cin>>tmp;
                if(tmp%2 ==0) even.push_back(tmp);
                else odd.push_back(tmp);
            }
            if(even.size() >=2){
                ans += even.size()*(even.size()-1)/2;
            }
            ans += even.size()*odd.size();
            for(int i=0; i<odd.size(); i++){
                for(int j=i+1; j<odd.size(); j++){
                    if(gcd(odd[i], odd[j]) >1){
                        ans+=1;
                    }
                }
            }
            cout << ans<<'\n';
        }

}
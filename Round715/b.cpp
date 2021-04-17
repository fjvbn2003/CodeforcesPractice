#include <iostream>
#include <string>
using namespace std;

int main(){
    int test_case;
    string s;
    cin>> test_case;
    int ct,cm;
    int n;
    bool ans = true;
    while(test_case--){
        cin>>n;
        cin>> s;
        ct = 0;
        cm = 0;
        ans  = true;
        for(int i=0; i<n; i++){
            if(s[i] == 'T'){
                ct++;
            }else{
                if(ct <=0){
                    ans = false;
                    break;
                }else{
                    ct--;
                    cm++;
                }
            }
        }
        if(cm != n/3){
            ans = false;
        }
        if(ct != n/3){
            ans =  false;
        }

        if(ans){
            cout <<"YES"<<'\n';
        }else{
            cout <<"NO"<<'\n';
        }
        
    }
    return 0;

}
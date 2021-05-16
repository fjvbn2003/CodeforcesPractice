#include <iostream>
#include <string>
using namespace std;
int main(){
    int test_case;
    string s;
    cin>> test_case;
    int u,d,r,l;
    int px,py;
    while(test_case--){

        cin>> px>>py;
        cin>> s;
        u =d = r = l = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='U'){
                u++;
            }else if(s[i]=='D'){
                d++;
            }else if(s[i]=='R'){
                r++;
            }else{
                l++;
            }
        }
        bool flag = true;
        if(px<0){
            if(l< -px) flag = false;
        }else{
            if(r < px) flag = false;
        }

        if(py <0){
            if(d < -py) flag  = false;
        }else{
            if(u < py) flag = false;
        }
        if(flag){
            cout <<"YES"<<endl;
        }else{
            cout <<"NO"<<endl;
        }

    }
    return 0;

}
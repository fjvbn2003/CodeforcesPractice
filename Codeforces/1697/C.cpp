#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int test_case;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>test_case;
    
    while(test_case--){
        int n;
        cin>>n;
        vector<char> s(n);
        vector<char> t(n);
        for(int i=0; i<n; i++) cin>> s[i];
        for(int i=0; i<n; i++) cin>> t[i];
        
        bool ans = true;
        for(int i=0; i<n; i++){
            if(s[i] == t[i]) continue;
            else{
                if(s[i] == 'b'){
                    if(i !=n-1){
                        if(s[i+1] == 'c'){
                            s[i] = 'c';
                            s[i+1] = 'b';
                        }else{
                            ans = false;
                            break;
                        }
                    }else{
                        ans = false;
                        break;
                    }
                }else if(s[i] == 'a'){
                    if(i !=n-1){
                        if(s[i+1] == 'b'){
                            s[i] = 'b';
                            s[i+1] = 'a';
                        }else{
                            ans = false;
                            break;
                        }
                    }else{
                        ans = false;
                        break;
                    }
                }else{//c
                    ans = false;
                    break;
                }

                if(s[i]!= t[i]){
                    ans = false;
                    break;
                }
            }
        }
        for(int i=0; i<n; i++){
            cout << s[i]<<" ";
        }
        cout <<endl;
        if(ans){
            cout << "YES"<<endl;
        
        }else{
            cout <<"NO"<<endl;
        }
    }

}
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    string s;
    stack<char> st;
    cin>>s;
    bool flag = false;
    for(int i=1; i<s.size(); i++){
        if(s[i]=='A' && s[i-1]=='A'){
            flag = true;
            break;
        }
    }
    if(flag){
        cout <<"NP"<<endl;
        return 0;
    }
    for(int i=0; i<s.size(); i++){
        if(s[i]=='P'){
            st.push('P');
            //cout<<"HI"<<endl;
        }else{
            if(i!= s.size()-1 && s[i+1]=='P' && st.size()>=2){
                st.pop();
                st.pop();
            }else{
                flag = true;
                break;
            }
        }
    }
    if(flag){
        cout << "NP"<<endl;
    }else{
        if(st.size()==1 && st.top()=='P'){
            cout <<"PPAP"<<endl;
        }else{
            cout <<"NP"<<endl;
        }
        
    }
    return 0;
}
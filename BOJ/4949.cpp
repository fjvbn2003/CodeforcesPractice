#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string s;
    while(1){
        getline(cin, s);
        if(s == "."){break;}
        stack <char> st;
        bool flag = false;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push('(');
            }else if( s[i]=='['){
                st.push('[');
            }else if( s[i]==')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    flag = true;
                    break;
                }
            
            }else if(s[i] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }else{
                    flag = true;
                    break;
                }
            }else{
                continue;
            }

        }
        if(!flag && st.empty()){
            cout <<"yes"<<endl;
        }else{
            cout <<"no"<<endl;
        }
    }
    return 0;
}
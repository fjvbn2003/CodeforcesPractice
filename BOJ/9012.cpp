#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int n;
    string s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>> s;
        stack<char> st;
        bool flag = true;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                st.push('(');
            }else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    flag = false;
                    break;
                }
            }
        }
        if(flag && st.size()==0){
            cout << "YES"<<endl;
        } else{
            cout <<"NO"<<endl;
        }
    }
    return 0;
}
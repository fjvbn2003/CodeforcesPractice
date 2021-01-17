#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    string s;
    stack<int> st;
    cin>>s;
    int ans =0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            st.push(i);
        }else{
            if(st.top()+1 == i){
                ans += st.size()-1;
                st.pop();
            }else{
                ans+=1;
                st.pop();
            }
        }
    }
    cout <<ans<<endl;
}
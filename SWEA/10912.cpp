#include <bits/stdc++.h>

using namespace std;

int main(){
    int test_case;
    cin>> test_case;
    string s;
    int sequence = 1;
    while(test_case--){
        cin>> s;
        stack<char> st;
        sort(s.begin(), s.end());
        for(int i=s.size()-1; i>=0; i--){
            if(!st.empty() && s[i] ==  st.top()){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
            cout <<"#"<<sequence<<" Good"<<endl;
        }else{
            cout <<"#"<<sequence<<" ";
            while(!st.empty()){
                cout <<st.top();
                st.pop();
            }
            cout <<endl;
        }
        sequence++;

    }
    return 0;
    



}
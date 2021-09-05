#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
bool is_right(string s){
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            st.push('(');
        }else{
            if(st.size()>0 && st.top()=='('){
                st.pop();
            }else{
                return false;
            }
        }
    }
    if(st.size() ==0) return true;
    else return false;
}
string erase_and_convert(string s){
    int n = s.size();
    for(int i=0; i<n; i++){
        if(s[i]=='(') s[i] = ')';
        else s[i] = '(';
    }
    if(s.size()>=2){
        return s.substr(1,n-2);
    }
    return s;
}
string convert(string s){
  //cout <<"in convert: "<<s<<endl;
    if(s=="") return s;
    int left =0, right = 0;
    string u,v;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(') left++;
        else right++;
        if(left ==right){
            break;
        }
    }
    u = s.substr(0,left+right);
    v = s.substr(left+right);
    if(is_right(u)){
        return u+convert(v);
    }else{
        return "("+convert(v)+")" + erase_and_convert(u);
    }
}

int main(){
  string s = ")(";
  cout <<convert(s)<<endl;
  return 0;
}
#include <iostream>
#include <string>
#include <stack>

using namespace std;
double ascii[100];
int main(){
    int n;
    stack<double> st;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0;i<n; i++){
        cin>> ascii[i];
    }
    //cout <<"hi"<<endl;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='+'){
            double a1 = st.top();
            st.pop();
            double a2 = st.top();
            st.pop();
            st.push(a1+a2);
        }else if(s[i]=='-'){
            double a1 = st.top();
            st.pop();
            double a2 = st.top();
            st.pop();
            st.push(a2-a1);
        }else if(s[i]=='*'){
            double a1 = st.top();
            st.pop();
            double a2 = st.top();
            st.pop();
            st.push(a1*a2);
        }else if(s[i]=='/'){
            //cout <<s[i]<<endl;
            double a1 = st.top();
            st.pop();
            double a2 = st.top();
            st.pop();
            st.push(a2/a1);
        }else{
            //cout <<s[i]<<endl;
            st.push(ascii[s[i]-'A']);
        }
        //cout <<st.top()<<endl;
    }
    cout<<fixed;
    cout.precision(2);
    //cout <<st.size()<<endl;
    cout << st.top()<<endl;

}
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int n;
    stack<int> st;
    string s;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>s;
        if(s == "push"){
            int t;
            cin>>t;
            st.push(t);

        }else if(s== "top"){
            if(st.empty()){
                cout << -1<<"\n";
            }else{
                cout << st.top()<<"\n";
            }
        }else if(s== "pop"){
            if(st.empty()){
                cout << -1<<"\n";
            }else{
                cout << st.top()<<"\n";
                st.pop();
            }
        }else if(s=="empty"){
            cout <<st.empty()<<"\n";

        }else{//size
            cout << st.size()<<"\n";
        }
    }
    cout <<endl;
    return 0;
}
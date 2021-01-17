#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int n;
    string s;
    queue<int> q;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s;
        if(s=="push"){
            int x;
            cin>>x;
            q.push(x);
        }else if(s=="front"){
            if(q.empty()){
                cout <<"-1"<<"\n";
            }else{
                cout <<q.front()<<"\n";
            }
        }else if(s=="pop"){
            if(q.empty()){
                cout <<"-1"<<"\n";
            }else{
                cout <<q.front()<<"\n";
                q.pop();
            }
            
        }else if(s=="size"){
            cout <<q.size()<<"\n";
        }else if(s=="back"){
            if(q.empty()){
                cout <<"-1"<<"\n";
            }else{
                cout <<q.back()<<"\n";
            }
        }else{
            cout <<q.empty()<<"\n";
        }
    }
    return 0;
}
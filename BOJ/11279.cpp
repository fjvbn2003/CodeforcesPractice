#include <iostream>
#include <queue>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, t;
    priority_queue<int> pq;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        if(t==0){
            if(pq.size() == 0){
                cout <<0<<"\n";
            }else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }else{
            pq.push(t);
        }
    }
    return 0;

}
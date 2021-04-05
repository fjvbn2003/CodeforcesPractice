#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>> n;
    int t;
    priority_queue<int> pq;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>> t;
            pq.push(-t);
            if(pq.size()>n){
                pq.pop();
            }
        }
    }
    cout << -pq.top()<<"\n";
    return 0;
}
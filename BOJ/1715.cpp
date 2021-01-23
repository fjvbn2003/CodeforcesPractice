#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n,t;
    //min heap
    priority_queue<long long> pq;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>t;
        pq.push(-t);
    }
    long long ans = 0;
    long long a,b;

    while(pq.size() >1){
        a = -pq.top();
        pq.pop();
        b = -pq.top();
        pq.pop();
        //cout <<a+b<<endl;
        ans += (a+b);
        pq.push(-(a+b));
    }   
    cout <<ans<<endl;
    return 0;

}
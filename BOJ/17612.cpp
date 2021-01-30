#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct person{
    int w;
    int counter;
    int id;
};
struct cmp{
    bool operator()(person a, person b){
    if(a.w ==  b.w){
        return a.counter > b.counter;
    }else{
        return a.w<b.w;
    }

    }
};



int main(){
    int n, k;
    int id, w, counter;
    cin>>n>>k;
    priority_queue< person ,vector<person>,  cmp> pq;
    vector<person> arr;
    long long ans = 0;
    int order = 1;
    person tmp;
    if(n>k){
        for(int i=0; i<k; i++){
            cin>>id>>w;
            tmp.w = w;
            tmp.id = id;
            tmp.counter = i;
            pq.push(tmp);
        }
        for(int i=0; i<n-k; i++){
            cin>> id>>w;
            tmp = pq.top();
            pq.pop();
            arr.push(tmp);
            tmp.id = id;
            tmp.w += w;
            pq.push(tmp);
        }
    }
    else{
        for(int i=0; i<k; i++){
            cin>>id>>w;
            tmp.w = w;
            tmp.id = id;
            tmp.counter = i;
            pq.push(tmp);
        }
    }
    while(!pq.empty()){
        ans+= (order*(pq.top().id));
        pq.pop();
        order++;
    }
    cout <<ans<<endl;
    return 0;
}
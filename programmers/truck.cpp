#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weight = {10};
    queue<pair<int,int> > q;
    int idx = 0;
    int time = 1;
    int remain = weight;
    if(truck_weight[idx] <= remain){
        q.push({truck_weight[idx], time});
        remain -= truck_weight[idx];
        idx++;
    }
    while(!q.empty()){
        time++;

        if(time - q.front().second == bridge_length){
            remain += q.front().first;
            q.pop();
        }
        if(idx != truck_weight.size() && remain >= truck_weight[idx]){
            q.push({truck_weight[idx], time});
            remain -= truck_weight[idx];
            idx++;
        }
        //cout <<"time:"<<time<<" remain:"<<remain<<" "<<q.size()<<endl;
    }
    cout <<time<<endl;
}
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
struct job{
    int call_time;
    int take_time;
    int category;
    int importance;
};
vector<int> solution(vector<vector<int>> jobs) {
    vector<int> answer;
    int cur_time = 0;
    int job_idx = 0;
    int pre_job = -1;
    vector<queue<job> > job_q(101, queue<job>());
    vector<int> sum_importance(101, 0);
    while(job_idx<jobs.size()){
        cout <<"cur_time: "<<cur_time<<endl;
        // queuing jobs to job_q;
        while(job_idx<jobs.size() && jobs[job_idx][0]<=cur_time){
            int a,b,c,d;
            a = jobs[job_idx][0];
            b = jobs[job_idx][1];
            c = jobs[job_idx][2];
            d = jobs[job_idx][3];
            job_q[c].push({a,b,c,d});
            sum_importance[c] += d;
            job_idx++;
        }
        int max_importance = 0;
        int max_idx = 100;
        bool find_pre_job = false;
        // todo pre_job
        if(pre_job != -1){
            if(!job_q[pre_job].empty() && job_q[pre_job].front().call_time<=cur_time){
                find_pre_job =true;
            }else{
                pre_job = -1;
            }
        }
        if(find_pre_job){
            sum_importance[pre_job] = 0;
            while(!job_q[pre_job].empty()){
                job tmp = job_q[pre_job].front();
                job_q[pre_job].pop();
                cout << "pre_job start: "<< pre_job<<endl;
                cur_time+= tmp.take_time;
            }
            continue;
        }
        
        // find max_importance category
        for(int i=100; i>=1; i--){
            if(sum_importance[i]>=max_importance){
                max_importance = sum_importance[i];
                max_idx = i;
            }
        }
        // not_found
        if(max_importance ==0){
            cur_time++;
        }else{
            answer.push_back(max_idx);
            sum_importance[max_idx] = 0;
            while(!job_q[max_idx].empty()){
                job tmp = job_q[max_idx].front();
                job_q[max_idx].pop();
                cout << "start job: "<< max_idx<<endl;
                cur_time+= tmp.take_time;
            }
            pre_job = max_idx;
        }
        
    }
    // for(int i=1; i<=100; i++){
    //     cout << "in queue: "<<i<<endl;
    //     if(!job_q[i].empty()){
    //         cout << job_q[i].front().category<<endl;
    //     }
    // }
    
    return answer;
}
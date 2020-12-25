#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

int N, M, K;
vector<ll> arr;
vector<ll> tree_arr;
vector<pair<int, pair<int, ll>>> cmd;

ll make_segment_tree(int node, int start, int end){
    if(start == end) return tree_arr[node] = arr[start];
    int mid = (start+end)/2;
    ll left_result = make_segment_tree(node*2, start, mid);
    ll right_result = make_segment_tree(node*2 +1 , mid+1, end);
    tree_arr[node] = left_result+right_result;
    return tree_arr[node];
}
ll sum(int node, int start, int end, int left, int right){
    if(left>end || right<start) return 0;
    if(left<=start && end <=right) return tree_arr[node];
    int mid = (start+end)/2;
    ll left_result = sum(node*2, start, mid, left, right);
    ll right_result = sum(node*2+1, mid+1, end, left, right);
    return left_result+right_result;
}
void update_segment_tree(int node, int start, int end, int index, ll diff){
    if(index<start || index>end) return;
    tree_arr[node] = tree_arr[node]+diff;
    if(start != end){
        int mid = (start+end)/2;
        update_segment_tree(node*2, start, mid, index, diff);
        update_segment_tree(node*2+1, mid+1,end, index, diff);
    }
}

int main(){
    cin>>N>>M>>K;
    for(int i=0; i<N; i++){
        int a; cin>>a;
        arr.push_back(a);
    }
    for(int i=0; i<M+K; i++){
        int a,b,c;
        cin>>a>>b>>c;
        cmd.push_back({a,{b,c}});
    }
    tree_arr.resize(4*N);
    make_segment_tree(1,0,N-1);
    for(int i=0;i<cmd.size(); i++){
        if(cmd[i].first == 1){
            int idx = cmd[i].second.first-1;
            int diff =  cmd[i].second.second - arr[idx];
            arr[idx] = cmd[i].second.second;
            update_segment_tree(1,0,N-1,idx, diff);
        }else{
            int left = cmd[i].second.first-1;
            int right = cmd[i].second.second-1;
            cout << sum(1,0,N-1, left,right)<<'\n';
        }
    }
}
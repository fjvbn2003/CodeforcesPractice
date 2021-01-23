#include <iostream>
#include <queue>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    priority_queue<int> left;
    priority_queue<int> right;
    int t ;
    for(int i = 0; i<n; i++){
        cin>>t;
        left.push(t);
        if(left.size() > right.size()+1){
            right.push(-left.top());
            left.pop();
        }
        if(left.size() >0 && right.size()>0 && left.top()> -right.top()){
            int lt = left.top();
            left.pop();
            int rt = -right.top();
            right.pop();
            right.push(-lt);
            left.push(rt);
        }
        cout << left.top()<<"\n";
    }
    return 0;

}
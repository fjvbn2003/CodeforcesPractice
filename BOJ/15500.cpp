#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int main(){
    int n,t;
    int k = 0;
    vector<pair<int,int> > arr;
    map<int, int > m;
    stack<int> st1, st2, st3;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>> t;
        st1.push(t);
        m[t] = 1;
    }
    for(int i=n; i>=1; i--){
        int stack_num = m[i];
        if(stack_num==1){
            while(st1.top() != i){
                arr.push_back({1,2});
                int tmp = st1.top();
                st1.pop();
                st2.push(tmp);
                m[tmp] = 2;
            }
            arr.push_back({1,3});
            st1.pop();
            m[i] = 3;
        }else if(stack_num==2){
            while(st2.top() != i){
                arr.push_back({2,1});
                int tmp = st2.top();
                st2.pop();
                st1.push(tmp);
                m[tmp] = 1;
                
            }
            arr.push_back({2,3});
            st2.pop();
            m[i] = 3;
        }
    }
    cout <<arr.size()<<endl;
    for(int i=0; i<arr.size(); i++){
        cout << arr[i].first <<" "<<arr[i].second<<'\n';
    }
    return 0;

}
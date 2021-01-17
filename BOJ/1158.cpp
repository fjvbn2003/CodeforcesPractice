#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n,k;
    queue<int> q;
    vector<int> arr;
    cin>>n>>k;
    
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    for(int i=0; i<n-1; i++){
        for(int j=1; j<k; j++){
            int t = q.front();
            q.pop();
            q.push(t);
        }
        arr.push_back(q.front());
        q.pop();
    }
    arr.push_back(q.front());
    cout<<"<";
    for(int i=0; i<arr.size()-1; i++){
        cout << arr[i]<<", ";
    }
    cout<<arr[arr.size()-1]<<">"<<endl;

}
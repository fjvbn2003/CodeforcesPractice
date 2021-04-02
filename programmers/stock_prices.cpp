#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    vector<int> prices = {1,2,3,2,3};
    vector<int> arr(prices.size(), 0);

    stack<pair<int, int> > st;
    for(int i=0; i< prices.size(); i++){
        while(!st.empty() && st.top().first>prices[i]){
            pair<int, int> tmp = st.top();
            st.pop();
            arr[tmp.second] = i-tmp.second;
        }
        st.push({prices[i], i});
        if(i ==  prices.size()-1 && !st.empty()){
            while(!st.empty()){
                pair<int, int> tmp = st.top();
                st.pop();
                arr[tmp.second] = i-tmp.second;
            }
        }
    }
    for(int i=0; i<arr.size(); i++){
        cout << arr[i]<<" ";
    }
    return 0;
    


}
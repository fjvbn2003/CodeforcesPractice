#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int histo(int start, int end){
    if(start==end){return arr[start];}
    int ret = -1;
    int mid = (start+end)/2;
    ret = max(histo(mid+1,end), histo(start,mid));
    
    
    int left = mid;
    int right = mid+1;
    int min_height = min(arr[left], arr[right]);
    int cand = 2*min_height;
    //cout <<"start, end: "<< start<<" "<<end<<endl;
    while(start<left || right<end){
        
        if(right<end && ((left==start) || arr[left-1] <arr[right+1]) ){
            right++;
            min_height = min(min_height, arr[right]);
        }else{
            left--;
            min_height = min(min_height, arr[left]);
        }
        
        //cout <<"cand: "<<cand<<endl;
        cand = max(cand, (right-left+1)*min_height);
        
    }
    ret = max(ret, cand);
    return ret;

}
int main(){

    int n,t;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>> t;
        arr.push_back(t);
    }
    cout<<histo(0,n-1)<<endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;
int n;
vector<int> arr;
//퀵 정렬
void quick_sort(int s, int e){
    if(s>=e){return;}
    int pivot = arr[e];
    int left = s;
    int right = e-1;
    while(left<=right){
        while(left<=e && arr[left]<pivot){
            left++;
        }
        while(s<=right && arr[right]>pivot){
            right--;
        }
        if(left>right){
            int t = arr[left];
            arr[left] = pivot;
            arr[e] = t;
        }else{
            int t = arr[right];
            arr[right] = arr[left];
            arr[left] = t;
        }
    }
    quick_sort(s,left-1);
    quick_sort(left+1, e);
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    int t;
    for(int i=0; i<n; i++){
        cin>>t;
        arr.push_back(t);
    }
    quick_sort(0,n-1);

    for(int i=0; i<n; i++){
        cout << arr[i]<<"\n";
    }
    return 0;
}
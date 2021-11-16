//
// Created by Yongju KIM on 2021/11/10.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubble_sort(int* arr, int  n){
    // n-1번 스왑 ~ 1번 스왑.
    for(int i=0; i<n; i++){
        for(int j=1; j<n-i; j++){
            if(arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
        }
    }
    return;
}
// 넣어야 할 위치를 미리 지정하고 매번 스왑
void selection_sort(int* arr, int n){
    // i는 넣어야 할 위치.
    for(int i=0; i<n; i++){
        int min_idx = i;
        int min_val = arr[i];
        for(int j=i+1; j<n; j++){
            if(arr[j]<min_val){
                min_val = arr[j];
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    return ;
}

void insertion_sort(int * arr, int n){
    // 앞에서 부터 정렬을 유지한다.
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(arr[j]<arr[j-1]) swap(arr[j], arr[j-1]);
            else break;
        }
    }
    return ;
}

void quick_sort(int* arr, int left, int right){
    if(left >= right ) return;
    int pivot = arr[left];
    int l = left+1;
    int r = right;
    while(l <r){
        while(arr[l]<= pivot && l<=right) l++;
        while(arr[r]>= pivot && r >=left) r--;
        if(l>=r) break;
        swap(arr[l], arr[r]);
    }
    if(pivot > arr[r])
        swap(arr[left], arr[r]);
    quick_sort(arr, left, r-1);
    quick_sort(arr, r+1, right);
    return;
}

int main(){
    int n = 5;
    int arr[] = {4,2,1,45,7};

    //bubble sort
    //bubble_sort(arr, n);

    //selection sort;
    //selection_sort(arr, n);

    //insertion sort;
    //insertion_sort(arr, n);

    // quick sort
    quick_sort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i]<<" ";
    }
    cout <<endl;
    return 0;
}
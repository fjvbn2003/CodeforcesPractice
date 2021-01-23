#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){

    int n, x, y;
    int ans = 0;
    vector<pair<int, int> > arr;
    ifstream infile("triangles.in");
    ofstream outfile("triangles.out");
    
    infile>>n;
    for(int i=0; i<n ; i++){
        infile>>x>>y;
        arr.push_back({x,y});
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k= j+1; k<n; k++){
                pair<int, int> p1 = arr[i];
                pair<int, int> p2 = arr[j];
                pair<int, int> p3 = arr[k];
                if(p1.first == p2.first && p2.second == p3.second){
                    ans = max(ans, (p2.second - p1.second)*(p3.first-p2.first));
                }
                if(p1.second == p2.second && p2.first == p3.first){
                    ans = max(ans, (p2.first - p1.first)*(p3.second-p2.second));

                }
                

            }
        }
    }
    outfile <<ans<<endl;
    return 0;

}
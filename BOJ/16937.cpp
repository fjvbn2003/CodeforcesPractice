#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int h,w,n;
vector<pair<int,int> > arr;
int main(){
        int r,c;
        cin>> h>>w;
        cin>>n;
        int ans = 0;
        for(int i=0; i<n; i++){
                cin>>r>>c;
                arr.push_back({r,c});
        }
        for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                        auto p1 = arr[i];
                        auto p2 = arr[j];
                        for(int k=0; k<2; k++){
                                for(int l = 0; l<2; l++){
                                        if(p1.first + p2.first <=h && max(p1.second,p2.second)<=w){
                                            int temp = p1.first*p1.second + p2.first*p2.second;
                                            if(ans < temp){
                                                ans = temp;
                                            }
                                        }
                                        if(p1.second + p2.second <=w && max(p1.first, p2.first) <=h){
                                            int temp = p1.first*p1.second + p2.first*p2.second;
                                            if(ans < temp){
                                                ans = temp;
                                            }
                                        }
                                swap(p2.first, p2.second);
                                }
                            swap(p1.first, p1.second);

                        }
                }
        }
        cout <<ans<<endl;
        return 0;
}
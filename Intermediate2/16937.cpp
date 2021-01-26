#include <iostream>
#include <vector>

using namespace std;
int arr[101][101];
int main(){
    vector<pair<int, int> > stickers;
    int h,w, n;
    int r,c;
    pair<int, int> a,b;
    cin>> h>>w>>n;
    for(int i=0; i<n; i++){
        cin>> r>>c;

        stickers.push_back({r,c});
        

    }
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            a = stickers[i];
            b = stickers[j];
            // 그그
            bool flag  = false;
            if(a.second+b.second <=w )
                flag = true;
            if(!flag && a.first+b.first <=h && b.second <=w && a.second <=w)
                flag = true;
            // 반그
            if(!flag && a.first+b.second <=w && b.first <=h && a.second<=h)
                flag = true;
            if(!flag && a.second+b.first <=h && b.second <=w && a.first <=w)
                flag = true;
            // 그반
            if(!flag && a.second+b.first <=w && b.second <=h && a.first<=h)
                flag = true;
            if(!flag && a.first+b.second <=h && b.first <=w && a.second <=w)
                flag = true;
            if(!flag && a.first+b.first <=w && b.second <=h && a.second <=h)
                flag = true;
            if(!flag && a.second+b.second <=h && b.first <=w && a.first<=w)
                flag = true;    

            if(flag){
                //cout <<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<endl;
                ans = max(ans, a.first*a.second + b.first*b.second);
            }
        }
    }
    cout <<ans<<endl;
    return 0;
}
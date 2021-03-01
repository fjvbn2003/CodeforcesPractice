#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int scores[40] = {6,13,4,18,1,20,5,12,9,14,11,8,16,7,19,3,17,2,15,10};
int main(){
    int test_case;
    int test_case_var = 1;

    cin>> test_case;
    while(test_case_var <= test_case){
        double a,b,c,d,e;
        cin>> a>>b>>c>>d>>e;
        int n;
        double x,y;
        cin>> n;
        vector<pair<double, double> > arr(n);
        for(int i=0; i<n; i++){
            cin>> arr[i].first>>arr[i].second;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            double degree = atan2(arr[i].second, arr[i].first)*180/M_PI;
            double leng = sqrt(pow(arr[i].first,2)+pow(arr[i].second,2));
            //cout <<"degree: "<<degree<<endl;
            degree +=9.0;
            if(degree <0){
                degree+= 360.0;
            }
            int idx = 0;
            while(degree >18.0){
                degree-=18.0;
                idx++;
            }
            int cand = scores[idx];
            if(leng <=a){
                cand = 50;
            }else if(leng <=b){
                cand = cand;
            }else if(leng <=c){
                cand  = cand*3;
            }else if(leng <=d){
                cand = cand;
            }else if(leng <=e){
                cand = cand*2;
            }else{
                cand = 0;
            }
            ans+=cand;
        }
        cout <<"Case #"<<test_case_var<<'\n';
        cout << ans<<endl;
        test_case_var++;
    }
}
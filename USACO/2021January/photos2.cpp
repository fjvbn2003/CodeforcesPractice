#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    int n,id;
    cin>>n;
    int even = 0;
    int odd = 0;
    for(int i=0; i<n; i++){
        cin>> id;
        if(id%2 ==0){
            even++;
        }else{
            odd++;
        }
    }
    int ans = 0;
    if(even<= odd){
        ans+= even*2;
        odd-=even;
        bool even = true;
        while(odd>0){
            //cout<<odd<<endl;
            if(even){
                odd-=2;
                ans++;
                even  = false;
            }else{
                odd-=1;
                ans++;
                even = true;
            }
        }
        if(odd<0){
            ans-=2;
        }
        cout<<ans<<endl;
    }else{
        cout<<odd*2 +1<<endl;
    }
    return 0;

}
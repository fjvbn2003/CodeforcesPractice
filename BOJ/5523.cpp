#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,at,bt;
    int a = 0;
    int b =0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>at>>bt;
        if(at>bt){
            a++;
        }
        if(at<bt){
            b++;
        }
    }
    cout<<a<<" "<<b<<endl;
}
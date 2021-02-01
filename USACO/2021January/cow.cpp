#include <iostream>
#include <string>
using namespace std;
int arr[26];
int main(){
    string s;
    string a;
    cin>>s>>a;
    
    int ans = 1;
    for(int i=0; i<s.size(); i++){
        arr[s[i]-'a'] = i;
    }
    int before = -1;
    for(int i=0; i<a.size(); i++){
        if(arr[a[i]-'a'] <= before){
            ans++;
        }
        before = arr[a[i]-'a'];
    }
    cout << ans<<endl;
}
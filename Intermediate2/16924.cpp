#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int y,x;
char arr[101][101];
bool memo[101][101];
int main(){
    cin>> y>>x;
    vector<pair<pair<int, int> , int> > ans;
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            cin>> arr[i][j];
        }
    }
    int max_cross = max(x,y);
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            int l = 0;
            if(arr[i][j]=='*'){
                for(int k=1; k<=max_cross+1; k++){
                    if(i-k >=0 && i+k <y && j-k>=0 && j+k<x){
                        if(arr[i-k][j]=='*' && arr[i+k][j]=='*' && arr[i][j-k]=='*'&& arr[i][j+k]=='*'){
                            memo[i-k][j]= true;
                            memo[i+k][j]= true;
                            memo[i][j-k]= true;
                            memo[i][j+k]= true;
                            l = k;
                        }else{
                            break;
                        }
                    }else{
                        break;
                    }
                }
            }
            if(l !=0){
                memo[i][j] = true;
                ans.push_back({{i,j},l});
            }
            
        }
    }
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            if(arr[i][j]=='*' && memo[i][j]==false){
                cout <<-1<<endl;
                return 0;
            }
        }
    }
    cout <<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        auto t = ans[i];
        cout << t.first.first+1<<" "<<t.first.second+1<<" "<<t.second<<endl;
    }
     return 0;
}
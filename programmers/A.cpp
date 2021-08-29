#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> dice) {
    
    int answer = 0;
    int n = dice.size();

    vector<vector<bool> > arr(n, vector<bool>(10, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<6; j++){
            arr[i][dice[i][j]] = true;
        }
    }
    vector<int> tt;
    for(int i=0; i<n; i++) tt.push_back(i);
    for(int number = 1; number <=9999; number++){
        int t = number;
        vector<int> tmp;
        while(t>0){
            tmp.push_back(t%10);
            t/=10;
        }
      
        if(tmp.size()>n) break;
        cout <<"tmp.size: "<< tmp.size()<<endl;
        cout <<"tmp: "<<endl;
        for(auto k :tmp){
          cout<<k<<" ";
        }
        cout <<endl;

        sort(tt.begin(), tt.end());
        bool suc = false;
        do{
            cout <<"tt : "<<endl;
            for(auto k :tt){
              cout<<k<<" ";
            }
            cout <<endl;
            bool flag = true;
            for(int i=0; i<tmp.size(); i++){
              //cout<< arr[tt[i]][tmp[i]]<<" ";
                if(arr[tt[i]][tmp[i]] == false){
                    cout <<tmp[i]<<" is not found in "<< tt[i]<<endl;
                    flag = false;
                    break;
                }
            }
            //cout <<endl;
            if(flag){
                suc = true;
                break;
            }
        }while(next_permutation(tt.begin(), tt.end()));
        
        if(!suc){
            answer = number;
            break;
        }
    }
    
    
    return answer;
}

int main(){
  vector<vector<int>> dice = {{1, 6, 2, 5, 3, 4}, {9, 9, 1, 0, 7, 8}};
  cout <<solution(dice)<<endl;

}
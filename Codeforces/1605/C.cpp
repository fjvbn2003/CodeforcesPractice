//
// Created by Yongju KIM on 2021/11/16.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int test_case;
    cin>>test_case;
    while(test_case--){
        int n;
        string s;

        cin>>n;
        cin>>s;
        bool find_a = false;
        int c_b = 0;
        int c_c = 0;
        int idx_a;
        int min_length = 1234567890;
        for(int i=0; i<n; i++){
            if(s[i] == 'a'){
                if(find_a == false){
                    //a를 처음 만났을 때.
                    c_b = 0;
                    c_c = 0;
                    find_a = true;
                    idx_a = i;
                    continue;
                }
                if(c_b <2 && c_c <2){
                    min_length = min(min_length, i-idx_a+1);
                }
                c_b = 0;
                c_c = 0;
                idx_a = i;
            }else if(s[i] == 'b'){
                c_b++;
            }else{
                c_c++;
            }
        }
        if(min_length == 1234567890){
            cout <<-1<<endl;
        }else{
            cout <<min_length<<endl;
        }


    }


}
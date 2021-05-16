#include <iostream>
#include <string>

using namespace std;
int main(){
    string s;
    int test_case,a,b;
    int ra, rb, c, rq;
    int ssize;

    cin>>test_case;
    while(test_case--){
        cin>> a>> b;
        cin>> s;
        ra = 0;
        rb = 0;
        rq = 0;
        bool flag = false;
        if(s.size()%2 ==1){
            ssize = s.size()/2+1;
        }else{
            ssize = s.size()/2;
        }
        for(int i=0; i<ssize; i++){
            c = s.size()-i-1;
            if(s[i]=='0'){
                if(s[c]=='0'){
                    if(s.size()%2 == 1 && i==c){
                        ra+= 1;
                    }else{
                        ra+=2;
                    }
                }else if(s[c]=='1'){
                    flag = true;
                    break;
                }else{
                    s[c] = '0';
                    ra+= 2;
                }
            }else if(s[i]=='1'){
                if(s[c]=='1'){
                    if(s.size()%2 == 1 && i==c){
                        rb+= 1;
                    }else{
                        rb+=2;
                    }
                }else if(s[c]=='0'){
                    flag = true;
                    break;
                }else{
                    s[c] = '1';
                    rb+= 2;
                }
            }else{
                if(s[c] == '0'){
                    s[i] = '0';
                    ra+=2;
                }else if(s[c] == '1'){
                    s[i] = '1';
                    rb+=2;
                }else{
                    if(s.size()%2 == 1 && i==s.size()/2-1){
                        rq++;
                    }else{
                        rq+=2;
                    }
                }
            }
            // cout <<s<<endl;
            // cout <<ra<<" "<<rb<<endl;
            
        }
        if(ra>a || rb>b){flag = true;}
        else{
            for(int i=0; i<ssize; i++){
                 c = s.size()-i-1;
                if(s[c]=='?'){
                    if(ra+2<=a){
                        s[i] = '0';
                        s[c] = '0';
                        ra+=2;
                    }else if(rb+2 <= b){
                        s[i] = '1';
                        s[c] = '1';
                        rb+=2;
                    }else{
                        if(s.size()%2 == 1 && i==c){
                            if(ra+1 <=a){
                                s[i] = '0';
                                ra++;
                            }else if(rb +1 <=b){
                                s[i] = '1';
                                rb++;
                            }else{
                                flag = true;
                            }
                        }else{
                            flag = true;
                        }
                    }
                }
            }
        }
        if(flag){
            cout <<-1<<'\n';
        }else{
            if(ra== a && rb == b){
                cout << s<<'\n';
            }else{
                cout <<-1<<'\n';
            }
        }
    }
    return 0;

}
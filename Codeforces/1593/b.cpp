#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int test_case;
  cin>> test_case;
  while(test_case--){
    long long n;
    cin>>n;
    if(n%25 ==0 ){
      cout << 0 <<endl;
      continue;
    }


    // case1 00
    int ans = 123456789;
    int cnt1 = 0;
    int num_cnt = 0;
    long long t1 = n;
    while(t1){
      if(t1%10 == 0){
        num_cnt++;
        t1/=10;
        break;
      }
      cnt1++;
      t1/=10;
    }
    while(t1 && num_cnt>0){
      if(t1%10 == 0){
        num_cnt++;
        break;
      }
      cnt1++;
      t1/=10;
    }
    if(num_cnt ==2){
      ans = min(ans, cnt1);
    }
    // case2 25
    t1 = n;
    cnt1 = 0;
    num_cnt = 0;
    while(t1){
      if(t1%10 == 5){
        num_cnt++;
        t1/=10;

        break;
      }
      t1/=10;
      cnt1++;
    }
    while(t1 && num_cnt >0){
      if(t1%10 == 2){
        num_cnt++;
        t1/=10;

        break;
      }
      cnt1++;
      t1/=10;
    }
    if(num_cnt ==2){
      ans = min(ans, cnt1);
    }



    // case3 50
    t1 = n;
    cnt1 = 0;
    num_cnt = 0;
    while(t1){
      if(t1%10 == 0){
        num_cnt++;
        t1/=10;

        break;
      }
      cnt1++;
      t1/=10;
    }
    while(t1 && num_cnt>0){
      if(t1%10 == 5){
        num_cnt++;
        break;
      }
      cnt1++;
      t1/=10;
    }

    if(num_cnt ==2){
      ans = min(ans, cnt1);
    }

    // case4 75
    t1 = n;
    cnt1 = 0;
    num_cnt = 0;
    while(t1){
      if(t1%10 == 5){
        num_cnt++;
        t1/=10;
        break;
      }
      cnt1++;
      t1/=10;

    }
    while(t1 && num_cnt>0){
      if(t1%10 == 7){
        num_cnt++;
        break;
      }
      cnt1++;
      t1/=10;

    }
    if(num_cnt ==2){
      ans = min(ans, cnt1);
    }


    cout << ans<<endl;

  }
  return 0;
}
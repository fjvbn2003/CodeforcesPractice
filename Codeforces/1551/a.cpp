# include <iostream>
using namespace std;

int main(){
  int test_case;
  cin>>test_case;
  while(test_case--){
   int n;
   cin>>n;
   if(n%3 ==0){
    cout <<n/3<<" "<<n/3<<endl;
   }else if(n%3 ==1){
      cout <<n/3+1<<" "<<n/3<<endl;
    }else{
      cout<<n/3<<" "<<n/3+1<<endl;
    }

  }
  return 0;
}

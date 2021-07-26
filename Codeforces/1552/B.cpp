#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main(){
  int test_case;  
  cin>> test_case;
  while(test_case--){
    int n;
    cin>>n;
    vector<vector<int> > arr(n, vector<int>(5));
    for(int i=0; i<n; i++){
      for(int j=0; j<5; j++){
        cin>> arr[i][j];
      }
    }
    vector<int> in_node(n,0);
    vector<int> out_node(n,0);
    
    for(int i=0; i<n; i++){
      for(int j=i+1; j<n; j++){
        int cnt = 0;
        for(int k=0; k<5; k++)
          if(arr[i][k]<arr[j][k])
            cnt++;
        //if cnt>=3 i win
        if(cnt>=3){
          in_node[i]+=1;
          out_node[j]+=1;

        //j win
        }else{
          in_node[j]+=1;
          out_node[i]+=1;
        }
      }
    }
    bool flag = false;
    for(int i=0; i<n; i++){
      if(in_node[i]==n-1 && out_node[i]==0){
        cout << i+1<<endl;
        flag = true;
        break;
      }
    }
    if(!flag){
      cout <<-1<<endl;
    }

  }
}
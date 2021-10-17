#include <iostream>
#include <set>

using namespace std;
struct Data
{
        int a ;
        int b ;
        int c;
} ;
 
struct DataCompare
{
  bool operator() ( const Data& lhs, const Data& rhs) const{
    if(lhs.a == rhs.a){
      return lhs.b>rhs.b;
    }      
    return lhs.a < rhs.a;

  }
};
set<Data, DataCompare> setData;

int main(){
  Data data;

  data.a = 3 ;
  data.b = 5 ;
  setData.insert(data) ;

  data.a = 2 ;
  data.b = 5 ;
  setData.insert(data) ;

  data.a = 2 ;
  data.b = 2 ;
  setData.insert(data) ;

  data.a = 6 ;
  data.b = 8 ;
  setData.insert(data) ;

  data.a = 1 ;
  data.b = 7 ;
  setData.insert(data) ;

  for(auto iter = setData.begin(); iter != setData.end(); iter++){
    cout << iter->a<<" "<< iter->b<<endl;
  }
  return 0;

}
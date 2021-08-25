#include <iostream>
#include <set>
using namespace std;
 
int main(void){
    multiset<int> ms;
 
    ms.insert(9);    
    ms.insert(13);
    ms.insert(5);        
    ms.insert(7);
    ms.insert(3);
    ms.insert(1);
    ms.insert(11);
    ms.insert(15);
 
    multiset<int>::iterator iter;
    for(iter = ms.begin(); iter != ms.end(); iter++){
        cout << *iter << " " ;
    }
    cout << endl;
    cout << "ms.count(11) : " << ms.count(11) << endl << endl;
 
    
    //원소값 3, 11, 11 을 추가해보겠습니다. 
    ms.insert(3);
    ms.insert(11);
    ms.insert(11);
    for(iter = ms.begin(); iter != ms.end(); iter++){
        cout << *iter << " " ;
    }
    cout << endl;
    cout << "ms.count(11) : " << ms.count(11) << endl ;
    
    return 0;    
}
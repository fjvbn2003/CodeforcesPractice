#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    
    unordered_map<string,int> um;
    
    if(um.empty()){
        cout<<"unordered_map은 비어있습니다"<<endl;
    }
    
    um.insert(make_pair("key",1));
    um["banana"]=2;
    um.insert({"melon",3});
    
    cout<<"unordered_map의 크기는 "<<um.size()<<" 입니다"<<endl;
    
    // auto로 해도 무방
    for(pair<string,int> elem : um){
        cout<<"key : "<<elem.first<<" value : "<<elem.second<<endl;
    }
    
    // find 대신 count로 확인 가능
    if(um.find("banana")!=um.end()){
        um.erase("banana");
    }
    
    cout<<"unordered_map의 크기는 "<<um.size()<<" 입니다"<<endl;
    for(auto elem : um){
        cout<<"key : "<<elem.first<<" value : "<<elem.second<<endl;
    }
    
    return 0;
}
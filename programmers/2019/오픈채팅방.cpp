#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;
struct rec{
  string uid;
  int op;
};
vector<string> solution(vector<string> records) {
 vector<rec> answer;
  map<string, string> Map;
  for(string record : records){
    stringstream ss(record);
    string op, id, name;
    ss>>op;
    if(op=="Enter"){
      ss>>id>>name;
      
    Map[id] = name;
      
      answer.push_back({id, 0});

    }else if(op=="Leave"){
      ss>>id;
      answer.push_back({id, 1});
    }else if(op=="Change"){
      ss>>id>>name;
      Map[id] = name;
    }
  }
  vector<string> answers;
  for(int i=0; i< answer.size(); i++){
    if(answer[i].op == 0){
      answers.push_back(Map[answer[i].uid]+"님이 들어왔습니다.");
    }else{
      answers.push_back(Map[answer[i].uid]+"님이 나갔습니다.");
    }
  }
    return answers;
}
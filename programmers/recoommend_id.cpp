#include <iostream>
#include <string>

using namespace std;

bool satisfiy(const string & s){
  int l = s.size();
  if(l<3 || l>15) return false;
  for(int i=0; i<l; i++){
    if(s[i]=='-' || s[i] =='.' || s[i]=='_' || ('a'<=s[i] && s[i]<='z') ||('0'<=s[i] && s[i]<='9')){
      continue;
    }else{
      return false;
    }
  }
  if(s[0]=='.' || s.back()=='.') return false;
  bool dot = false;
  for(int i=0; i<l; i++){
    if(s[i]=='.'){
      if(dot) return false;
      dot = true;
    }
    else{
      dot = false;
    }
  }
  return true;
}
void remove_char(string & s){
  for(int i=0; i<s.size(); i++){
    if(s[i]=='-' || s[i] =='.' || s[i]=='_' || ('a'<=s[i] && s[i]<='z') ||('0'<=s[i] && s[i]<='9')){
      continue;
    }else{
      s =  s.substr(0,i) + s.substr(i+1);
      i-=1;
    }
  }
  return;
}
void lower(string &s){
  for(int i=0; i<s.size(); i++){
    s[i] = tolower(s[i]);
  }
  return;
}
void remove_dots(string &s){
  bool dot =  false;
  for(int i=0; i<s.size(); i++){
    if(s[i]=='.'){
      if(dot){
        s = s.substr(0,i)+s.substr(i+1);
        // cout<<s.substr(0,i)<<" "<<s.substr(i)<<endl;
        i-=1;
      }
      dot = true;
    }else{
      dot  = false;
    }
  }
  if(s[0]=='.'){
    s = s.substr(1);
  }
  if(s.back() == '.'){
    s = s.substr(0, s.size()-1);
  }
  return;
}
int main(){

  string id = "b...";
  if(satisfiy(id)){
    cout << id<<endl;
  }else{
    lower(id);
    remove_char(id);
    remove_dots(id);
    if(id == ""){
      id = "a";
    }
    if(id.size()>=16){
      id = id.substr(0,15);
    }
    if(id.back()=='.'){
      id = id.substr(0, id.size()-1);
    }
    while(id.size()<=2){
      id = id+id.back();
    }
    cout <<id<<endl;
  }
  return 0;
}
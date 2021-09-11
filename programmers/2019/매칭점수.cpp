#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct page{
  page(){
    basic_score=0;
    link_score = 0;
    outer_size =0;
    outerlink = vector<int>();
    url = "";
  }
  string url;
  double basic_score;
  int outer_size;
  double link_score;
  vector<int> outerlink;
};

int main(){
  string word = "blind";
  vector<string> pages = {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"};
  vector<page> my_pages;
  map<string, int> Map;

  //find url idx 
  for(int i=0; i<pages.size(); i++){
        page p;

    string s  = pages[i];
    int idx = 0;
    idx = s.find("<head",idx);
    string url;
    while(idx != string::npos){
      idx = s.find("<meta", idx);
      int idx2 = s.find(">", idx);  
      int tmp = s.find("https:", idx);
      if(idx<tmp && tmp <idx2){
        int tt = s.find("\"", tmp);
        url =  s.substr(tmp, tt-tmp );

        Map[url] = i;
        //cout << s.substr(tmp, tt-tmp )<<endl;
        idx = tmp;
        break;
      }
      idx = idx2;
    }
    p.url = url;
    my_pages.push_back(p);
  }
  // for (auto t : Map){
  //   cout <<t.first<<endl;
  // }
  // find links
  for(int i=0; i<pages.size(); i++){
    string s  = pages[i];
    int idx = 0;
    int cnt=0;
    
    while(idx != string::npos){
      idx = s.find("<a",idx); 
      int idx2  = s.find(">" ,idx);
      int tmp = s.find("https:", idx);
      if(idx<tmp && tmp < idx2){
        int tt = s.find("\"", tmp);
        cnt++;
        //cout <<s.substr(tmp, tt-tmp)<<endl;
        if(Map.count(s.substr(tmp, tt-tmp)) >0){
          my_pages[i].outerlink.push_back(Map[s.substr(tmp, tt-tmp)]);
        }
      }
      idx = idx2;
    }
    my_pages[i].outer_size = cnt;
    //cout <<"hi"<<endl;
  }
  // find word
  for(int i=0; i<pages.size(); i++){
    string s  = pages[i];
    string w = word;
    for(int i=0; i<s.size(); i++)
      s[i] = tolower(s[i]);
    for(int i=0; i<w.size(); i++)
      w[i] = tolower(w[i]);
    int idx = 0;
    int cnt = 0;
    while(idx != string::npos){
      idx = s.find(w, idx);
      if(idx == string::npos) break;
      if(isalpha(s[idx-1]) || isalpha(s[idx+w.size()])){
        idx++;
        continue;
      }
      idx++;
      cnt++;
    }
    my_pages[i].basic_score = cnt;
  }
  for(int i=0; i<my_pages.size(); i++){
    for(int j=0; j<my_pages[i].outerlink.size(); j++){
      // cout << "i: "<<i<<" : "<<my_pages[i].outerlink[j]<<endl;
      my_pages[my_pages[i].outerlink[j]].link_score += ((double)my_pages[i].basic_score)/(my_pages[i].outer_size);
    }
  }
  vector<pair<double, int> > answer;

  for(int i=0; i<my_pages.size(); i++){
    //cout <<"basic: "<< my_pages[i].basic_score <<" link: "<< my_pages[i].link_score<<" size: "<<my_pages[i].outer_size<<endl;
    answer.push_back({(double)my_pages[i].basic_score+my_pages[i].link_score,i});
  }
  sort(answer.begin(), answer.end());
  cout << answer.back().second<<endl;
  return 0;
}
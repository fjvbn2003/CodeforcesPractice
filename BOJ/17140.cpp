#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;
int r,c,k;
vector<vector<int> > arr;
bool comp(const pair<int, int> &a, const pair<int, int> & b){
    if(a.second == b.second){
        return a.first <b.first;
    }
    return a.second <b.second;
}

int main(){
    arr.resize(100, vector<int>(100, 0));
    cin>>r>>c>>k;
    r--;
    c--;

    int r_size =3;
    int c_size =3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    // 바로 찾았을 경우.
    if(arr[r][c]==k){
        cout <<0<<endl;
        return 0;
    }

    bool find = false;
    int ans = -1;
    for(int time=1; time<=100; time++){
        // 로우 갯수가 컬럼 갯수보다 많을 경우.

        if(r_size>=c_size) {
            // 모든 로우에 대해서.
            int max_c = -1;
            for(int i=0; i<r_size; i++){
                // i열 정렬.
                map<int , int> mp;
                for(int j=0; j<c_size; j++){
                    if(arr[i][j]==0) continue;
                    if(mp.count(arr[i][j])>0) mp[arr[i][j]]++;
                    else mp.insert(make_pair(arr[i][j],1));
                }
                vector<pair<int, int> > tmp;
                for(auto t : mp){
                    tmp.push_back(t);
                }
                sort(tmp.begin(), tmp.end(), comp);
                int tmp_c = tmp.size()*2;
                tmp_c = min(100, tmp_c);
                max_c = max(tmp_c, max_c);
                int cnt =0;
                for(auto t : tmp){
                    arr[i][cnt++] = t.first;
                    arr[i][cnt++] = t.second;
                    if(cnt>=100) break;
                }

                for(int t=cnt; t<100; t++){
                    arr[i][t] = 0;
                }
            }
            c_size = max_c;
        }else{// 컬럼 갯수가 많을 경우
            // 모든 컬럼에 대해서.
            int max_r = -1;
            for(int i=0; i<c_size; i++){
                // i열 정렬.
                map<int , int> mp;
                for(int j=0; j<r_size; j++){
                    if(arr[j][i]==0) continue;
                    if(mp.count(arr[j][i])>0) mp[arr[j][i]]++;
                    else mp.insert(make_pair(arr[j][i],1));
                }
                vector<pair<int, int> > tmp;
                for(auto t : mp){
                    tmp.push_back(t);
                }
                sort(tmp.begin(), tmp.end(), comp);

                int tmp_r = tmp.size()*2;
                tmp_r = min(100, tmp_r);
                max_r = max(max_r, tmp_r);

                int cnt =0;
                for(auto t : tmp){
                    arr[cnt++][i] = t.first;
                    arr[cnt++][i] = t.second;
                    if(cnt>=100) break;
                }
                for(int t=cnt; t<100; t++){
                    arr[t][i] = 0;
                }
            }
            r_size = max_r;
        }
//        cout <<"r_size: "<<r_size<<" c_size: "<<c_size<<endl;
//        for(int i=0; i<r_size; i++){
//            for(int j=0; j<c_size; j++){
//                cout <<arr[i][j]<<" ";
//            }
//            cout <<endl;
//        }
//        cout <<endl;


        if(arr[r][c]==k){
            ans = time;
            find = true;
            break;
        }
    }

    cout <<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<vector<int>> count(10,vector<int>(10));
    string s;
    cin>>s;
    for(int i=1;i<s.size();i++){
        count[s[i-1]-'0'][s[i]-'0']++;
    }
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    int mi = INT_MAX;
    do{
        count[a[0]][s[0]-'0']++;
        vector<vector<int>> dist(10,vector<int>(10));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                dist[a[i]][a[j]] = abs(i-j);
            }
        }
        int sum=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                sum+=dist[i][j]*count[i][j];
            }
        }
        mi = min(sum,mi);
        count[a[0]][s[0]-'0']--;
    }while(next_permutation(a.begin(),a.end()));
    cout<<mi+s.size()<<endl;
}
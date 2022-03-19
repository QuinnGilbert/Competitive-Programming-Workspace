#include <bits/stdc++.h>

using namespace std;

bool check(vector<vector<char>> &a, vector<vector<bool>> &result, bool fin, int index){
    int n=7;
    int r = index/n;
    int c = index%n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!='.'){
                int count=0;
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        if(x+i<n&&x+i>=0&&y+j<n&&y+j>=0){
                            if(result[x+i][y+j]) count++;
                        }
                    }
                }
                if(count>(a[i][j]-'0')) return false;
                if((fin||(r>i+1&&c>j+1))&&count!=(a[i][j]-'0')) return false;

            }
            // if(result[i][j]){
            //     bool check = false;
            //     for(int x=-1;x<=1;x++){
            //         for(int y=-1;y<=1;y++){
            //             if(x+i<n&&x+i>=0&&y+j<n&&y+j>=0){
            //                 if(a[i+x][j+y]!='.') check = true;
            //             }
            //         }
            //     }
            //     if(!check) return false;
            // }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(result[i][j]){
    //             cout<<'*';
    //         }else{
    //             cout<<a[i][j];
    //         }
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // cout<<"TRUE"<<endl;
    return true;
}

bool find(vector<vector<char>> &a, vector<vector<bool>> &result, int index, int count){
    // cout<<index<<endl;
    int n = 7;
    int r=index/n;
    int c=index%n;
    if(index==49){
        return (count==10)&&check(a,result,true,index);
    }
    if(a[r][c]!='.'){
        return find(a,result,index+1,count);
    }
    result[r][c] = true;
    if(count<10&&check(a,result,false,index)){
        if(find(a,result,index+1,count+1)) return true;
    }
    result[r][c] = false;
    if(find(a,result,index+1,count)) return true;
    return false;
}



int main(){
    int t;
    cin>>t;
    for(int q=0;q<t;q++){
        int n = 7;
        vector<vector<char>> a(7,vector<char>(7));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        vector<vector<bool>> res(7,vector<bool>(7));
        find(a,res,0,0);
        cout<<"Tentaizu Board #"<<q+1<<":"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(res[i][j]){
                    cout<<'*';
                }else{
                    cout<<a[i][j];
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
}
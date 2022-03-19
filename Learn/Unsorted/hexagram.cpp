#include <bits/stdc++.h>

using namespace std;

int gen(vector<int> &a,vector<int> &v, int index, vector<bool> &used){
    // if(a[0]==7&&a[1]==23&&a[2]==15&&a[3]==12){
    //     for(int i=0;i<12;i++){
    //         cout << a[i]<< " ";
    //     }
    //     cout << endl;
    // }
    int sum = a[0]+a[1]+a[2]+a[3];
    if(index==7){
        if(a[4]+a[1]+a[5]+a[6]!=sum)return 0;
    }
    if(index==9){
        if(a[0]+a[5]+a[7]+a[8]!=sum)return 0;
    }
    if(index==11){
        if(a[4]+a[2]+a[9]+a[10]!=sum)return 0;
    }
    if(index==12){
        if(a[6]+a[7]+a[11]+a[10]==sum&&sum==a[3]+a[9]+a[11]+a[8]){
            return 1;
            // cout <<"CHECK"<<endl;
        }
        // cout << sum << " " << a[6]+a[7]+a[11]+a[10] << " " << 
        return 0;
    }
    int count=0;
    for(int i=0;i<12;i++){
        if(!used[i]){
            used[i]=true;
            a[index]=v[i];
            count+=gen(a,v,index+1,used);
            used[i]=false;
            a[index]=0;
        }
    }
    return count;
}

int main(){
    while(true){
        vector<int> a(12);
        for(int i=0;i<12;i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        if(a[0]==0&&a[11]==0)break;
        vector<int> res(12);
        vector<bool> used(12);
        int count=gen(res,a,0,used);
        // do{
        //     int sum = a[0]+a[1]+a[2]+a[3];
        //     if(sum==a[4]+a[1]+a[5]+a[6]){
        //         if(sum==a[0]+a[5]+a[7]+a[8]){
        //             if(sum==a[4]+a[2]+a[9]+a[10]){
        //                 if(sum==a[6]+a[7]+a[11]+a[10]){
        //                     if(sum==a[3]+a[9]+a[11]+a[8]){
        //                         count++;
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }while(next_permutation(a.begin(),a.end()));
        cout<<count/12<<endl;
    }
}


//1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10 11 11 12 12

// 6*sum-3sum
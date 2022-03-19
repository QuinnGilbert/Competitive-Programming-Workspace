#include <bits/stdc++.h>

using namespace std;

bool check(long long x,long long n,long long k,long long m){
    long long prev = -1;
    long long sum = 0;
    while(k>0){
        long long value = (n-sum)/x;
        // cout<<value<<endl;
        if(value<=m){
            sum+=k*m;
            break;
        }
        if(value==prev){
            //currenty (n-sum)/x = value
            //meaning value*x = (n-sum)
            //find number of times you would have to add value to change value
            //(n-sum-value*x ) / value 
            long long times = (n-sum-value*x)/value;
            sum+=times*value;
            k-=times;
        }
        sum+=value;
        prev=value;
        k--;
    }
    return sum>=n;
}

int main(){

    ifstream fin("loan.in");
    ofstream fout("loan.out");

    long long n,m,k;
    fin>>n>>k>>m;

    long long low = 1;
    long long high = n+1;
    while(low<high-1){
        // cout<<low<<" "<<high<<endl;
        long long mid = (low+high)/2;
        if(check(mid,n,k,m)){
            low=mid;
        }else{
            high=mid;
        }
    }
    fout<<low<<endl;
}

// 5 3 3

//100
//50 25 
//33 22 15 10

//1000000000000 
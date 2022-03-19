#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

vector<vector<double>> multiply(vector<vector<double>> a, vector<vector<double>> b){
    
}

vector<vector<double>> pow(vector<vector<double>> x, int p){

    int n = x.size();
    vector<vector<double>> result(n,vector<double>(n));
    for(int i=0;i<n;i++){
        result[i][i] = 1;
    }
    while(p){
        if(p%2==1){
            result = multiply(result,x);    
        }
        p=p>>1;
        x = multiply(x,x);
    }

}
//NOTE: My original idea doesn't work because you can't multiply two non-constants with fast matrix expo?
int main(){

    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n,k;
    double p;
    cin>>n>>k>>p;
    int length = (1<<n)+2;//every possible state + number of moves + answer
    vector<vector<double>> matrix(length,vector<double>(length));
    //add each number with k bits to win (times moves)
    //increment moves
    for(int i=0;i<(i<<n);i++){
        int count=0;
        int x=i;
        while(x>0){
            if(x%2==1)count++;
            x/=2;
        }
        // if(count=)
        int loss = (i%(1<<n)*2);
        int win = (i%(1<<n)*2)+1;
        matrix[loss][i] = 1-p;
        matrix[win][i] = p;
    }

}

/*

*/
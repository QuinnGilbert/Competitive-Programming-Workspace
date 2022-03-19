/*
TASK: msquare
LANG: C++14
*/


#include<iostream>
#include<math.h>
#include<deque>
#include<vector>
#include<stdlib.h>
#include<fstream>

using namespace std;

struct State{
    int x[8];
    int d;
    State(int a[],int b){
        for(int i=0;i<8;i++){
            x[i]=a[i];
        }
        d=b;
    }
};

void change(int x[], int a[], int b[], int c[]){
    a[0] = x[7];
    a[1] = x[6];
    a[2] = x[5];
    a[3] = x[4];
    a[4] = x[3];
    a[5] = x[2];
    a[6] = x[1];
    a[7] = x[0];

    b[0] = x[3];
    b[1] = x[0];
    b[2] = x[1];
    b[3] = x[2];
    b[4] = x[5];
    b[5] = x[6];
    b[6] = x[7];
    b[7] = x[4];

    c[0] = x[0];
    c[1] = x[6];
    c[2] = x[1];
    c[3] = x[3];
    c[4] = x[4];
    c[5] = x[2];
    c[6] = x[5];
    c[7] = x[7];
}


int value(int a[]){
    int pow = 1;
    int res = 0;
    for(int i=0;i<8;i++){
        res+=pow*(a[i]-1);
        pow*=8;
    }
    return res;
}

int a[8];
int initial[8];
bool v[16777216];
int previous[16777216];
char prec[16777216];

int main(){
    
    ifstream fin("msquare.in");
    ofstream fout("msquare.out");

    for(int i=0;i<8;i++){
        // cin >> a[i];
        fin >> a[i];
        initial[i] = i+1;
    }
    deque<State> q;
    q.push_back(State(initial,0));
    v[value(initial)] = true;
    previous[value(initial)] = -1;
    while(!q.empty()){
        State s = q.front();
        q.pop_front();
        // for(int i=0;i<8;i++){
        //     cout<<s.x[i];
        // }
        // cout << endl;
        bool check = true;
        for(int i=0;i<8;i++){
            if(s.x[i]!=a[i]){
                check = false;
            }
        }
        if(check){
            // cout <<s.d<<endl;
            fout <<s.d<<endl;
            int x = value(s.x);
            deque<char> temp;
            while(previous[x]!=-1){
                temp.push_front(prec[x]);
                x = previous[x];
            }
            while(!temp.empty()){
                // cout << temp.front();
                fout << temp.front();
                temp.pop_front();
            }
            // cout << endl;
            fout << endl;
            break;
        }
        int A[8];
        int B[8];
        int C[8];
        change(s.x,A,B,C);
        if(!v[value(A)]){
            q.push_back(State(A,s.d+1));
            v[value(A)] = true;
            previous[value(A)] = value(s.x);
            prec[value(A)] = 'A';
        }
        if(!v[value(B)]){
            q.push_back(State(B,s.d+1));
            v[value(B)] = true;
            previous[value(B)] = value(s.x);
            prec[value(B)] = 'B';
        }
        if(!v[value(C)]){
            q.push_back(State(C,s.d+1));
            v[value(C)] = true;
            previous[value(C)] = value(s.x);
            prec[value(C)] = 'C';
        }
    }
    cout << "Done";
    fin.close();
    fout.close();
}


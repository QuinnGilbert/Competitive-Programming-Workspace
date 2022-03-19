#include <bits/stdc++.h>

using namespace std;

struct peice{
    vector<int> a;
    int i;
    peice(int A,int B, int C, int D, int index){
        a.push_back(A);
        a.push_back(B);
        a.push_back(C);
        a.push_back(D);
        i=index;
    }
    peice(){}
    void print(){
        cout<<"i="<<i<<" a="<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
    }
};
//a[0]=left, a[1] = down, a[2] = right, a[3] = up

// void processRow(){
//     //might be able to just do this in main
    
// }

void rotate(peice &p){
    p.a.push_back(p.a[0]);
    p.a.erase(p.a.begin());
}

int main(){

    int n;
    cin>>n;
    unordered_map<int,vector<peice>> side;
    bool four = false;
    bool three = false;
    bool two = false;
    peice start;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        peice p = peice(a,b,c,d,i);
        if(a!=0)side[a].push_back(p);
        if(b!=0)side[b].push_back(p);
        if(c!=0)side[c].push_back(p);
        if(d!=0)side[d].push_back(p);
        if((a==0)+(b==0)+(c==0)+(d==0)==4) four = true;
        if((a==0)+(b==0)+(c==0)+(d==0)==3){ 
            three = true;
            start = p;
        }
        if((a==0)+(b==0)+(c==0)+(d==0)==2&&!two){
            two = true;
            start = p;
        }
    }
    // for(int i=1;i<7;i++){
    //     cout<<i<<endl;
    //     side[i][0].print();
    //     side[i][1].print();
    // }

    if(four||n==1){
        if(four&&n==1){
            cout<<"1 1"<<endl;
            cout<<"1"<<endl;
        }else{
            cout<<"impossible"<<endl;
        }
        return 0;
    }
    if(three){
        
        vector<peice> puzzle;
        vector<bool> used(n*4+1);
        int count=1;
        used[start.i]=true;
        while(start.a[2]==0){
            rotate(start);
        }
        puzzle.push_back(start); 
        while(puzzle[puzzle.size()-1].a[2]!=0){
            peice p = side[puzzle[puzzle.size()-1].a[2]][0];
            if(used[p.i]) p = side[puzzle[puzzle.size()-1].a[2]][1];
            while(p.a[0]!=puzzle[puzzle.size()-1].a[2]){
                rotate(p);
            }
            if(used[p.i]||p.a[1]!=0||p.a[3]!=0){
                cout<<"impossible"<<endl;
                return 0;
            }
            puzzle.push_back(p);
            used[p.i]=true;
            count++;
        }
        if(count!=n){
            cout<<"impossible"<<endl;
            return 0;
        }
        cout<<"1 "<<n<<endl;
        for(int i=0;i<n;i++){
            cout<<puzzle[i].i+1<<" ";
        }
        cout<<endl;

        return 0;
    }
    if(!two){
        cout<<"impossible"<<endl;
        return 0;
    }

    // cout<<"CHECK1"<<endl;

    while(!(start.a[0]==0&&start.a[3]==0)){
        rotate(start);
        if(start.a[0]==0&&start.a[2]==0){
            cout<<"impossible"<<endl;
            return 0;
        }
    }
    // cout<<"CHECK2"<<endl;
    vector<bool> used(n*4+1);
    used[start.i]=true;
    vector<vector<peice>> puzzle;
    puzzle.push_back(vector<peice>());
    puzzle[0].push_back(start);
    int count=1;
    // start.print();
    //add first row
    while(puzzle[0][puzzle[0].size()-1].a[2]!=0){
        peice p = side[puzzle[0][puzzle[0].size()-1].a[2]][0];
        if(used[p.i]) p = side[puzzle[0][puzzle[0].size()-1].a[2]][1];
        while(p.a[0]!=puzzle[0][puzzle[0].size()-1].a[2]){
            rotate(p);
        }
        if(used[p.i]||p.a[3]!=0||p.a[1]==0) {
            // cout<<puzzle[0].size()<<endl;
            // p.print();
            cout<<"impossible"<<endl;
            return 0;
        }
        puzzle[0].push_back(p);
        used[p.i] = true;
        count++;
    }
    int c = puzzle[0].size();
    // for(int i=0;i<c;i++){
    //     cout<<puzzle[0][i].i<<" ";
    // }
    // cout<<endl;
    if(n%c!=0){
        // cout<<"n/c"<<endl;
        cout<<"impossible"<<endl;
        return 0;
    }

    // cout<<"CHECK3"<<endl;

    for(int i=1;i<n/c;i++){
        // cout<<"i="<<i<<endl;
        // cout<<"CHECK11"<<endl;
        puzzle.push_back(vector<peice>());
        // cout<<"CHECK15"<<endl;
        // cout<<puzzle[i-1][0].a[1]<<endl;
        if(puzzle[i-1][0].a[1]==0){
            cout<<"impossible"<<endl;
            return 0;
        }
        peice first = side[puzzle[i-1][0].a[1]][0];
        // cout<<"CHECK14"<<endl;
        if(used[first.i])first = side[puzzle[i-1][0].a[1]][1];
        // cout<<"CHECK13"<<endl;
        while(first.a[3]!=puzzle[i-1][0].a[1]){
            rotate(first);
        }
        // cout<<"CHECK12"<<endl;
        if(first.a[0]!=0||first.a[2]==0||used[first.i]){
            cout<<"impossible"<<endl;
            return 0;
        }
        puzzle[i].push_back(first);
        used[first.i] = true;
        count++;
        // cout<<"CHECK5"<<endl;
        // cout<<first.i<<endl;
        while(puzzle[i][puzzle[i].size()-1].a[2]!=0){
            // cout<<"CHECK7"<<endl;
            peice p = side[puzzle[i][puzzle[i].size()-1].a[2]][0];
            if(used[p.i])p=side[puzzle[i][puzzle[i].size()-1].a[2]][1];
            while(p.a[0]!=puzzle[i][puzzle[i].size()-1].a[2]){
                rotate(p);
            }
            // cout<<"CHECK6"<<endl;
            if(used[p.i]||p.a[3]==0){
                cout<<"impossible"<<endl;
                return 0;
            }
            puzzle[i].push_back(p);
            used[p.i] = true;
            count++;
            // cout<<"CHECK8"<<endl;
        }
        // cout<<"CHECK9"<<endl;
        if(puzzle[i].size()!=c){
            cout<<"impossible"<<endl;
            return 0;
        }
        // cout<<"CHECK10"<<endl;
    }

    // cout<<"CHECK4"<<endl;

    for(int i=0;i<c;i++){
       if(puzzle[puzzle.size()-1][i].a[1]!=0){
           cout<<"impossible"<<endl;
           return 0;
       }
    }

    cout<<n/c<<" "<<c<<endl;
    for(int i=0;i<n/c;i++){
        for(int j=0;j<c;j++){
            cout<<puzzle[i][j].i+1<<" ";
        }
        cout<<endl;
    }

}

//bug in code is due to 2 peices being assigned to each value, but I am only writing one in "side"
//need better way to organize peices in side
//quick fix: store a pair in side, and check if first index is used

/*
if you add each shape row by row, you only need to check if it matches the element at the top

to build:
- start with a corner piece
- orient it so that it becomes top left piece
- add the peice on the right
- if not first row, check if it matches the above row
- if you ever find that a piece is already used, it is impossible

at the end to be correct it must:
- have the same number of pieces in each row
- have correct edges on all sides
- have all inside pieces match (should be checked while adding)
- have all n pieces used

edge cases:
- only 1 piece
- only 1 row (2 pieces with 3 zeroes and all others with 2 zeroes)
*/
#include <bits/stdc++.h>

using namespace std;

// struct 

int main(){

    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    string s;
    cin>>s;
    priority_queue<int,vector<int>,greater<int>> left;
    priority_queue<int,vector<int>,greater<int>> right;
    priority_queue<int,vector<int>,greater<int>> sum;



}




/*

To compute initial alarms for vertical segment of length L:
- if segment decreases on A, set alarm for when A=L
- if segment decreases on B, set alarm for when B=L
- if segment decreases on A and B, set alarm for when A+B=L (i=L)

process whenever vertical segments disappear:
- delete segemnt
- merge horizontal
- recompute alarms

To recompute alarms:
- 


*/












//OOPS my solution breaks since for some it is overcounting (7 4 3 5 AA)
//In other words, we cannot actually merge all of these elements

/*
Observations:
- It should still be true that up until some value overtakes another, the order does not matter
- Values should keep growing (if they were initially up until they reach a local maximum)
- When a local minimum levels out on one side, all increasing values on the other side should also level out
- If a value to the left is lesser, it will always be either lesser or equal (by same logic, greater will always be greater)
- Up to that point, each value can either:
    1. Not be affected (local maximum)
    2. Grow from both sides
    2. Grow from only 1 side

- The lower value will only merge if the value that they are merging with has not yet changed
- Each increasing subarray will increase together (except for the last value)
- Since this is true, now the only things that should matter are when a value actually merges (with a local max) [NEED TO VERIFY]

imagine we have an array A B C with B<A<C
if there are B-A left shifts then B will no longer respond to 

*/

//If I'm going to keep thinking about this I should just start implementing it and change it to work as I go along

//keep 3 queues for left, right, and sum

/*
EX:
4 3 5 3 6 6 BABAA
(4,1) (3,1) (5,1) (3,1) (6,2)
(4,2) (5,1) (3,1) (6,2)


5 4 3 2 1 2 3 4 5
5 4 3 2 2 3 4 5 5

*/
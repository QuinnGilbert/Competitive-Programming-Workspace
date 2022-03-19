#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> next(n);
    fill(next.begin(),next.end(),-1);
    deque<pair<int,int>> q;
    for(int i=0;i<n;i++){
        while(!q.empty()&&q.front().first<a[i]){
            next[q.front().second] = i;
            q.pop_front();
        }
        q.push_front(make_pair(a[i],i));
    }
    // for(int i=0;i<n;i++){
    //     cout<<next[i]<<endl;
    // }

    long long count=0;
    for(int i=0;i<n-1;i++){
        int index = i+1;
        while(true){
            // if(a[index]>max)  count++;
            // if(a[index]>max) max = a[index];
            // if(a[index]>a[i]) break;
            // index++;
            count+=index-i+1; //change to make it work for USACO 2022 Jan Silver Problem 2
            // count++;
            if(next[index]==-1||a[index]>a[i]) break;
            index = next[index];
        }
    }
    cout<<count<<endl;
}

/*
we can ignore the trivial cases and just add n-1

each left value will have at most a[i]-1 pairs (but might have to search through more than that number of values)
all a[i]-1 pairs will not work, if they are not in increasing order

I think (not proven) that the total number is <n^1.5

5 3 1 2 4
8 6 4 2 1 3 5 7

after a number appears inside, all right edges less than it are invalid
is there any way to skip to the next greatest value? yes

8 7 6 5 4 3 2 1
0 7 1 6 2 5 3 4



key observation should have been: you can only form a pair with 1 greater value on each side,
so if we think about each pair looking always looking at the smaller values, the answer is bounded by 2n

6
1 3 2 6 4 5

6 5 4 3 2 1
3 5 4 1 2 0
*/
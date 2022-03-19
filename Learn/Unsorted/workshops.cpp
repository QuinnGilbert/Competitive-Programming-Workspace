#include <bits/stdc++.h>

using namespace std;

int main(){
    int test=0;
    int w;
    // cin>>w;
    while(true){
        test++;
        cin>>w;
        if(w==0)break;
        vector<pair<int,int>> a(w);
        for(int i=0;i<w;i++){
            int x,y;
            cin>>x>>y;
            a[i]=make_pair(x,y);
        }
        int r;
        cin>>r;
        vector<pair<int,int>> b(r);
        for(int i=0;i<r;i++){
            int x;
            string s;
            cin>>x>>s;
            int time = 60*(stoi(s.substr(0,2))-14)+stoi(s.substr(3,5));
            b[i] = make_pair(x,time);
        }
        vector<bool> v(r);
        sort(a.begin(),a.end(),greater<pair<int,int>>());
        // for(int i=0;i<w;i++){
        //     cout<<a[i].first<<endl;
        // }
        int count=0;
        int sum=0;
        for(int i=0;i<w;i++){
            int min = INT_MAX;
            int mini = -1;
            for(int j=0;j<r;j++){
                if(a[i].first<=b[j].first&&a[i].second<=b[j].second&&!v[j]){
                    if(b[j].second<min){
                        mini=j;
                        min=b[j].second;
                    }
                }
            }
            if(mini==-1){
                count++;
                sum+=a[i].first;
            }else{
                v[mini]=true;
            }
        }
        printf("Trial %d: %d %d\n",test,count,sum);
        cout<<endl;
    }

}

/*
PE potential errors:
space after print statement
double space after colon
extra new line on last case
*/


//maximize number of used workshops
//secondary maximize number of people in rooms

//want to fit the most workshops into all rooms
//want to use the shortest workshops with the most people first (except not really since one with more people )
//want to put each workshop into the smallest room possible

//once again, dp solution should be simple but lets practice the greedy

//actually I misinterpreted the problem, I think each room can only have one workshop (I'll assume this is correct for now)
/*

for a given room, you can only have 1 workshop
workshop can only fit if both people and time are less than capacity
maximize total workshops over total people
2 rooms can be better in different ways
if a workshop can fit into a room, you should always put it in the harshest room (but do we optimize by capacity or time?)


Next Day Thoughts:
if we start with the longest workshops, then any room this workshop can fit into (time-wise) will also fit all other workshops
now we have to optimize the people, so we can put this workshop into the lowest capacity room that it will fit into
this will maximize the number of rooms, but can it maximize the number of people?

No, but I think that if we swap it around to sort by people first then it will.
Yes! That should work.

*/
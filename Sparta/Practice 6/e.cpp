#include <bits/stdc++.h>

using namespace std;

int main(){

    int l,n;
    cin>>l>>n;
    vector<pair<int,int>> forward;
    vector<pair<int,int>> backward;
    int minv=INT_MAX;
    int maxv=0;
    int minf=INT_MAX;
    int minb=INT_MAX;
    int maxf=0;
    int maxb=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        minv=min(min(a,b),minv);
        maxv=max(max(a,b),maxv);
        if(a<b){
            minf=min(min(a,b),minf);
            maxf=max(max(a,b),maxf);
            forward.push_back(make_pair(a,b));
        }else{
            minf=min(min(a,b),minb);
            maxf=max(max(a,b),maxb);
            backward.push_back(make_pair(a,b));
            backward.push_back(make_pair(a,a));
        }
    }
    sort(forward.begin(),forward.end());
    sort(backward.begin(),backward.end(),greater<pair<int,int>>());
    int prev=minv;
    int sum1=0;
    int sum4=INT_MAX;
    for(int i=0;i<forward.size();i++){
        int diff = forward[i].second-forward[i].first;
        sum4=min(sum4,sum1+maxv-forward[i].first);
        sum1+=max(0,min(forward[i].second-prev,diff*2));
        prev=max(forward[i].second,prev);
    }
    prev=maxv;
    int sum2=0;
    int sum3=INT_MAX;
    for(int i=0;i<backward.size();i++){
        int diff = backward[i].first-backward[i].second;
        int minx;
        sum3=min(sum3,sum2+backward[i].first-minv);
        sum2+=max(0,min(prev-backward[i].second,diff*2));
        // cout<<sum2<<endl;
        // cout<<backward[i].first<<" "<<backward[i].second<<" "<<<<endl;
        prev=min(backward[i].second,prev);
    }
    // cout<<maxv-minv<<" "<<sum1<<" "<<sum2<<" "<<sum3<<endl;
    cout<<maxv-minv+min(min(sum1,sum2),min(sum3,sum4))<<endl;
}


/*
You have a sorted forward array and a backward array
You can either go through the entire array in 1 dir, or reloop over yourself for some if you pass them
In other words you can either add the distance to get from prev end to current start, or 2*|end-start|
BUT one of the directions must go the entire distance

WRONG because you can also start in the middle
also bc you can only use prev value if you came from prev

max-min+forward with redo 
or
max-min+backward with red


*/
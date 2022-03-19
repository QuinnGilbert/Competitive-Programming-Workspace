#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k,m,n;
    cin>>k>>m>>n;
    vector<pair<int,int>> a;
    vector<int> b(m);
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        a.emplace_back(x,y);
    }
    
    
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    b.push_back(-1000000001);
    b.push_back(1000000001);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int bi=0;
    unordered_map<int,int> change;
    // vector<int> points;
    vector<long long> all;
    int sum=0;

    for(int i=0;i<k;i++){
        if(a[i].first>b[bi+1]){
            int ma=0;
            int total=0;

            vector<pair<int,int>> points;
            
            // sort(change.begin(),change.end());

            for(auto i : change){
                // total+=i.second;
                // cout<<i.first<<" "<<i.second<<"total: "<<total<<endl;
                // ma=max(ma,total);
                points.emplace_back(i);
            }

            sort(points.begin(),points.end());

            for(auto i : points){
                total+=i.second;
                ma=max(ma,total);
            }

            all.push_back(ma);
            all.push_back(sum-ma);

            sum=0;
            change.clear();
            while(a[i].first>b[bi+1]){
                bi++;
            }
        }

        // cout<<a[i].first<<" "<<bi<<" "<<b[bi]<<"\n";
        sum+=a[i].second;
        if(a[i].first-b[bi]<=b[bi+1]-a[i].first){
            // points.push_back(b[bi]);
            // points.push_back((a[i].first-b[bi])*2+b[bi]);
            change[b[bi]]+=a[i].second;
            change[(a[i].first-b[bi])*2+b[bi]]-=a[i].second;
        }else{
            // points.push_back(b[bi+1]-(b[bi+1]-a[i].first)*2);
            // points.push_back(b[bi+1]);
            change[b[bi+1]-(b[bi+1]-a[i].first)*2]+=a[i].second;
            change[b[bi+1]]-=a[i].second;
        }
    }
    // sort(points.begin(),points.end());
    int ma=0;
    int total=0;
    for(auto i:change){
        total+=i.second;
        ma=max(ma,total);
    }
    all.push_back(ma);
    all.push_back(sum-ma);


    
    // for(int i:all){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    sort(all.begin(),all.end());

    long long result=0;
    for(int i=all.size()-1;i>=all.size()-n;i--){
        // cout<<i<<" "<<all[i]<<endl;
        result+=all[i];
    }
    cout<<result<<endl;

    // while(bi<m-1||ai<k) {
    //     if(bi==m-1||(ai<k&&a[ai].first<b[bi])) {
    //         if(a[ai].first-left<right-a[ai].first) {
    //             if(!all.count(left)){
    //                 points.push_back(left);
    //                 all.insert(left);
    //             }
    //             add[left]+=a[ai].second;
    //             if(!all.count(left+2*(a[ai].first-left))){
    //                 points.push_back(left+2*(a[ai].first-left));
    //                 all.insert(left+2*(a[ai].first-left));
    //             }
    //             sub[left+2*(a[ai].first-left)]+=a[ai].second;
    //             // cout<<"add: "<<left<<" sub: "<<left+2*(a[ai].first-left)<<endl;
    //         }else {
    //             // add(change,right-2*(right-a[ai].x),a[ai].y);
    //             if(!all.count(right)){
    //                 points.push_back(right);
    //                 all.insert(right);
    //             }
    //             sub[right]+=a[ai].second;
    //             if(!all.count(right-2*(right-a[ai].first))){
    //                 points.push_back(right-2*(right-a[ai].first));
    //                 all.insert(right-2*(right-a[ai].first));
    //             }
    //             add[right-2*(right-a[ai].first)]+=a[ai].second;
    //             // add(change,right,-a[ai].y);
    //             // cout<<"add: "<<right<<" sub: "<<right-2*(right-a[ai].first)<<endl;
    //         }
    //         ai++;
    //     }else {
    //         bi++;
    //         left = b[bi-1];
    //         right = b[bi];
    //     }
    // }

    // sort(points.begin(),points.end());
    // // for(int i:points){
    // //     cout<<i<<" ";
    // // }
    // // cout<<endl;

    // vector<long long> result;
    // long long sum=0;
    // long long ma=0;
    // long long cur=0;
    // for(int i:points){
    //     if(sub.count(i)){
    //         long long diff = sub[i];
    //         cur-=diff;
    //         // if(diff>=0) {
    //         //     sum+=diff;
    //         // }
    //         // ma=max(ma, cur);
    //     }
    //     if(end.count(i)) {
    //         result.push_back(ma);
    //         result.push_back(sum-ma);
    //         sum=0;
    //         ma=0;
    //         if(cur!=0){
    //             // cout<<"CHECK "<<i<<" "<<cur<<endl;
    //         }
    //     }
    //     if(add.count(i)){
    //         long long diff = add[i];
    //         cur+=diff;
    //         sum+=diff;
    //         ma=max(ma,cur);
    //     }
    //     // cout<<cur<<" "<<sum<<" "<<ma<<endl;
    // }
    // result.push_back(sum-ma);
    // result.push_back(ma);
    // sort(result.begin(),result.end());
    // // for(int i:result){
    // //     cout<<i<<" ";
    // // }
    // // cout<<endl;
    // sum=0;
    // for(int i=result.size()-1;i>=0&&i>=result.size()-n;i--) {
    //     sum+=result[i];
    // }
    // cout<<sum<<"\n";
}

/*
00 04 2
04 06 1
08 10 1
10 08 1
12 12 1
13 14 2

there should never be more than 1 point for each star point

will a greedy approach that always places at the largest point work? (I think so, but not proven)

I don't think we can compress the segments like I thought at first

can easilly coordinate compress (and also double everything so that all points are integers)

there are never segments past star points
*/
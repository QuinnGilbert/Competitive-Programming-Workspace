#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
    int t;
    cin >> t;
    for(int q=0;q<t;q++){
        int n,m;
        cin >>n>>m;
        vector<int> x(n);
        vector<int> y(n);
        for(int i=0;i<n;i++){
            cin >> x[i] >> y[i];
        }
        vector<vector<bool>> edge(n,vector<bool>(n,true));
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            edge[a][b]=false;
            edge[b][a]=false;
        }
        vector<int> perm(n);
        for(int i=0;i<n;i++){
            perm[i]=i;
        }
        double min = INT_MAX;
        do{
            double px = 0;
            double py = 0;
            bool check = true;
            int prev=perm[0];
            double sum = 0;
            for(int i=0;i<n;i++){
                if(!edge[prev][perm[i]]){
                    check = false;
                    break;
                }
                int next = perm[i];
                sum+=dist(px,py,x[next],y[next]);
                px=x[next];
                py=y[next];
                prev=next;
            }
            if(check&&sum<min){
                min=sum;
            }
        }while(next_permutation(perm.begin(),perm.end()));
        cout << "Vacation #" << q+1 << ":" << endl;
        // cout << min << endl;
        if(min!=INT_MAX){
            printf("Jimmy can finish all of the rides in %.3lf seconds.\n",min+120*n);
        }else{
            cout << "Jimmy should plan this vacation a different day." << endl;
        }
        cout<<endl;
    }
}



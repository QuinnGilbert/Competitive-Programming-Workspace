#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
long long mod;
long long f[1000005][2][2];
int main()
{
     int i;
    //  freopen("express.in","r",stdin);
    //  freopen("express.out","w",stdout);
    //  scanf("%d%lld",&n,&mod);
    cin >> n >> mod;
     f[3][0][0]=(long long)2;
     f[3][1][0]=(long long)1;
     f[3][1][1]=(long long)1;
     f[3][0][1]=(long long)1;
     for(i=4;i<=n;i++)
     {
         f[i][0][0]=(f[i-1][0][0]+f[i-1][0][1])%mod;
         f[i][0][1]=f[i-1][0][0]%mod;
 
         f[i][1][0]=(f[i-1][1][1]+f[i-1][1][0])%mod;
         f[i][1][1]=f[i-1][1][0];        
     }
     if(n<=3) printf("0");
     else printf("%lld",(f[n][1][0]+f[n][0][0]+f[n][0][1]-(long long)n-(long long)1+mod*(n/mod+1))%mod);
     for(int i=0;i<=n;i++){
         cout << f[i][0][0] << " ";
     }
     cout << endl;
     for(int i=0;i<=n;i++){
         cout << f[i][0][1] << " ";
     }
     cout << endl;
     for(int i=0;i<=n;i++){
         cout << f[i][1][0] << " ";
     }
     cout << endl;
     for(int i=0;i<=n;i++){
         cout << f[i][1][1] << " ";
     }
     cout << endl;
     cout << (f[n][1][0]+f[n][0][0]+f[n][0][1]-(long long)n-(long long)1+mod*(n/mod+1))%mod << endl;
     cout << f[n][1][0] << " " << f[n][0][0] << " " << f[n][0][1];
     return 0;
 }
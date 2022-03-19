#include <iostream>
#include <vector>

using namespace std;

// 2*2*3
// 3
// 1 + 2 

int sum_of_divisors(int n){
  int prod=1;
  for(int k=2;k*k<=n;++k){
    int p=1;
    while(n%k==0){
      p=p*k+1;
      n/=k;
    }
    prod*=p;
  }
  if(n>1)
    prod*=1+n;
  return prod;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //4179871
    //3906313

    //make a list of abundant numbers
    vector<int> abundant;
    int max = 28123;
    max=100;
    for(int x=1;x<=max;x++){
        cout<<sum_of_divisors(x)<<endl;
        int sum=1;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                sum+=i;
                if(i*i!=x)sum+=x/i;
            }
        }
        if(sum>x){
            // cout<<x<<" "<<sum<<"\n";
            abundant.push_back(x);
        }
        // cout<<x<<" "<<sum<<"\n";
    }
    // for(int i=2;i<=28123;++i)
    //     if(sum_of_divisors(i)>2*i)
    //         abundant.push_back(i);

    vector<bool> b(28123*2+1);
    for(int i=0;i<abundant.size();i++){
        for(int j=0;j<abundant.size();j++){
            b[abundant[i]+abundant[j]]=true;
        }
    }
    int sum=0;
    for(int i=0;i<=28123;i++){
        if(!b[i]){
            // cout<<i<<"\n";
            sum+=i;
        }
    }
    cout<<sum<<"\n";
}

/*

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
0 1 1 3 1 6 1 7 4  8  1 16  1 10

1: 1
2: 3
3: 4

2*2*3

1+2+3+4+6
1+(2)+(3)

1
2
3
2*2
2*3
//2
//2*3
//2*2*3

1+2+3+4+6+12 = 16+12 = 28

every multiple of an abundant number is an abundant number


*/


// #include <iostream>
// #include <vector>

// using namespace std;

// int sum_of_divisors(int n){
//   int prod=1;
//   for(int k=2;k*k<=n;++k){
//     int p=1;
//     while(n%k==0){
//       p=p*k+1;
//       n/=k;
//     }
//     prod*=p;
//   }
//   if(n>1)
//     prod*=1+n;
//   return prod;
// }

// int main(){
//   vector<int> abundant;
  
//   for(int i=2;i<=28123;++i)
//     if(sum_of_divisors(i)>2*i)
//       abundant.push_back(i);
  
//   bool sum_of_abundants[28123*2+1]={false};
  
//   for(int i=0;i<abundant.size();++i)
//     for(int j=0;j<=i;++j)
//       sum_of_abundants[abundant[i]+abundant[j]]=true;
  
//   int sum=0;
  
//   for(int i=1;i<30000;++i)
//     if(!sum_of_abundants[i])
//       sum+=i;
  
//   cout << sum << endl;
// }
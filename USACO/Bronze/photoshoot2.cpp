#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;cin>>n;
    vector<int> a(n);
    vector<int> place(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    for(int i=0;i<n;i++){
        int b;cin>>b;
        place[b-1]=i;
    }
    


}

/*
We must move all elements that are to the right of their place orginally
Moving those elements might make us have to move other elements
The elements that are moved will be all the elements between the index and the correct place?
^ Unless an element is shifted out of that range first

1 4 3 5 2
1 2 4 3 5
1 2 3 4 5

1 4 3 5 2

1 4 3 5 2
4 3 5 2 +1
4 3 5 +1
4 5
5


*/
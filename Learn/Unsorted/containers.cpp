#include <bits/stdc++.h>

using namespace std;

int main(){
    int c = 0;
    while(true){
        c++;
        string s;
        cin >> s;
        if(s=="end")break;
        vector<char> a;
        a.push_back(s[0]);
        for(int i=1;i<s.length();i++){
            int mini = -1;
            for(int j=0;j<a.size();j++){
                if(s[i]<=a[j]){
                    if(mini==-1)mini = j;
                    else if(a[j]<a[mini]){
                        mini = j;
                    }
                }
            }

            if(mini==-1){
                a.push_back(s[i]);
                // cout << s[i] << endl;
            }else {
                // cout << a[mini] << " " << s[i] << endl;
                a[mini] = s[i];
            }
        }
        cout << "Case "<<c<<": "<< a.size() << endl;
    }
}
//if all chars Z come after Y 1 less stack is needed
//if all chars z come after Y and Y come after X 2 less stacks are needed
//if all chars Z come after X but not Y only 1 less stack is needed: XZY

//if there are 2 separate stacks that come completely after a value only 1 can be used 

//11 15 21 17 10 4

//333222211111

//ACMICPC

//1 3 13 9 3 9 3

//DDCFFCEDA 

//4 4 3 6 6 3 5 4 1
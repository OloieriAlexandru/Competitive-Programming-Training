#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    int c1 = 0, c2 = 0;
    cin>>n;
    cin>>s;
    for (auto x:s){
        if (x == 'A'){
            ++c1;
        } else{
            ++c2;
        }
    }
    if (c1 > c2){
        cout<<"Anton\n";
    } else {
        if (c1 == c2){
            cout<<"Friendship\n";
        } else {
            cout<<"Danik\n";
        }
    }
    return 0;
}

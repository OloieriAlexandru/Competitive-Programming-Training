#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c1, c2;
    cin>>c1>>c2;
    if (c1 == 9 && c2 == 1){
        cout<<"9 10\n";
        return 0;
    }
    if (abs(c1-c2) > 1){
        cout<<"-1\n";
        return 0;
    }
    if (c1 > c2){
        cout<<"-1\n";
        return 0;
    }
    if (c1 == c2){
        cout<<c1<<"0 "<<c2<<"1\n";
        return 0;
    }
    cout<<c1<<"9 "<<c2<<"0\n";
    return 0;
}

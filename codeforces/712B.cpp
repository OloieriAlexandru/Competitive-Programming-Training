#include <bits/stdc++.h>
using namespace std;
string s;
int ans, x, y;
int main()
{
    cin>>s;
    if (s.size()%2){
        cout<<"-1\n";
        return 0;
    }
    for (auto ch:s){
        switch(ch){
            case 'L': --x; break;
            case 'R': ++x; break;
            case 'U': ++y; break;
            case 'D': --y; break;
        }
    }
    int ans = abs(x)+abs(y);
    cout<<ans/2<<'\n';
    return 0;
}

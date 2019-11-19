#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>n;
        cin>>s>>t;
        int dif = 0, p1, p2;
        for (int i=0;i<s.size();++i){
            if (s[i]!=t[i]){
                if (!dif) p1 = i; else p2 = i;
                ++dif;
            }
        }
        if (dif > 2){
            cout<<"No\n";
            continue;
        }
        if (!dif){
            cout<<"Yes\n";
            continue;
        }
        swap(s[p1],t[p2]);
        dif = 0;
        for (int i=0;i<n;++i){
            if (s[i]!=t[i]){
                ++dif;
                break;
            }
        }
        if (dif){
            cout<<"No\n";
        } else {
            cout<<"Yes\n";
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define lld long long
using namespace std;
int t, x, ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>x;
        if (x <= 4)
        {
            cout<<4-x<<'\n';
            continue;
        }
        if (x % 2)
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }
    return 0;
}

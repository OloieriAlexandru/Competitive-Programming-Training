#include <bits/stdc++.h>
using namespace std;
int t;
long long x, y;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if (x == y + 1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}

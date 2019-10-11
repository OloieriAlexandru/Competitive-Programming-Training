#include <bits/stdc++.h>
#define lld long long
#define nmax
#define mod
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;

int main()
{
    int t, n, x;

    cin>>n;
    bool ok = false;
    for (int i=1; i<=n; ++i)
    {
        cin>>x;
        if (x)
            ok = true;
    }
    if (ok)
        cout<<"HARD\n";
    else
        cout<<"EASY\n";
    return 0;
}

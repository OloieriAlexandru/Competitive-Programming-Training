#include <bits/stdc++.h>
#define nmax 405
#define lld long long
using namespace std;
int t, n, a[nmax];
lld arr;
int main()
{
    cin>>t;
    for (int q=1; q<=t; ++q)
    {
        cin>>n;
        for (int i=1; i<=4*n; ++i)
            cin>>a[i];
        sort(a+1,a+4*n+1);
        bool first = true, ok= true;
        int st = 1, dr = 4*n;
        while (st < dr && ok)
        {
            if (a[st] != a[st+1])
            {
                ok = false;
                continue;
            }
            if (a[dr] != a[dr-1])
            {
                ok = false;
                continue;
            }
            if (first)
                first = !first, arr = a[st] * a[dr];
            else
            {
                if (a[st] * a[dr] != arr)
                {
                    ok = false;
                    continue;
                }
            }
            st += 2;
            dr -= 2;
        }
        if (ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

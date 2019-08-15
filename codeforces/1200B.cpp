#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, act, x, minn;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        if (n)
            cin>>act;
        bool ok = true;
        for (int i=1; i<n; ++i)
        {
            cin>>x;
            if (!ok) continue;
            minn = max(0, x - k);
            if (act < minn)
            {
                if (act + m < minn)
                {
                    ok = false;
                    continue;
                }
                m -= (minn - act);
                act = x;
            }
            else
                m += (act - minn), act = x;
        }
        if (ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

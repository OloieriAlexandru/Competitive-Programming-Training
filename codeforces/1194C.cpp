#include <bits/stdc++.h>
#define nmax 26
using namespace std;
string a, b, c;
int t, fv[nmax];
int main()
{
    cin>>t;
    while(t--)
    {
        bool ok = true;
        cin>>a>>b>>c;
        memset(fv,0,sizeof(fv));
        for (auto x:c)
            ++fv[x-'a'];
        int i = 0, j = 0;
        while (i < a.size() && j < b.size() && ok)
        {
            if (a[i] == b[j])
            {
                ++i, ++j;
                continue;
            }
            if (fv[b[j]-'a'] == 0)
            {
                ok = false;
                continue;
            }
            --fv[b[j]-'a'];
            ++j;
        }
        if (i < a.size())
            ok = false;
        else
        {
            while (j < b.size())
            {
                if (fv[b[j]-'a'] == 0)
                {
                    ok = false;
                    break;
                }
                --fv[b[j]-'a'];
                ++j;
            }
        }
        if (!ok)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}

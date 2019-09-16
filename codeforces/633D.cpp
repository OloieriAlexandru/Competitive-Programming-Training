#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int n, a[nmax], ans, x, y, z, ln;
unordered_map<int,int>mp;
int elements[nmax];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        ++mp[a[i]];
    }
    if (mp.count(0))
        ans = max(2,mp[0]);
    else
        ans = 2;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
        {
            if (i == j) continue;
            if (a[i] == 0 && a[j] == 0) continue;
            ln = 2;
            x = a[i],y = a[j];
            elements[1] = x,elements[2] = y;
            --mp[x], --mp[y];
            while (1)
            {
                z = x + y;
                if (!mp[z]) break;
                elements[++ln] = z;
                --mp[z];
                x = y,y = z;
            }
            for (int k=1;k<=ln;++k)
                ++mp[elements[k]];
            ans = max(ln, ans);
        }
    }
    cout<<ans<<'\n';
    return 0;
}

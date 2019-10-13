#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n, m, m1, s1, m2, s2;
        int ans = 0;
        scanf("%d %d",&n,&m);
        for (int i=1;i<=n;++i)
        {
            scanf("%d:%d %d:%d",&m1,&s1,&m2,&s2);
            if (m1 == m2)
                ans += s2 - s1;
            else
                ans += s2 + (60 - s1) + (m2-m1-1)*60;
        }
        ans /= 60;
        if (ans >= m)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

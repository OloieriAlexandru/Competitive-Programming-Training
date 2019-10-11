#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int t, ans, n, h, a[nmax], hact;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&h,&n);
        unordered_set<int>st;
        for (int i=1; i<=n; ++i)
        {
            scanf("%d",&a[i]);
            st.insert(a[i]);
        }
        ans = 0;
        bool ok= false;
        for (int i=1; i<=n; ++i)
        {
            hact = a[i];
            if (hact <= 1) break;
            if (i == 1 || ok)
            {
                if (st.count(hact - 1))
                {
                    if (st.count(hact - 2))
                    {
                        ok = true;
                        ++i;
                    }
                    else
                    {
                        ok = false;
                        ++i;
                        if (hact > 2) ++ans;
                    }
                }
                else
                    ok = false;
            }
            else
            {
                if (st.count(hact - 1))
                {
                    ok = true;
                    continue;
                }
                ok = false;
                if (hact >= 2)
                    ++ans;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

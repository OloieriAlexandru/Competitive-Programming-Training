#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int t, n, m, nrm, mrm, x, ans;
vector<int>a,b;
int logic(vector<int>&a,vector<int>&b)
{
    int act2 = 0, ret = 0;
    for (int i=0; i<a.size(); ++i)
    {
        while (act2 < b.size() && b[act2] < a[i])
        {
            ++ret;
            while (act2 < b.size() && b[act2] <= a[i])
                ++act2;
        }
    }
    if (act2 != b.size()) ++ret;
    return ret;
}
int main()
{
    freopen("portofel.in","r",stdin);
    freopen("portofel.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        a.clear();
        b.clear();
        a.push_back(0);
        for (int i=1; i<=n; ++i)
        {
            scanf("%d",&x);
            if (!a.size())
                a.push_back(x);
            else if (a.back() != x)
                a.push_back(x);
        }
        for (int i=1; i<=m; ++i)
        {
            scanf("%d",&x);
            if (!b.size())
                b.push_back(x);
            else if (b.back() != x)
                b.push_back(x);
        }
        if (b[0] >= a.back() || a[0] >= b.back())
        {
            printf("1\n");
            continue;
        }
        int v1 = logic(a, b);
        printf("%d\n", v1);
    }
    return 0;
}

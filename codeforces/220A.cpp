#include <bits/stdc++.h>
using namespace std;
vector<int>a,b;
int g,n,p1,p2,x;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        a.push_back(x);
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    if (a == b)
    {
        cout<<"YES\n";
        return 0;
    }
    for (int i=0;i<n;++i)
    {
        if (a[i]!=b[i])
        {
            ++g;
            if (g == 3)
            {
                cout<<"NO\n";
                return 0;
            }
            if (g == 1) p1 = i;
            else p2 = i;
        }
    }
    if (g == 1)
    {
        cout<<"NO\n";
        return 0;
    }
    swap(a[p1],a[p2]);
    if (a == b)
    {
        cout<<"YES\n";
        return 0;
    }
    cout<<"NO\n";
    return 0;
}

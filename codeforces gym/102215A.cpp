#include <bits/stdc++.h>
#define nmax 500005
using namespace std;
int fv[nmax], a[nmax];
int n, act, r, ans;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        fv[i] = 1;
    }
    act = r = 1;
    while (act <= n)
    {
        while (r <= n)
        {
            if (a[r] > 0)
            {
                if (fv[a[r]]<=0) break;
            }
            else
            {
                --fv[abs(a[r])];
            }
            ++r;
            ++ans;
        }
        cout<<ans<<' ';
        --ans;
        if (a[act] < 0)
            ++fv[abs(a[act])];
        ++act;
    }
    cout<<'\n';
    return 0;
}

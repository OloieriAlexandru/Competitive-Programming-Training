#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
int cif[nmax], n, x, y, ans;
int main()
{
    cin>>n>>x>>y;
    for (int i=1; i<=n; ++i)
    {
        char ch;
        cin>>ch;
        if (ch == '1')
            cif[n-i+1] = 1;
    }

    if (!cif[y+1]) ++ans;
    for (int i=y; i>=1; --i)
        if (cif[i]) ++ans;
    for (int i=y+2; i<=x; ++i)
        if (cif[i]) ++ans;
    cout<<ans<<'\n';
    return 0;
}

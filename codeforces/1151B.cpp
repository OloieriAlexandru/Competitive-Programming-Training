#include <bits/stdc++.h>
#define nmax 505
using namespace std;
int n, m, pdif[nmax], act, xorr, init, ans[nmax];
void printAns()
{
    cout<<"TAK\n";
    for (int i=1; i<=n; ++i)
        cout<<ans[i]<<' ';
    cout<<'\n';
}
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
    {
        cin>>act;
        init = act;
        xorr ^= act;
        ans[i] = 1;
        for (int j=2; j<=m; ++j)
        {
            cin>>act;
            if (act != init) pdif[i] = j;
        }
    }
    if (xorr)
        printAns();
    else
    {
        bool ok = false;
        for (int i=1;i<=n;++i)
        {
            if (!pdif[i]) continue;
            ans[i] = pdif[i];
            ok = true;
            break;
        }
        if (ok)
            printAns();
        else
            cout<<"NIE\n";
    }
    return 0;
}

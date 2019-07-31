#include <bits/stdc++.h>
using namespace std;
int cif;
char lit;
int a[11], b[11], c[11];
int ans = 2;
void read()
{
    cin>>cif>>lit;
    switch(lit)
    {
        case 'm': ++a[cif]; break;
        case 'p': ++b[cif]; break;
        case 's': ++c[cif]; break;
        default: break;
    }
}
void doo(int v[])
{
    for (int i=1;i<10;++i)
    {
        if (v[i] == 3) ans = 0;
        if (v[i] == 2) ans = min(ans, 1);
        if (v[i-1] && v[i] && v[i+1]) ans = 0;
        if (v[i-1] && v[i] || v[i-1] && v[i+1] || v[i] && v[i+1]) ans = min(ans, 1);
    }
}
int main()
{
    read();
    read();
    read();
    doo(a);
    doo(b);
    doo(c);
    cout<<ans<<'\n';
    return 0;
}

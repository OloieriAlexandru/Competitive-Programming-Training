#include <bits/stdc++.h>
#define nmax 500005
using namespace std;
char ch;
int a[nmax], n, k;
void solve2()
{
    int v1 = 0, v2 = 0;
    int f1 = 0, f2 = 1;
    for (int i=1;i<=n;++i)
    {
        if (a[i] != f1) ++v1;
        if (a[i] != f2) ++v2;
        ++f1, ++f2;
        f1 %= 2, f2 %= 2;
    }
    if (v1 < v2)
    {
        cout<<v1<<'\n';
        for (int i=1;i<=n;++i)
            if (i%2)
                cout<<'A';
            else
                cout<<'B';
    }
    else
    {
        cout<<v2<<'\n';
        for (int i=1;i<=n;++i)
            if (!(i%2))
                cout<<'A';
            else
                cout<<'B';
    }
    cout<<'\n';
}
int dif(int a, int b)
{
    ++a;
    a %= k;
    if (a == b)
        ++a, a%=k;
    return a;
}
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>ch;
        ch -= 'A';
        a[i] = ch;
    }
    if (k == 2)
    {
        solve2();
        return 0;
    }
    int ans = 0;
    for (int i=1;i<n;++i)
    {
        if (a[i] == a[i+1])
        {
            // schimb a[i+1]
            ++ans;
            a[i+1] = dif(a[i+1], a[i+2]);
        }
    }
    cout<<ans<<'\n';
    for (int i=1;i<=n;++i)
        cout<<(char)(a[i]+'A');
    cout<<'\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int nrd(int x)
{
    int ans = 1;
    for (int i=2;i*i<=x;++i)
        if (x%i == 0)
            ++ans;
    return ans;
}
int main()
{
    int n, m, k;
    cin>>m>>n>>k;
    for (int i=k+1;i<=10000;++i)
    {
        int nr1 = i;
        int nr2 = i - k;
        int nrd1 = nrd(nr1);
        int nrd2 = nrd(nr2);
        if (nrd1 == n && nrd2 == m)
        {
            cout<<i<<'\n';
            return 0;
        }
    }
    cout<<0<<'\n';
    return 0;
}
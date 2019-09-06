#include <bits/stdc++.h>
#define nmax 200111
using namespace std;
int aint[3][nmax];
int a[nmax], n, nn, act;
int nra, nrb, nrc, ans = 999999999;
char ch;
void update(int arb, int poz)
{
    for (; poz<=nn; poz+=(poz&(-poz)))
        ++aint[arb][poz];
}
int query(int arb, int poz)
{
    int ret = 0;
    for (; poz>=1; poz-=(poz&(-poz)))
        ret+=aint[arb][poz];
    return ret;
}
int queryy(int arb, int x, int y)
{
    return query(arb, y) - query(arb, x-1);
}
int main()
{
    cin>>n;
    nn = 2 * n;
    for (int i=1; i<=n; ++i)
    {
        cin>>ch;
        if (ch == 'A')
        {
            a[i] = 0, ++nra;
            update(0,i);
            update(0,i+n);
        }
        else if (ch == 'B')
        {
            a[i] = 1, ++nrb;
            update(1,i);
            update(1,i+n);
        }
        else if (ch == 'C')
        {
            a[i] = 2, ++nrc;
            update(2,i);
            update(2,i+n);
        }
    }
    for (int i=1; i<=n; ++i)
    {
        // a b c
        act = queryy(0,i,i+nra-1) + queryy(1,i+nra,i+nra+nrb-1) + queryy(2,i+nra+nrb,i+nra+nrb+nrc-1);
        ans = min(ans, n-act);
        // a c b
        act = queryy(0,i,i+nra-1) + queryy(2,i+nra,i+nra+nrc-1) + queryy(1,i+nra+nrc,i+nra+nrb+nrc-1);
        ans = min(ans, n-act);
        // b a c
        act = queryy(1,i,i+nrb-1) + queryy(0,i+nrb,i+nra+nrb-1) + queryy(2,i+nra+nrb,i+nra+nrb+nrc-1);
        ans = min(ans, n-act);
        // b c a
        act = queryy(1,i,i+nrb-1) + queryy(2,i+nrb,i+nrc+nrb-1) + queryy(0,i+nrc+nrb,i+nra+nrb+nrc-1);
        ans = min(ans, n-act);
        // c a b
        act = queryy(2,i,i+nrc-1) + queryy(0,i+nrc,i+nrc+nra-1) + queryy(1,i+nra+nrc,i+nra+nrb+nrc-1);
        ans = min(ans, n-act);
        // c b a
        act = queryy(2,i,i+nrc-1) + queryy(1,i+nrc,i+nrc+nrb-1) + queryy(0,i+nrc+nrb,i+nra+nrb+nrc-1);
        ans = min(ans, n-act);
    }
    cout<<ans<<'\n';
    return 0;
}

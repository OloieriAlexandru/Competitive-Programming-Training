#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld numitor, numarator, gc, add, dif;
int t, vp, pp, pi;
string s;
int main()
{
    int t;
    cin>>t;
    for (int q=1; q<=t; ++q)
    {
        cin>>s;
        pi = vp = pp=  -1;
        numitor = 0, numarator = 0;
        for (int i=0; i<s.size(); ++i)
            if (s[i] == '.')
                vp = i;
            else if (s[i] == '(')
                pp = i;
            else if (s[i] == ')')
                pi = i;
        if (pp == -1)
            pp = s.size(), pi = s.size();
        int nrz = pp - vp - 1;
        int nrn = pi - pp - 1;
        numitor = numarator = 0;
        for (int i=1; i<=nrn; ++i)
            numitor = numitor * 10 + 9;
        if (!numitor) numitor = 1;
        for (int i=1; i<=nrz; ++i)
            numitor = numitor * 10;
        add = dif = 0;
        for (int i=0; i<s.size(); ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
                add = add * 10 + s[i] - '0';
            if (s[i] >= '0' && s[i] <= '9' && !(i > pp && i < pi))
                dif = dif * 10 + s[i] - '0';
        }
        if (nrn == -1)
            numarator = add;
        else
            numarator = add - dif;
        if (vp == -1)
        {
            printf("Case #%d: %lld/1\n", q, numarator);
            continue;
        }
        gc = __gcd(numitor, numarator);
        numarator /= gc;
        numitor /= gc;
        printf("Case #%d: %lld/%lld\n", q, numarator, numitor);
    }
    return 0;
}

#include <bits/stdc++.h>
#define lld long long
#define nmax 2005
using namespace std;
string s;
int n, st, dr, cnt;
lld cntl[nmax], cntr[nmax], ans;
lld sumr[nmax];
int main()
{
    cin>>s;
    n = s.size();
    for (int i=0; i<n; ++i)
    {
        st = i, dr = i; cnt = 1;
        while (st >= 0 && dr < n && s[st] == s[dr])
        {
            cntl[st] += cnt, cntr[dr] += cnt;
            --st, ++dr;
        }
        st = i, dr = i+1, cnt = 1;
        while (st >=0 && dr < n && s[st] == s[dr])
        {
            cntl[st] += cnt, cntr[dr] += cnt;
            --st, ++dr;
        }
    }
    for (int i=n-1;i>=0;--i)
        sumr[i] = sumr[i+1] + cntl[i];
    for (int i=0; i<n-1; ++i)
        ans += cntr[i] * sumr[i+1];
    cout<<ans<<'\n';
    return 0;
}

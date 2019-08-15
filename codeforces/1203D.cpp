#include <bits/stdc++.h>
#define nmax 205
using namespace std;
char s[nmax], t[nmax];
int poz1[nmax], poz2[nmax], n1, n2, j;
int main()
{
    cin>>(s+1);
    cin>>(t+1);
    n1 = strlen(s+1), n2 = strlen(t+1);
    for (int i=1, j = 1; i<=n2;++j)
        if (s[j] == t[i])
            poz1[i] = j, ++i;
    for (int i=n2, j = n1; i>=1;--j)
        if (s[j] == t[i])
            poz2[i] = j, --i;
    int ans = n1-poz1[n2];
    ans = max(ans, poz2[1]-1);
    for (int i=1; i<n2; ++i)
        ans = max(ans, abs(poz2[i+1]-poz1[i]-1)), ans = max(ans, abs(poz2[i+1]-poz2[i]-1)), ans = max(ans, abs(poz1[i+1]-poz1[i]-1));
    cout<<ans<<'\n';
    return 0;
}

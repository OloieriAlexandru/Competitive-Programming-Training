#include <bits/stdc++.h>
#define nmax 7
using namespace std;
int nec[nmax], s, n, a, b, ans;
bool used[nmax];
int main()
{
    cin>>n;
    cin>>a;
    cin>>b;
    nec[1] = a;
    nec[2] = a;
    nec[3] = a;
    nec[4] = a;
    nec[5] = b;
    nec[6] = b;
    sort(nec+1,nec+7);
    int anss;
    for (int i=6;i>=1;--i)
    {
        if (used[i]) continue;
        s = nec[i];
        ++ans;
        used[i] = true;
        for (int j=1;j<i;++j)
        {
            if (used[j]) continue;
            if (s + nec[j] > n) continue;
            used[j] = true;
            s += nec[j];
        }
    }
    anss = ans;
    ans = 0;
    memset(used, 0, sizeof(used));
    for (int i=6;i>=1;--i)
    {
        if (used[i]) continue;
        s = nec[i];
        ++ans;
        used[i] = true;
        for (int j=i-1;j>=1;--j)
        {
            if (used[j]) continue;
            if (s + nec[j] > n) continue;
            used[j] = true;
            s += nec[j];
        }
    }
    anss = min(ans, anss);
    cout<<anss<<'\n';
    return 0;
}

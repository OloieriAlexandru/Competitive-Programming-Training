#include <bits/stdc++.h>
#define nmax 100005
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lld long long
using namespace std;
lld n, q, a[nmax], s[nmax], x, y, sum;
int main()
{
    cin>>n>>q;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        s[i] = s[i-1] + a[i];
    }
    for (int i=1;i<=q;++i)
    {
        cin>>x>>y;
        sum = s[y] - s[x-1];
        if (sum % 2)
            printf("Nao\n");
        else
            printf("Sim\n");
    }
    return 0;
}

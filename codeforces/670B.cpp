#include <bits/stdc++.h>
#define lld long long
#define nmax 100005
using namespace std;
int n, id[nmax];
lld cnt, sum;
int main()
{
    cin>>n>>cnt;
    for (int i=1;i<=n;++i)
        cin>>id[i];
    for (int i=1;i<=n;++i)
    {
        if (cnt - i > 0)
            cnt -= i;
        else
        {
            cout<<id[cnt]<<'\n';
            return 0;
        }
    }
    return 0;
}

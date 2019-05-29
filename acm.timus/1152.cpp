#include <bits/stdc++.h>
#define pii pair<int,int>
#define nmax 20
#define inf 999999999
#define mp make_pair
using namespace std;
int n, c[nmax], dp[1<<nmax];
queue<pair<int,pair<int,int>>>q;
pair<int,pair<int,int>>act;
int add, sum;
int msk;
int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        cin>>c[i];
        sum+=c[i];
    }
    for (int i=0; i<(1<<n); ++i)
        dp[i] = inf;
    q.push(mp(0,mp(0,sum)));
    dp[0] = 0;
    while(!q.empty())
    {
        act = q.front();
        q.pop();
        for (int i=0; i<n; ++i)
            if (!((1<<i)&act.first))
            {
                add = act.second.second - c[i];
                msk = act.first ^ (1<<i);
                if (i == (n-1))
                {
                    if (!((1<<(i-1))&act.first))
                        add-=c[i-1], msk^=(1<<(i-1));
                    if (!((1<<0)&act.first))
                        add-=c[0], msk^=(1<<0);
                }
                else if (i == 0)
                {
                    if (!((1<<(i+1))&act.first))
                        add-=c[i+1], msk^=(1<<(i+1));
                    if (!((1<<(n-1))&act.first))
                        add-=c[n-1], msk^=(1<<(n-1));
                }
                else
                {
                    if (!((1<<(i-1))&act.first))
                        add-=c[i-1], msk^=(1<<(i-1));
                    if (!((1<<(i+1))&act.first))
                        add-=c[i+1], msk^=(1<<(i+1));
                }
                if (dp[msk]>act.second.first + add)
                {
                    dp[msk] = act.second.first + add;
                    q.push(mp(msk,mp(act.second.first + add, add)));
                }
            }
    }
    cout<<dp[(1<<n)-1]<<'\n';
    return 0;
}
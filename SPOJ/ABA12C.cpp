#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#define LMAX 105
#define NMAX 105
#define NMAX2 1005
#define mp make_pair
#define INF 999999999
using namespace std;

vector<pair<int,int>>v;

int dp[NMAX][NMAX2];
int n, k;
int x;
int a[LMAX];

int main()
{
    int t;
    cin>>t;
    for (int q = 1; q<=t; ++q)
    {
        cin>>n>>k;
        for (int i =1 ; i<=k; ++i)
        {
            cin>>x;
            if (x==-1)
            {
                continue;
            }
            v.push_back(mp(i, x));
        }
        for (int i=0;i<=n;++i)
        {
            for (int j=1;j<=k;++j)
            {
                dp[i][j] = INF;
            }
        }
        for (int i=1;i<=n;++i)
        {
            for (int j=1;j<=k;++j)
            {
                for (auto w=0u;w<v.size();++w)
                {
                    if (j-v[w].first<0)
                    {
                        continue;
                    }
                    dp[i][j] = min(dp[i][j], dp[i-1][j-v[w].first] + v[w].second);
                }
            }
        }
        int m = INF;
        for (int i=1;i<=n;++i)
        {
            if (dp[i][k]!=INF)
            {
                m = min(m, dp[i][k]);
            }
        }
        if (m==INF)
        {
            cout<<-1<<'\n';
        }
        else
        {
            cout<<m<<'\n';
        }
        v.clear();
    }
    return 0;
}

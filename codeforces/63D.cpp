#include <bits/stdc++.h>
#define nmax 105
#define pb push_back
#define mp make_pair
using namespace std;
int a, b, c, d, n, s, l, h;
int v[nmax];
char mat[nmax][nmax];
vector<pair<int,int>>ans;
int main()
{
    cin>>a>>b>>c>>d>>n;
    for (int i=1; i<=n; ++i)
        cin>>v[i], s+=v[i];
    if (s > a*b + c*d)
    {
        cout<<"NO\n";
        return 0;
    }
    l = a + c;
    h = max(b, d);
    for (int i=1; i<=h; ++i)
        for (int j=1; j<=l; ++j)
            mat[i][j] = '.';
    if (b == d)
    {
        for (int j=1; j<=l;)
        {
            for (int i=1; i<=h; ++i)
                ans.pb(mp(i,j));
            ++j;
            if (j > l) break;
            for (int i=h; i>=1; --i)
                ans.pb(mp(i,j));
            ++j;
        }
    }
    else
    {
        if (b > d)
        {
            if (a % 2)
            {
                for (int j=a; j>=1;)
                {
                    for (int i=b; i>=d+1;--i)
                        ans.pb(mp(i,j));
                    --j;
                    if (j == 0) break;
                    for (int i=d+1;i<=b;++i)
                        ans.pb(mp(i,j));
                    --j;
                }
            }
            else
            {
                for (int j=a;j>=1;)
                {
                    for (int i=d+1;i<=b;++i)
                        ans.pb(mp(i,j));
                    --j;
                    if (j == 0) break;
                    for (int i=b;i>=d+1;--i)
                        ans.pb(mp(i,j));
                    --j;
                }
            }
            for (int j=1;j<=l;)
            {
                for (int i=d;i>=1;--i)
                    ans.pb(mp(i,j));
                ++j;
                if (j > l) break;
                for (int i=1;i<=d;++i)
                    ans.pb(mp(i,j));
                ++j;
            }
        }
        else
        {
            if (c % 2)
            {
                for (int j=a+1;j<=l;)
                {
                    for (int i=d;i>=b+1;--i)
                        ans.pb(mp(i,j));
                    ++j;
                    if (j > l) break;
                    for (int i=b+1;i<=d;++i)
                        ans.pb(mp(i,j));
                    ++j;
                }
            }
            else
            {
                for (int j=a+1;j<=l;)
                {
                    for (int i=b+1;i<=d;++i)
                        ans.pb(mp(i,j));
                    ++j;
                    if (j > l) break;
                    for (int i=d;i>=b+1;--i)
                        ans.pb(mp(i,j));
                    ++j;
                }
            }
            for (int j=l;j>=1;)
            {
                for (int i=b;i>=1;--i)
                    ans.pb(mp(i,j));
                --j;
                if (j == 0) break;
                for (int i=1;i<=b;++i)
                    ans.pb(mp(i,j));
                --j;
            }
        }
    }
    char act = 'a';
    int actt = 1, cnt = 0;
    for (int i=0;i<ans.size();++i)
    {
        if (cnt == v[actt])
            ++act, ++actt, cnt = 0;
        ++cnt;
        mat[ans[i].first][ans[i].second] = act;
    }
    cout<<"YES\n";
    for (int i=1; i<=h; ++i)
    {
        for (int j=1; j<=l; ++j)
            cout<<mat[i][j];
        cout<<'\n';
    }
    return 0;
}

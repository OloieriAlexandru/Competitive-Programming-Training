#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <cstring>
#define mp make_pair
#define pb push_back
#define INF
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define lld long long
#define INF 999999999999999999999

using namespace std;
ifstream fin("in");
ofstream fout("out");

vector<int>ans;

int a[101][501];
lld dp[101][501];
lld s[101][501];
int v[101][501];
int n, m;

int main()
{
    cin>>n>>m;
    for (int i =1 ; i<=n; ++i)
    {
        for (int j = 1; j<=m; ++j)
        {
            cin>>a[i][j];
            s[i][j] = s[i][j-1] + a[i][j];
        }
    }
    for (int i= 1; i<=m; ++i)
    {
        dp[1][i] = a[1][i];
        v[1][i] = i;
    }
    for (int i=2; i<=n; ++i)
    {
        for (int j=1; j<=m; ++j)
        {
            dp[i][j] = INF;
            for (int k=1; k<=m; ++k)
            {
                lld act = s[i][max(j,k)] - s[i][min(j,k)-1] + dp[i-1][k];
                if (act<dp[i][j])
                {
                    dp[i][j] = act;
                    v[i][j] = k;
                }
            }
        }
    }
    lld mi = INF;
    int poz;
    for (int j=1; j<=m; ++j)
    {
        if (mi>dp[n][j])
        {
            poz = j;
            mi = dp[n][j];
        }
    }
    ans.push_back(poz);
    for (int i = n-1;i>=1;--i)
    {
        poz = v[i][poz];
        ans.push_back(poz);
    }
    int last = ans[ans.size()-1];
    for (int i=ans.size()-2; i>=0; --i)
    {
        int act = ans[i];
        if (act<last)
        {
            for (int j=last; j>=act; --j)
            {
                cout<<j<<' ';
            }
        }
        else
        {
            for (int j = last; j<=act; ++j)
            {
                cout<<j<<' ';
            }
        }
        last = act;
    }
    cout<<last;
    cout<<'\n';
    return 0;
}
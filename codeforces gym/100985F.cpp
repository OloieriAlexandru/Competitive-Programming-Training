#include <bits/stdc++.h>
#define nmax
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lld long long
using namespace std;
int n, m, k, rm, nk;
int maxx = -1, cnt, ans1, procint;
bool ok;
double proc;
int main()
{
    cin>>n>>m>>k;
    rm = n - m;
    for (int i=0;i<=rm;++i)
    {
        nk = k + i;
        proc = (double)nk / n * 100;
        if (proc >= 70.0 && !ok)
        {
            ok = true;
            ans1 = i;
        }
        procint = (int)proc;
        if (procint > maxx)
            maxx = procint, cnt = i;
    }
    if (ok)
        cout<<ans1<<'\n';
    else
        cout<<"-1\n";
    cout<<maxx<<'\n';
	return 0;
}

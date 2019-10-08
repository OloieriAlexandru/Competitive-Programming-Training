#include <bits/stdc++.h>
#define nmax
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lld long long
using namespace std;
int main()
{
    int maxx = -1, cnt = 0, poz;
    int n, x;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        if (x > maxx)
            maxx = x, cnt = 1, poz = i;
        else if (x == maxx)
            ++cnt;
    }
    if (cnt > 1)
        cout<<"-1\n";
    else
        cout<<poz<<'\n';
	return 0;
}

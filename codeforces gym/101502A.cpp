#include <bits/stdc++.h>
#define lld long long
#define nmax
#define mod
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
int t;
lld x, y;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>y>>x;
        lld ans = ((100LL)*y)/(100LL+x);
        cout<<ans<<'\n';
    }
	return 0;
}

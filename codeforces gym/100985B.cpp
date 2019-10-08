#include <bits/stdc++.h>
#define nmax 100005
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define lld long long
using namespace std;
int n, a[nmax], ans;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (n == 1)
        cout<<"1\n";
    else
    if (n == 2)
        cout<<"2\n";
    else
    {
        int ans = 1;
        lld p2 = 1;
        while (true)
        {
            if (p2 > n)
            {
                cout<<ans-1<<'\n';
                return 0;
            }
            ++ans, p2*=2;
        }
    }
	return 0;
}

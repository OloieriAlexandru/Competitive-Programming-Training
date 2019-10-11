#include <bits/stdc++.h>
#define lld long long
#define nmax 100
#define mod
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
char s[nmax];
int main()
{
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans = 0;
        int bed = 0, kit = 0, liv = 0;
        for (int i=1;i<=n;++i)
        {
            cin>>s;
            if (!strncmp(s, "bed", 3))
                ++bed;
            else
            if (!strncmp(s, "kitchen", 7))
                ++kit;
            else
            if (!strncmp(s, "living", 6))
                ++liv;
        }
        while (liv>=1 && kit>=1 && bed > 1)
            ++ans, --liv, --kit, bed -=2;
        cout<<ans<<'\n';
    }
	return 0;
}

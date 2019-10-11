#include <bits/stdc++.h>
#define lld long long
#define nmax
#define mod
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
using namespace std;
int ans[] =
{
    0, -1, // 0, 1
    1, // 2
    1, // 3
    1, // 4
    1, // 5
    2, // 6
    3, // 7
    2, // 8
    2, // 9
    2, // 10
    2, // 11
};
int n, t, anss;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        if (n <= 11)
            cout<<ans[n]<<'\n';
        else
        {
            anss = 0;
            while (n > 11)
            {
                n -= 11;
                anss += 2;
            }
            // n <= 11
            if (n == 1)
                ++anss;
            else
            {
                anss += ans[n];
                if (n == 7)
                    --anss; // ma duc 4 -> 6 -> 3 -> 5
            }
            cout<<anss<<'\n';
        }
    }
    return 0;
}

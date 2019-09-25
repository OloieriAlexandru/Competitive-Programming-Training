#include <bits/stdc++.h>
#define lld long long
using namespace std;
int t;
lld c, m, x, ans, minn;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>c>>m>>x;
        minn = min(c, m);
        if (c + m + x >= minn * 3)
            cout<<minn<<'\n';
        else
            cout<<(c+m+x)/3<<'\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, x, minn;
double d;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        int act = 0;
        minn = (int)(ceil(n*d));
        for (int i=1; i<=n; ++i)
        {
            cin>>x;
            if (x >= 50)
                ++act;
        }
        if (act >= minn)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}

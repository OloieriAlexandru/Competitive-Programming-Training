#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int b, p, f, h, c;
        cin>>b>>p>>f;
        cin>>h>>c;
        int ans = 0;
        for (int i=0;i<=100;++i)
        {
            for (int j=0;j<=100;++j)
            {
                if ((i+j)*2>b) continue;
                if (i > p) continue;
                if (j > f) continue;
                ans = max(ans, i*h+j*c);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

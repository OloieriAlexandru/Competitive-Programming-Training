#include <bits/stdc++.h>
using namespace std;
vector<int>toadd;
int n, nr, x, ans1, ans2, ind;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>nr;
        if (nr % 2)
        {
            ind = nr / 2 + 1;
            for (int j=1; j<=nr; ++j)
            {
                cin>>x;
                if (j < ind) ans1 += x;
                else if (j > ind) ans2 += x;
                else toadd.push_back(x);
            }
        }
        else
        {
            ind = nr / 2;
            for (int j=1; j<=nr; ++j)
            {
                cin>>x;
                if (j <= ind) ans1 += x;
                else ans2 += x;
            }
        }
    }
    sort(toadd.begin(), toadd.end(), [](int a, int b)
    {
        return a > b;
    });
    for (int i=0;i<toadd.size();++i)
        if (i % 2 == 0) ans1 += toadd[i]; else ans2 += toadd[i];
    cout<<ans1<<' '<<ans2<<'\n';
    return 0;
}

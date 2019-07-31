#include <bits/stdc++.h>
#define lld long long
using namespace std;
vector<int>divv;
vector<int>altDiv;
int n, t, x;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        divv.clear();
        altDiv.clear();
        for (int i=1; i<=n; ++i)
        {
            cin>>x;
            divv.push_back(x);
        }
        sort(divv.begin(), divv.end());
        lld pos = 1LL * divv[0] * divv[n-1];
        lld d;
        for (d=2; d*d<pos; ++d)
        {
            if (pos % d) continue;
            altDiv.push_back(d);
            altDiv.push_back(pos/d);
        }
        if (d*d == pos)
            altDiv.push_back(d);
        sort(altDiv.begin(),altDiv.end());
        if (altDiv == divv)
            cout<<pos<<'\n';
        else
            cout<<"-1\n";
    }
    return 0;
}

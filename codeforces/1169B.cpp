#include <bits/stdc++.h>
#define nmax 300005
using namespace std;
int n, m, x, y;
vector<pair<int,int>>pairs;
bool good(int a, int b)
{
    for (int i=0;i<pairs.size();++i)
        if (!(pairs[i].first == a || pairs[i].first == b || pairs[i].second == a || pairs[i].second == b)) return false;
    return true;
}
void tryy(int a)
{
    for (int i=1;i<pairs.size();++i)
    {
        if (pairs[i].first == a || pairs[i].second == a) continue;
        if (good(a,pairs[i].first))
        {
            cout<<"YES\n";
            exit(0);
        }
        if (good(a,pairs[i].second))
        {
            cout<<"YES\n";
            exit(0);
        }
        break;
    }
    if (good(a,a))
    {
        cout<<"YES\n";
        exit(0);
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;++i)
    {
        cin>>x>>y;
        pairs.push_back(make_pair(x,y));
    }
    tryy(pairs[0].first);
    tryy(pairs[0].second);
    cout<<"NO\n";
    return 0;
}

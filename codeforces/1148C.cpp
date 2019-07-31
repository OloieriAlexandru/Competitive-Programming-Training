#include <bits/stdc++.h>
#define nmax 300005
using namespace std;
int n, p[nmax], a[nmax];
vector<pair<int,int>>ans;
void swapp(int x, int y)
{
    ans.push_back(make_pair(x, y));
    swap(a[x], a[y]);
    p[a[x]] = x;
    p[a[y]] = y;
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        p[a[i]] = i;
    }
    for (int i=2; i<n; ++i)
    {
        if (p[i] == i) continue;
        int y = p[i]; // pozitia pe care se afla elementul de care am nevoie
        if (2 * abs(y-i) >= n)
        {
            swapp(y, i);
            continue;
        }
        int u, v;
        if (abs(y - n) * 2 >= n)
            u = n, v = 1;
        else
            u = 1, v = n;
        if (2 * abs(i - u) >= n)
        {
            swapp(u, y);
            swapp(u, i);
            continue;
        }
        swapp(u, y);
        swapp(u, v);
        swapp(i, v);
        continue;
    }
    if (a[1] != 1)
        ans.push_back(make_pair(1, n));
    cout<<ans.size()<<'\n';
    for (auto x:ans)
        cout<<x.first<<' '<<x.second<<'\n';
    return 0;
}

#include <bits/stdc++.h>
#define pii pair<int,int>
#define nmax 205
using namespace std;
vector<pii>v;
int ans[nmax], anss, n, nn, x, p1, p2, l, r;
vector<pii>apart;
vector<int>rm;
vector<int>uno;
int main()
{
    cin>>n;
    nn = 2 * n;
    for (int i=1; i<=nn; ++i)
    {
        cin>>x;
        v.push_back(make_pair(x, i));
    }
    sort(v.begin(), v.end());
    for (int i=0;i<v.size();++i)
    {
        int ln = 1;
        while (i+1 < v.size() && v[i].first == v[i+1].first)
            ++i, ++ln;
        if (ln == 2)
        {
            ans[v[i].second] = 1, ++l;
            ans[v[i-1].second] = 2, ++r;
            continue;
        }
        else if (ln == 1)
        {
            uno.push_back(v[i].second);
        }
        else if (ln >= 3)
        {
            ans[v[i].second] = 1, ++l;
            ans[v[i-1].second] = 2, ++r;
            for (int j=i-2;j>=0&&v[j].first == v[j+1].first;--j)
                rm.push_back(v[j].second);
        }
    }
    int start;
    for (int i=0;i<uno.size();++i)
        if (i % 2)
            ans[uno[i]] = 2, ++r;
        else
            ans[uno[i]] = 1, ++l;
    if (uno.size()%2)
        ans[rm[0]] = 2, start = 1;
    else start = 0;
    for (int i=start;i<rm.size();i+=2)
        ans[rm[i]] = 1, ans[rm[i+1]] = 2;
    anss = l * r;
    cout<<anss<<'\n';
    for (int i=1; i<=nn; ++i)
        cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}

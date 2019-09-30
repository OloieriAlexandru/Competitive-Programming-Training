#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
string name[nmax];
int n, m, x, y;
int ln, index;
vector<pair<int,int>>v;
int main()
{
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>name[i];
    cin>>m;
    for (int i=1;i<=m;++i)
    {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    index = 1;
    for (int i=v.size()-1;i>=0;--i)
    {
        if (v[i].first == index)
        {
            index = v[i].second;
            ++ln;
        }
    }
    for (int i=1;i<=ln;++i)
        cout<<"I_love_";
    cout<<name[index]<<'\n';
    return 0;
}

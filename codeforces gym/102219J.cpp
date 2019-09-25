#include <bits/stdc++.h>
#define nmax 10
using namespace std;
char ch1, ch2, ch3;
int n1, n2, dg[nmax], af;
vector<int>g[nmax];
vector<char>sol;
int main()
{
    for (int i=1;i<=5;++i)
    {
        cin>>ch1>>ch2>>ch3;
        n1 = ch1 - 'A' + 1;
        n2 = ch3 - 'A' + 1;
        if (ch2 == '<')
            swap(n1, n2);
        ++dg[n2];
        g[n1].push_back(n2);
    }
    queue<int>q;
    for (int i=1;i<=5;++i)
        if (!dg[i])
            q.push(i);
    while (!q.empty())
    {
        ++af;
        sol.push_back(q.front()-1+'A');
        auto act = q.front();
        q.pop();
        for (int i=0;i<g[act].size();++i)
        {
            --dg[g[act][i]];
            if (!dg[g[act][i]])
            {
                q.push(g[act][i]);
            }
        }
    }
    reverse(sol.begin(), sol.end());
    if (af == 5)
        for (auto x:sol)
            cout<<x;
    else
        cout<<"impossible";
    cout<<'\n';
    return 0;
}

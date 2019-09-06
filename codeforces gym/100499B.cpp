#include <bits/stdc++.h>
#define nmax 10000005
using namespace std;
int a[nmax], t, n, k, s, c1, c2, m;
int main()
{
    cin>>t;
    while(t--)
    {
        priority_queue<int, vector<int>, less<int> >ans;
        cin>>n>>k>>s>>c1>>c2>>m;
        a[1] = s;
        ans.push(s);
        for (int i=2;i<=k;++i)
        {
            a[i] = (1LL* c1 * a[i-1]+c2)%m;
            ans.push(a[i]);
        }
        for (int i=k+1;i<=n;++i)
        {
            a[i] = (1LL* c1 * a[i-1]+c2)%m;
            ans.push(a[i]);
            ans.pop();
        }
        vector<int>anss;
        while(!ans.empty())
        {
            anss.push_back(ans.top());
            ans.pop();
        }
        reverse(anss.begin(), anss.end());
        for (auto x:anss)
            cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}

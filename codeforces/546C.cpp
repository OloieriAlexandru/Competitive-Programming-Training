#include <bits/stdc++.h>
#define inf 10000000
using namespace std;
int a[11], b[11], v1, v2;
queue<int>q1,q2;
int main()
{
    int n;
    cin>>n;
    int n1, n2;
    cin>>n1;
    for (int i=1;i<=n1;++i)
        cin>>a[i];
    cin>>n2;
    for (int i=1;i<=n2;++i)
        cin>>b[i];
    int ans = 0;
    for (int i=1;i<=n1;++i)
        q1.push(a[i]);
    for (int i=1;i<=n2;++i)
        q2.push(b[i]);
    while (ans < inf && !q1.empty() && !q2.empty())
    {
        v1 = q1.front();
        q1.pop();
        v2 = q2.front();
        q2.pop();
        if (v1 > v2)
        {
            q1.push(v2);
            q1.push(v1);
        }
        else
        {
            q2.push(v1);
            q2.push(v2);
        }
        ++ans;
    }
    if (q1.empty())
        cout<<ans<<' '<<2<<'\n';
    else
    if (q2.empty())
        cout<<ans<<' '<<1<<'\n';
    else
        cout<<"-1\n";
    return 0;
}

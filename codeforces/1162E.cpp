#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    int n, x;
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int i = 0, cnt = 1;
    while (i < n && v[i] == v[i+1])
        ++i,++cnt;
    if (cnt <= n/2)
        cout<<"Alice\n";
    else
        cout<<"Bob\n";
    return 0;
}

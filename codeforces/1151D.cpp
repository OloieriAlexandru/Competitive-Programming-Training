#include <bits/stdc++.h>
#define lld long long
using namespace std;
lld add, ans;
int n, a, b;
vector<int>mul;
int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; ++i)
    {
        scanf("%d %d",&a,&b);
        mul.push_back(a-b);
        add += (1LL * b * n - a);
    }
    sort(mul.begin(), mul.end(), [](int a, int b)
    {
        return a>b;
    });
    for (int i=0;i<mul.size();++i)
        ans += 1LL * (i+1) * mul[i];
    ans += add;
    cout<<ans<<'\n';
    return 0;
}

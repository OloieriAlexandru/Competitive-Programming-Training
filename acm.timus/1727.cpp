#include <bits/stdc++.h>
using namespace std;
vector<int>ans;
int sumOfDigits(int x)
{
    int ans = 0;
    while (x) ans+=x%10,x/=10;
    return ans;
}
void solve(int n)
{
    if (n<=9)
        ans.push_back(n);
    else
    {
        ans.push_back(n);
        solve(n - sumOfDigits(n));
    }
}
int main()
{
    int n;
    cin>>n;
    solve(n);
    cout<<ans.size()<<'\n';
    for (auto x:ans)cout<<x<<' ';
    cout<<'\n';
    return 0;
}
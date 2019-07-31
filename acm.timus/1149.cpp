#include <bits/stdc++.h>
#define nmax 202
using namespace std;
string sins[nmax];
int n;
string getNumString(int x)
{
    string num;
    while (x)
        num.push_back((x%10) + '0'), x /= 10;
    reverse(num.begin(), num.end());
    return num;
}
void calcSins()
{
    sins[1] = "sin(1)";
    for (int i=2; i<=n; ++i)
    {
        sins[i] = sins[i-1];
        while (sins[i].back() == ')')
            sins[i].pop_back();
        if (i%2 == 0)
            sins[i].push_back('-');
        else
            sins[i].push_back('+');
        sins[i] += "sin(";
        sins[i] += getNumString(i);
        for (int j=1; j<=i; ++j)
            sins[i].push_back(')');
    }
}
int main()
{
    cin>>n;
    calcSins();
    //for (int i=1; i<=n; ++i)
    //     cout<<sins[i]<<'\n';
    string ans;
    for (int i=1; i<n; ++i)
        ans.push_back('(');
    for (int i=1; i<=n; ++i)
    {
        ans += sins[i];
        ans.push_back('+');
        ans += getNumString(n-i+1);
        if (i<n)
            ans.push_back(')');
    }
    cout<<ans<<'\n';
    return 0;
}

#include <bits/stdc++.h>
#define lld long long
#define nmax 100005
using namespace std;
lld n, sum;
string s;
int main()
{
    cin>>n;
    cin>>s;
    sort(s.begin(), s.end());
    for (auto x:s)
        sum += (x-'0');
    for (int i=0; i<s.size(); ++i)
    {
        if (sum >= n)
        {
            cout<<i<<'\n';
            return 0;
        }
        sum += 9 - (s[i] - '0');
    }
    cout<<s.size()<<'\n';
    return 0;
}

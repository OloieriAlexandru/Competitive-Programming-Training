#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
    return (a+b) < (b+a);
}
vector<string>a;
string act;
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>act;
        a.push_back(act);
    }
    sort(a.begin(), a.end(), cmp);
    for (auto x:a)
        cout<<x;
    cout<<'\n';
    return 0;
}

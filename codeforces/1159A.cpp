#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, act = 0, curr = 0, minn = 999999999;
    char ch;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>ch;
        if (ch == '-')
            --curr, --act;
        else
            ++curr, ++act;
        minn = min(minn, curr);
    }
    if (minn < 0)
        act += abs(minn);
    cout<<act<<'\n';
    return 0;
}

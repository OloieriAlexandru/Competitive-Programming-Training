#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s1, s2;
int calc(int poz)
{
    int ch1 = (int)s1[poz];
    int ch2 = (int)s2[poz];
    int z = (int)'0';
    int no = (int)'9';
    if (ch1 > ch2) swap(ch1, ch2);
    int ret = ch2 - ch1;
    ret = min(ret, ch1 - z + no - ch2 + 1);
    return ret;
}
int main()
{
    cin>>n;
    cin>>s1>>s2;
    for (int i=0;i<n;++i)
        ans += calc(i);
    cout<<ans<<'\n';
    return 0;
}

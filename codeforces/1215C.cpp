#include <bits/stdc++.h>
#define nmax 200005
using namespace std;
string s1, s2;
vector<pair<int,int>>ans;
vector<int>ab, ba;
bool u[nmax];
int countCh(string &s, char ch)
{
    int ret = 0;
    for (auto x:s)
        if (x == ch) ++ret;
    return ret;
}
int a1, a2, b1, b2, n;
int main()
{
    cin>>n;
    cin>>s1;
    cin>>s2;
    a1 = countCh(s1, 'a');
    b1 = countCh(s1, 'b');
    a2 = countCh(s2, 'a');
    b2 = countCh(s2, 'b');
    if ((a1+a2)%2 || (b1+b2)%2)
    {
        cout<<"-1\n";
        return 0;
    }
    for (int i=0; i<n; ++i)
        if (s1[i] != s2[i])
        {
            if (s1[i] == 'a')
            {
                if (ab.size())
                {
                    ans.push_back(make_pair(ab.back(), i));
                    ab.pop_back();
                }
                else
                    ab.push_back(i);
            }
            else
            {
                if (ba.size())
                {
                    ans.push_back(make_pair(ba.back(), i));
                    ba.pop_back();
                }
                else ba.push_back(i);
            }
        }
    if ((ab.size() && !ba.size()) || (!ab.size() && ba.size()))
    {
        cout<<"-1\n";
        return 0;
    }
    if (ab.size() && ba.size())
    {
        ans.push_back(make_pair(ab[0], ab[0]));
        ans.push_back(make_pair(ab[0], ba[0]));
    }
    cout<<ans.size()<<'\n';
    for (auto x:ans)
        cout<<x.first+1<<' '<<x.second+1<<'\n';
    return 0;
}

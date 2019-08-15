#include <bits/stdc++.h>
#define nmax 5005
using namespace std;
string s, all;
vector<int>ans;
int stv[nmax], act = -1;
string ot = "<table>";
string ct = "</table>";
string orr = "<tr>";
string cr = "</tr>";
string oc = "<td>";
string cc = "</td>";
bool matches(string &s, string &m, int i)
{
    for (int j=0;j<m.size() && (i + j)<s.size();++j)
        if (s[(i+j)] != m[j])
            return false;
    return true;
}
int main()
{
    while(cin>>s)
        all += s;
    for (int i=0;i<all.size();++i)
    {
        if (matches(all, ot, i))
        {
            ++act;
            stv[act] = 0;
        }
        else if (matches(all, ct, i))
        {
            ans.push_back(stv[act]);
            --act;
        }
        else if (matches(all, orr, i))
        {
            continue;
        }
        else if (matches(all, cr, i))
        {
            continue;
        }
        else if (matches(all, oc, i))
        {
            ++stv[act];
        }
        else if (matches(all, cc, i))
        {
            continue;
        }
        else
        {
            continue;
        }
    }
    sort(ans.begin(), ans.end());
    for (auto x:ans)
        cout<<x<<' ';
    cout<<'\n';
    return 0;
}

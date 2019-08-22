#include <bits/stdc++.h>
#define nmax 11
#define nmax2 10005
using namespace std;
int n, ln, lensum, linelen, need;
char ch;
string s;
bool used[nmax2];
vector<pair<string,int>>words[nmax], wrs;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>s;
        ln = s.size();
        lensum += ln;
        words[ln].push_back(make_pair(s, i));
        wrs.push_back(make_pair(s, i));
    }
    linelen = lensum/(n/2) + 1;
    cin>>ch;
    for (auto &it:wrs)
        it.first.push_back(ch);
    sort(wrs.begin(), wrs.end());
    for (int i=1; i<nmax; ++i)
        sort(words[i].begin(), words[i].end(), [](pair<string,int> s1, pair<string,int> s2)
    {
        return s1.first > s2.first;
    });
    for (int i=0; i<wrs.size(); ++i)
    {
        if (used[wrs[i].second]) continue;
        used[wrs[i].second] = true;
        cout<<wrs[i].first;
        ln = wrs[i].first.size();
        need = linelen - ln;
        while (used[words[need].back().second])
            words[need].pop_back();
        used[words[need].back().second] = true;
        cout<<words[need].back().first<<'\n';
    }
    return 0;
}

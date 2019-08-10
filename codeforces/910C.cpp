#include <bits/stdc++.h>
#define nmax 27
using namespace std;
vector<string>numbers;
int n;
string s;
long long significance[nmax], ans;
set<char>digits;
bool apFirst[nmax];
int assignn[nmax];
bool used[nmax], assigned[nmax];
int tens[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
void process(string &s)
{
    int act;
    for (int i=0; i<s.size(); ++i)
    {
        digits.insert(s[i]);
        act = s[i] - 'a';
        if (i == 0) apFirst[act] = 1;
        significance[act] += tens[s.size()-(i+1)];
    }
}
vector<pair<long,char>>v;
int main()
{
    cin>>n;
    for (int i=1; i<=n; ++i)
    {
        cin>>s;
        numbers.push_back(s);
        process(s);
    }
    for (int i=0; i<26; ++i)
    {
        if (!significance[i]) continue;
        v.push_back(make_pair(significance[i], (char)(i+'a')));
    }
    sort(v.begin(), v.end(), [](pair<long,char>a,pair<long,char>b)
    {
        return a.first > b.first;
    });
    int diff = digits.size();
    bool ok = false;
    for (int i=0; i<v.size(); ++i)
    {
        if (!apFirst[v[i].second-'a'])
        {
            assignn[v[i].second-'a'] = 0;
            assigned[v[i].second-'a'] = true;
            ok = true;
            break;
        }
    }
    int start, to;
    if (ok) start = 1, to = diff-1;
    else start = 1, to = diff;
    for (int t=1; t<=to; ++t)
    {
        for (int i=0; i<v.size(); ++i)
        {
            if (assigned[v[i].second-'a'])continue;
            assigned[v[i].second-'a'] = true;
            assignn[v[i].second-'a'] = t;
            break;
        }
    }
    for (int i=0; i<26; ++i)
        ans += assignn[i] * significance[i];
    cout<<ans<<'\n';
    return 0;
}

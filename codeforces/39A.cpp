#include <bits/stdc++.h>
#define nmax 1000005
#define pb push_back
#define mp make_pair
using namespace std;
char s[nmax];
int n, a, ln;
vector<pair<pair<int,int>,int>>as;
bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)
{
    return a.first.first*a.first.second < b.first.first*b.first.second;
}
int main()
{
    cin>>a;
    cin>>s;
    ln = strlen(s);
    int sign = 1;
    bool needs;
    for (int i=0; i<ln; ++i)
    {
        if (i > 0 && needs)
        {
            if (s[i] == '-')
                sign = -1;
            else
                sign = 1;
            needs = false;
            continue;
        }
        if (s[i] == 'a')
        {
            int coeff = 0;
            i += 3;
            if (s[i] == '*')
            {
                ++i;
                while (s[i] && s[i] >= '0' && s[i] <= '9')
                {
                    coeff = coeff * 10 + (s[i] - '0');
                    ++i;
                }
                as.pb(mp(mp(coeff, sign),0));
                --i;
            }
            else
            {
                --i;
                as.pb(mp(mp(1, sign),0));
            }
        }
        else if (s[i] == '+')
        {
            int coeff = 0;
            i += 3;
            if (s[i] == '*')
            {
                ++i;
                while (s[i] && s[i] >= '0' && s[i] <= '9')
                {
                    coeff = coeff * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                as.pb(mp(mp(coeff, sign),1));
            }
            else
            {
                --i;
                as.pb(mp(mp(1,sign),1));
            }
        }
        else
        {
            int coeff = 0;
            while (s[i] && s[i] >= '0' && s[i] <= '9')
            {
                coeff = coeff * 10 + (s[i] - '0');
                ++i;
            }
            as.pb(mp(mp(coeff, sign),s[i+1] == '+'?1:0));
            i += 3;
        }
        needs = true;
    }
    sort(as.begin(), as.end(), cmp);
    long long ans = 0;
    for (int i=0; i<as.size(); ++i)
    {
        if (as[i].second)
            ++a;
        ans += a * (as[i].first.first * as[i].first.second);
        if (!as[i].second)
            ++a;
    }
    cout<<ans<<'\n';
    return 0;
}

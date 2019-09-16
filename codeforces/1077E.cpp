#include <bits/stdc++.h>
#define nmax 1000005
#define maxLen 5000000
using namespace std;
int n, x, ans, p2[30], act;
int nr, fv[nmax];
char s[maxLen];
unordered_map<int,int>mp;
int main()
{
    mp.reserve(1000000);
    cin>>n;
    cin.get();
    cin.getline(s, maxLen);
    char*p;
    p = strtok(s, " ");
    while (p)
    {
        ++mp[atoi(p)];
        p = strtok(NULL, " ");
    }
    for (auto x:mp)
        fv[nr++] = x.second;
    sort(fv,fv+nr,[](int a, int b)
    {
        return a > b;
    });
    p2[0] = 1;
    for (int i=1; i<=20; ++i)
        p2[i] = p2[i-1] * 2;
    ans = fv[0];
    act = ans;
    int cnt = min(nr, 19);
    for (int i=1; i<cnt; ++i)
    {
        act = min(act/2, fv[i]);
        ans = max(ans, act * (p2[i+1]-1));
    }
    printf("%d\n", ans);
    return 0;
}

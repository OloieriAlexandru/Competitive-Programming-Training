#include <bits/stdc++.h>
#define nmax 15
#define lld long long
using namespace std;
int gen[nmax], sum;
vector<lld>ans[nmax];
bool ok(int ln)
{
    int fv[nmax];
    memset(fv, 0, sizeof(fv));
    for (int i=1; i<=ln; ++i)
        ++fv[gen[i]];
    for (int i=1; i<=ln; ++i)
        if (gen[i] != fv[i-1]) return false;
    return true;
}
lld num(int ln)
{
    lld ret = 0;
    for (int i=1; i<=ln; ++i)
        ret = 1LL*ret * 10 + gen[i];
    return ret;
}
void bkt(int k, int ln)
{
    if (k-1 == ln)
    {
        if (ok(ln))
            ans[ln].push_back(num(ln));
        return;
    }
    int start;
    if (k == 1) start = 1;
    else start = 0;
    for (int i=start; i<=9; ++i)
    {
        if (sum + i > ln) continue;
        sum += i;
        gen[k] = i;
        bkt(k+1, ln);
        sum -= i;
    }
}
int main()
{
    //freopen("out.txt","w",stdout);
    /*for (int i=1; i<=10; ++i)
    {
        cout<<"Incep "<<i<<'\n';
        bkt(1,i);
    }
    for (int i=1; i<=10; ++i)
    {
        cout<<i<<":\n";
        for (auto x:ans[i])
            cout<<x<<' ';
        cout<<'\n';
    }*/
    int t, n;
    cin>>t;
    vector<lld>anss[nmax];
    anss[1].push_back(-1);
    anss[2].push_back(-1);
    anss[3].push_back(-1);
    anss[6].push_back(-1);
    anss[4].push_back(1210);
    anss[4].push_back(2020);
    anss[5].push_back(21200);
    anss[7].push_back(3211000);
    anss[8].push_back(42101000LL);
    anss[9].push_back(521001000LL);
    anss[10].push_back(6210001000LL);
    while(t--)
    {
        cin>>n;
        for (auto x:anss[n])
            cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}

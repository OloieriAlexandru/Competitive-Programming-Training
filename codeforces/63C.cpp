#include <bits/stdc++.h>
#define nmax 10
using namespace std;
int n, bulls, perm[4], permans[4], cows, cnt;
char ch;
vector<int>v[10];
vector<pair<int,int>>bc;
bool uz[nmax];
bool match(int nw)
{
    int b = 0, c = 0;
    for (int i=0; i<4; ++i)
    {
        if (perm[i] == v[nw][i]) ++b;
        if (uz[v[nw][i]]) ++c;
    }
    c -= b;
    return b == bc[nw].first && c == bc[nw].second;
}
bool ok()
{
    for (int i=0; i<n; ++i)
        if (!match(i)) return false;
    return true;
}
void gen(int k)
{
    if (k == 4)
    {
        if (ok())
        {
            ++cnt;
            memcpy(permans, perm, sizeof(permans));
        }
        return ;
    }
    for (int i=0; i<10; ++i)
    {
        if (uz[i]) continue;
        uz[i] = true;
        perm[k] = i;
        gen(k+1);
        uz[i] = false;
    }
}
int main()
{
    cin>>n;
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<4; ++j)
        {
            cin>>ch;
            v[i].push_back(ch-'0');
        }
        cin>>bulls>>cows;
        bc.push_back(make_pair(bulls, cows));
    }
    gen(0);
    if (cnt >= 2)
        cout<<"Need more data\n";
    else if (!cnt)
        cout<<"Incorrect data\n";
    else
    {
        for (int i=0; i<4; ++i)
            cout<<permans[i];
        cout<<'\n';
    }
    return 0;
}

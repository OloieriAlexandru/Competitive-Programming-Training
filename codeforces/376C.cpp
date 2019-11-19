#include <bits/stdc++.h>
#define nmax 10
using namespace std;
string s;
int fv[nmax], req, sol[nmax];
int c[] = {1,6,8,9};
bool uz[nmax];
int ans;
bool ok;
void bkt(int k)
{
    if (ok)
    {
        return;
    }
    if (k==4)
    {
        int rr = req;
        for (int i=0; i<4; ++i)
        {
            rr=rr*10+sol[i];
            rr%=7;
        }
        if (!rr)
            ok=true;
        return;
    }
    for (int i=0; i<4; ++i)
    {
        if(uz[i])
        {
            continue;
        }
        uz[i]=true;
        ans=ans*10+c[i];
        sol[k]=c[i];
        bkt(k+1);
        if (ok)
            return;
        ans/=10;
        uz[i]=false;
    }
}
int main()
{
    cin>>s;
    for (auto x:s)
    {
        ++fv[x-'0'];
    }
    if (fv[1]&&fv[6]&&fv[8]&&fv[9])
        --fv[1], --fv[6], --fv[8], --fv[9];
    else
        return 0;
    int r = 0;
    for (int i=1; i<nmax; ++i)
    {
        while (fv[i])
        {
            cout<<i;
            --fv[i];
            r = r * 10 + i;
            r %= 7;
        }
    }
    req=r;
    bkt(0);
    cout<<ans;
    while (fv[0])
    {
        cout<<0;
        --fv[0];
    }
    cout<<'\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int ask(int x, int y)
{
    char ch;
    cout<<"? "<<x<<' '<<y<<'\n';
    fflush(stdout);
    cin>>ch;
    if (ch == 'x') return 1;
    else if (ch == 'y')return 2;
    exit(0);
}
void printAns(int x)
{
    cout<<"! "<<x<<'\n';
}
void solve(int k)
{
    int l, r;
    int li;
    if (k == -1) li = 0; else li = 1<<k;
    if (k == -1) l = 1, r = 1;
    else l = (1<<k) + 1, r = (1<<(k+1));
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (ask(li, m) == 1)
            r = m-1;
        else
            l = m+1;
    }
    printAns(l);
}
int main()
{
    string s;
    while(cin>>s)
    {
        if (s == "end") break;
        int i = 0;
        if (ask(0,1) == 1)
        {
            solve(-1);
            continue;
        }
        for (;i<30;++i)
            if (ask(1<<i,1<<(i+1)) == 1) break;
        solve(i);
    }
    return 0;
}

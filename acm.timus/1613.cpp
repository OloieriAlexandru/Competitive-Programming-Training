#include <bits/stdc++.h>
using namespace std;

struct e
{
    vector<int>poz;
};
e neww, act;
int n;
int x;
int q;
int l, r, v;
vector<int>rez;
map<int, e> M;

int main()
{
    cin>>n;
    for (int i = 1; i<=n; i++)
    {
        cin>>x;
        map<int, e>::iterator it = M.find(x);
        if (it != M.end())
        {
            it -> second.poz.push_back(i);
        }
        else
        {
            neww.poz.erase(neww.poz.begin(), neww.poz.begin() + neww.poz.size());
            neww.poz.push_back(i);
            M[x] = neww;
        }
    }
    for (map<int, e>::iterator it = M.begin(); it!= M.end(); ++it)
    {
        sort(it -> second.poz.begin(), it -> second.poz.begin() + it -> second.poz.size());
    }
    cin>>q;
    for (int i= 1; i<=q; i++)
    {
        cin>>l>>r>>v;
        map<int, e>::iterator it = M.find(v);
        if (it==M.end())
        {
            rez.push_back(0);
            continue;
        }
        int siz = it->second.poz.size();
        int st = 0, dr = siz-1;
        int m;
        while (st<=dr)
        {
            m = (st+dr)/2;
            if ((it -> second.poz[m]) == l)
            {
                st = m;
                break;
            }
            if ((it -> second.poz[m])>l)
            {
                dr = m - 1 ;
            }
            else
            {
                st = m + 1;
            }
        }
        if ((it -> second.poz[st]>=l)&&(it -> second.poz[st]<=r) && st >=0 && st<siz)
        {
            rez.push_back(1);
        }
        else
        {
            rez.push_back(0);
        }
    }
    for (auto i : rez)
    {
        cout<<i;
    }
    cout<<'\n';
    return 0;
}
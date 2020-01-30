#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, m, x, v[nmax];
char ch;
struct a
{
    int val, poz;
};
a aint[nmax*4];
void build(int nod, int st, int dr)
{
    if (st == dr){
        aint[nod].val = v[st];
        aint[nod].poz = st;
        return;
    }
    int m = (st + dr) / 2;
    build(nod<<1,st,m);
    build(nod<<1|1,m+1,dr);
    if (aint[nod<<1].val <= aint[nod<<1|1].val){
        aint[nod] = aint[nod<<1];
    } else {
        aint[nod] = aint[nod<<1|1];
    }
}
a query(int nod, int st, int dr, int x, int y){
    if (x <= st && dr <= y){
        return aint[nod];
    }
    int m = (st + dr) / 2;
    a a1, a2;
    a1.val = 999;
    a2.val = 999;
    if (x <= m){
        a1 = query(nod<<1,st,m,x,y);
    }
    if (y > m){
        a2 = query(nod<<1|1,m+1,dr,x,y);
    }
    if (a1.val <= a2.val){
        return a1;
    }
    return a2;
}
int main()
{
    cin>>n>>m;
    for (int i=0;i<=n;++i){
        cin>>ch;
        v[i]=ch-'0';
    }
    build(1, 0, n-1);
    vector<int>ans;
    int poz = n;
    while (poz > 0){
        int cr = max(poz-m, 0);
        a act = query(1, 0, n-1, cr, poz-1);
        if (act.val != 0){
            cout<<"-1\n";
            return 0;
        }
        int add = poz - act.poz;
        ans.push_back(add);
        poz = act.poz;
    }
    reverse(ans.begin(), ans.end());
    for (auto x:ans){
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}

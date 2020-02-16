#include <bits/stdc++.h>
#define nmax 100005
#define ld double
using namespace std;
ld a[nmax], v[nmax], aint[4*nmax];
int n, m, op;
void build(int nod, int st, int dr){
    if (st == dr){
        aint[nod] = a[st];
        return;
    }
    int m = (st+dr)/2;
    build(nod<<1,st,m);
    build(nod<<1|1,m+1,dr);
    aint[nod] = aint[nod<<1] + aint[nod<<1|1];
}
void update(int nod, int st, int dr, int x, ld y){
    if (st == dr){
        aint[nod] = y;
        return;
    }
    int m = (st + dr) / 2;
    if (x <= m){
        update(nod<<1,st,m,x,y);
    } else {
        update(nod<<1|1,m+1,dr,x,y);
    }
    aint[nod] = aint[nod<<1] + aint[nod<<1|1];
}
ld query(int nod, int st, int dr, int x, int y){
    if (x <= st && dr <= y){
        return aint[nod];
    }
    int m = (st + dr) / 2;
    ld ans = 0;
    if (x <= m){
        ans += query(nod<<1,st,m,x,y);
    }
    if (y > m){
        ans += query(nod<<1|1,m+1,dr,x,y);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%lf",&v[i]);
        a[i] = log2(v[i]);
    }
    build(1,1,n);
    scanf("%d",&m);
    for (int t=1;t<=m;++t){
        scanf("%d",&op);
        if (op == 1){
            int x;
            ld y;
            scanf("%d %lf",&x,&y);
            a[x] = log2(y);
            v[x] = y;
            update(1,1,n,x,a[x]);
        } else {
            int x, y;
            scanf("%d %d",&x,&y);
            ld ans = query(1,1,n,x,y);
            if (ans >= 100.0){
                cout<<"INFINITE!\n";
            } else {
                cout<<setprecision(10)<<fixed<<pow(2,ans)<<'\n';
            }
        }
    }
    return 0;
}

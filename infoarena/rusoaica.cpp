#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 100005
using namespace std;
lld ans = 0;
priority_queue< pair<int,pair<int,int>> , vector < pair<int,pair<int,int>> > , greater < pair<int,pair<int,int>> > >pq;
int n, m, a, x, y, c;
int h[nmax], t[nmax];
void unionn(int x, int y){
    if (h[x] == h[y]){
        ++h[x];
        t[y] = x;
    } else if (h[x] > h[y]){
        t[y] = x;
    } else {
        t[x] = y;
    }
}
int findd(int x){
    int cx = x, up;
    while (t[x]){
        x = t[x];
    }
    if (x != cx){
        while (t[cx]){
            up = t[cx];
            t[cx] = x;
            cx = up;
        }
    }
    return x;
}
int main()
{
    freopen("rusuoaica.in","r",stdin);
    freopen("rusuoaica.out","w",stdout);
    scanf("%d %d %d",&n,&m,&a);
    for (int i=1;i<=m;++i){
        scanf("%d %d %d",&x,&y,&c);
        if (c > a){
            ans -= c;
        } else {
            pq.push(make_pair(c,make_pair(x,y)));
        }
    }
    int chosen = 0;
    pair<int,pair<int,int>> act;
    while (!pq.empty() && chosen < n-1){
        act = pq.top();
        pq.pop();
        int c1 = findd(act.second.first);
        int c2 = findd(act.second.second);
        if (c1 == c2){
            ans -= act.first;
            continue;
        }
        ++chosen;
        ans += act.first;
        unionn(c1, c2);
    }
    while (!pq.empty()){
        ans -= pq.top().first;
        pq.pop();
    }
    ans += 1LL * ((n-1)-chosen) * a;
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

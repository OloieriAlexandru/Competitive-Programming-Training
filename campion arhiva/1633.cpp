#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 102
#define inf 999999999
using namespace std;
int n, m, t, x, y, sum[nmax][nmax], a[nmax][nmax], dist[nmax][nmax], tot[nmax][nmax];
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool used[nmax][nmax];
void lee(int l, int c){
    queue<pii>q;
    pii act;
    int i, j;
    q.push(mp(l,c));
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            used[i][j] = false;
        }
    }
    dist[l][c] = 0;
    used[l][c] = true;
    while (!q.empty()){
        act = q.front(); q.pop();
        i = act.first, j = act.second;
        sum[i][j] += dist[i][j];
        ++tot[i][j];
        for (int k=0;k<4;++k){
            if (a[i+dl[k]][j+dc[k]] == 1 || used[i+dl[k]][j+dc[k]]){
                continue;
            }
            used[i+dl[k]][j+dc[k]] = true;
            dist[i+dl[k]][j+dc[k]] = dist[i][j] + 1;
            q.push(mp(i+dl[k],j+dc[k]));
        }
    }
}
int main()
{
    freopen("wow.in","r",stdin);
    freopen("wow.out","w",stdout);
    scanf("%d %d %d",&n,&m,&t);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=0;i<=n+1;++i){
        a[i][0] = a[i][m+1] = 1;
    }
    for (int j=0;j<=m+1;++j){
        a[0][j] = a[n+1][j] = 1;
    }
    for (int i=1;i<=t;++i){
        scanf("%d %d",&x,&y);
        lee(x+1,y+1);
    }
    int minn = inf;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (a[i][j] || tot[i][j] != t){
                continue;
            }
            minn = min(minn, sum[i][j]);
        }
    }
    printf("%d\n", minn);
    bool quit = false;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (sum[i][j] == minn && tot[i][j] == t){
                printf("%d %d\n", i-1, j-1);
                quit = true;
                break;
            }
        }
        if (quit){
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
2 nov 2017, 22:39

#include <fstream>

using namespace std;

ifstream fin("wow.in");
ofstream fout("wow.out");

struct fab
{
    int x, y;
} repr[1502];

struct geniu
{
    int l, c;
} C[10010], X;

void citire();
void bordare();
void adunare();
void copiere();
void scad_m();
void caut();
void lee(int, int);
void afisare();

int initial[102][102], suma[102][102], repr_curent[102][102];
int dl[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int minim = 99999999, pozi, pozj;
int n, m, p, i;

int main()
{
    citire();
    bordare();
    for(i = 1; i <= m; ++i)
    {
        copiere();
        lee(repr[i].x, repr[i].y);
        adunare();
    }
    scad_m();
    caut();
    afisare();
    return 0;
}

void citire()
{
    int i, j;
    fin >> n >> p;
    fin >> m;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= p; ++j)
        {
            fin >> initial[i][j];
            if(initial[i][j] == 1)
                initial[i][j] = -1;
        }
    for(i = 1; i <= m; ++i)
    {
        fin >> repr[i].x >> repr[i].y;
        repr[i].x++;
        repr[i].y++;
    }
}

void bordare()
{
    int i;
    for(i = 0; i <= n + 1; ++i)
        initial[i][0] = initial[i][p+1] = -1;
    for(i = 0; i <= p + 1; ++i)
        initial[0][i] = initial[n+1][i] = -1;
}

void copiere()
{
    int i, j;
    for(i = 0; i <= n + 1; ++i)
        for(j = 0; j <= p + 1; ++j)
            repr_curent[i][j] = initial[i][j];
}

void adunare()
{
    int i, j;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= p; ++j)
        {
            if(repr_curent[i][j] != 0 && suma[i][j] != -1)
                suma[i][j] += repr_curent[i][j];
            else
                suma[i][j] = -1;
        }
}

void lee(int li, int ci)
{
    int i, ic = 0, sc = 0, l9, c9;
    C[ic].l = li;
    C[ic].c = ci;
    repr_curent[li][ci] = 1;
    while(ic <= sc)
    {
        X = C[ic];
        ic++;
        for(i = 0; i <= 3; ++i)
        {
            if(repr_curent[X.l + dl[i]][X.c + dc[i]] == 0)
            {
                l9 = X.l + dl[i];
                c9 = X.c + dc[i];
                repr_curent[l9][c9] = repr_curent[X.l][X.c] + 1;
                ++sc;
                C[sc].l = l9;
                C[sc].c = c9;
            }
        }
    }
}

void scad_m()
{
    int i, j;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= p; ++j)
            suma[i][j] -= m;
}

void afisare()
{
    --pozi;
    --pozj;
    fout << minim << '\n';
    fout << pozi << ' ' << pozj;
    fout << '\n';
    fout.close();
}

void caut()
{
    int i, j;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= p; ++j)
            if(suma[i][j] < minim && suma[i][j] > 0)
            {
                minim = suma[i][j];
                pozi = i;
                pozj = j;
            }
}

*/

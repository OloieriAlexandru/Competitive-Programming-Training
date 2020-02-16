#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define nmax 260
using namespace std;
char a[nmax][nmax];
bool vis1[nmax][nmax], vis2[nmax][nmax];
int a1[nmax][nmax], a2[nmax][nmax], x1, y111, x2, y2;
vector<pii>ans;
int n, m;
int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool interior(int i, int j){
    return i>=1&&i<=n&&j>=1&&j<=m;
}
void lee(int m[nmax][nmax], int xs, int ys, bool visited[nmax][nmax], bool can = false){
    queue<pii>q;
    visited[xs][ys] = true;
    m[xs][ys] = 0;
    pii act;
    q.push(mp(xs,ys));
    m[xs][ys] = 1;
    int i, j, ii, jj;
    while (!q.empty()){
        act = q.front(); q.pop();
        i = act.first, j = act.second;
        for (int k=0;k<4;++k){
            ii = i+dl[k];
            jj = j+dc[k];
            if (!interior(ii,jj)) continue;
            if (a[ii][jj] == 'P' || (a[ii][jj] == 'C' && !can)) continue;
            //if (a[ii][jj] == 'T' || a[ii][jj] == 'J') continue;
            if (visited[ii][jj]) continue;
            visited[ii][jj] = true;
            m[ii][jj] = m[i][j] + 1;
            q.push(mp(ii,jj));
        }
    }
}
int main()
{
    freopen("tom.in","r",stdin);
    freopen("tom.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>a[i][j];
            if (a[i][j] == 'T'){
                x1 = i, y111 = j;
            } else if (a[i][j] == 'J'){
                x2 = i, y2 = j;
            }
        }
    }
    lee(a1, x1, y111, vis1);
    lee(a2, x2, y2, vis2, true);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (!(vis1[i][j] && vis2[i][j])){
                continue;
            }
            if (a1[i][j] == a2[i][j]*2-1){
                ans.pb(mp(i,j));
            }
        }
    }
    cout<<ans.size()<<'\n';
    for (unsigned i=0;i<ans.size();++i){
        cout<<ans[i].first<<' '<<ans[i].second<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
11 nov 2017, 23:52

#include <fstream>

using namespace std;

ifstream fin("tom.in");
ofstream fout("tom.out");

struct elem
{
    int x,y,d;
};
int i,j,n,m,a[258][258],xj,yj,xt,yt,b[258][258],p,u,ok,nr,v1[1001],v2[1001];
char ca;
elem c1[256*256],w,c2[256*256];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            fin>>ca;
            if(ca=='P')
            {
                a[i][j]=-1;
                b[i][j]=-1;
            }
            if(ca=='C')
                b[i][j]=-2;
            if(ca=='J')
            {
                xj=i;
                yj=j;
            }
            if(ca=='T')
            {
                xt=i;
                yt=j;
            }
        }
    for(i=0;i<m+2;i++)
    {
        a[0][i]=a[n+1][i]=-1;
        b[0][i]=b[n+1][i]=-1;
    }
    for(i=0;i<n+2;i++)
    {
        a[i][0]=a[i][m+1]=-1;
        b[i][0]=b[i][m+1]=-1;
    }
    c1[p].x=xj;
    c1[p].y=yj;
    c1[p].d=1;
    c2[p].x=xt;
    c2[p].y=yt;
    c2[p].d=1;
    a[xj][yj]=1;
    b[xt][yt]=1;
    while(p<=u)
    {
        w=c1[p];
        p++;
        for(i=0;i<4;i++)
        {
            if(a[w.x+dx[i]][w.y+dy[i]]==0)
            {
                u++;
                c1[u].x=w.x+dx[i];
                c1[u].y=w.y+dy[i];
                c1[u].d=w.d+1;
                a[w.x+dx[i]][w.y+dy[i]]=w.d+1;
            }
        }
    }
    p=u=0;
    while(p<=u)
    {
        w=c2[p];
        p++;
        for(i=0;i<4;i++)
            if(b[w.x+dx[i]][w.y+dy[i]]==0)
            {
                u++;
                c2[u].x=w.x+dx[i];
                c2[u].y=w.y+dy[i];
                c2[u].d=w.d+1;
                b[w.x+dx[i]][w.y+dy[i]]=w.d+1;
            }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i][j]!=-1)
                if(b[i][j]==2*a[i][j]-1)
                {
                    nr++;
                    v1[nr]=i;
                    v2[nr]=j;
                }
    fout<<nr<<'\n';
    for(i=1;i<=nr;i++)
        fout<<v1[i]<<' '<<v2[i]<<'\n';
    fout.close();
    return 0;
}
*/

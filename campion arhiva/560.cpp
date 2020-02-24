#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 10005
using namespace std;
vector<int>g[nmax];
vector< pii > cc;
int n, m, x, y, nrcc;
bool uz[nmax];
void dfs(int k){
    uz[k] = true;
    ++nrcc;
    for (int i=0;i<g[k].size();++i){
        if (uz[g[k][i]]){
            continue;
        }
        dfs(g[k][i]);
    }
}
bool cmp(const pii & a, const pii & b){
    return a.first > b.first;
}
int main()
{
    freopen("turn1.in","r",stdin);
    freopen("turn1.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;++i){
        scanf("%d %d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i=1;i<=n;++i){
        if (uz[i]){
            continue;
        }
        nrcc = 0;
        dfs(i);
        cc.pb(mp(nrcc,i));
    }
    sort(cc.begin(),cc.end(),cmp);
    if (cc.size() == 1){
        cout<<"1 1\n";
    } else {
        cout<<cc[0].second<<' '<<cc[1].second<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
10 apr 2019, 17:23
80 puncte

#include <fstream>
#include <vector>
#include <iostream>
#define NMAX 10010
using namespace std;
ifstream fin("turn1.in");
ofstream fout("turn1.out");

vector<int> G[NMAX];
int n, m;
int nr[NMAX];
int x, y;
int num;
bool uz[NMAX];
int max1, max2, nr1, nr2;

void dfs(int k);

int main()
{
    int i;
    fin>>n>>m;
    for(i=1; i<=m; i++)
    {
        fin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (i=1; i<=n; i++)
    {
        if (!uz[i])
        {
            num = 0;
            dfs(i);
            // o sa am cate noduri are componenta
            if(num>max1)
            {
                max2=max1;
                max1=num;
                nr2=nr1;
                nr1=i;
            }
            else if(x>max2)
            {
                max2=x;
                nr2=i;
            }
        }
    }
    fout<<nr1<<' '<<nr2<<'\n';
    fin.close();
    fout.close();
    return 0;
}
void dfs(int k)
{
    int i, vecin;
    uz[k]=1;
    num++;
    for(i=0; i<G[k].size(); i++)
    {
        vecin=G[k][i];
        if(!uz[vecin])
        {
            dfs(vecin);
        }
    }
}
*/

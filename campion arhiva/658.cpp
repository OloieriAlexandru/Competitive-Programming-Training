#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
bool ad[nmax][nmax];
int n, m, x, y;
vector<int>ans;
int main()
{
    srand(time(NULL));
    freopen("joc10.in","r",stdin);
    freopen("joc10.out","w",stdout);
    scanf("%d",&n);
    m = (n*(n-1))/2;
    for (int i=1;i<=m;++i){
        scanf("%d %d",&x,&y);
        ad[x][y] = true;
    }
    ans.push_back(1);
    for (int i=2;i<=n;++i){
        if (ad[ans.back()][i]){
            ans.push_back(i);
            continue;
        }
        bool found = false;
        for (int j=i-1;j>0;--j){
            if (ad[ans[j-1]][i] && ad[i][ans[j]]){
                found = true;
                ans.insert(ans.begin()+j, i);
                break;
            }
        }
        if (found){
            continue;
        }
        ans.insert(ans.begin(),i);
    }
    for (int i=0;i<n;++i){
        printf("%d ",ans[i]);
    }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
12 apr 2017, 21:53
90 puncte

#include <fstream>
#include <vector>
#define nmax 1005

using namespace std;
ifstream fin("joc10.in");
ofstream fout("joc10.out");

vector <int> G[nmax];
int sol[nmax];
bool uz[nmax];
int n;
bool ok;

void bkt(int k, int nod);

int main()
{
int i;
int x, y;
int m;
fin>>n;
m=(n*(n-1))/2;
for (i=1;i<=m;i++)
    {
     fin>>x>>y;
     G[x].push_back(y);
    }
for (i=1;i<=n;i++)
    {
     uz[i]=1;
     sol[1]=i;
     bkt(2,i);
     if (ok) break;
     uz[i]=0;
    }
fin.close();
fout.close();
return 0;
}

void bkt(int k, int nod)
    {
     unsigned int i;
     if (ok)
         return ;
     if (k==n+1)
        {
         for (i=1;i<=n;i++)
              fout<<sol[i]<<' ';
         ok=1;
         return ;
        }
     for (i=0;i<G[nod].size();i++)
         if (!uz[G[nod][i]])
            {
             sol[k]=G[nod][i];
             uz[G[nod][i]]=1;
             bkt(k+1,G[nod][i]);
             uz[G[nod][i]]=0;
            }
    }
*/

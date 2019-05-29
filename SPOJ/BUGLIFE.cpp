#include <stdio.h>
#include <set>
#include <vector>
#define LMAX 2005
#define pii pair<int,int>
#define mp make_pair

using namespace std;

int color[LMAX];
bool use[LMAX];
int n, m;
int x, y;
vector<int>G[LMAX];
set<pii>mu;

bool dfs(int act, int col)
{
    bool ans = true;
    use[act] = 1;
    color[act] = col;
    for (int i=0;i<G[act].size();++i)
    {
        if (!use[G[act][i]])
        {
            ans = ans && dfs(G[act][i], 3-col);
        }
        else
        if (use[G[act][i]] && color[G[act][i]] == col)
        {
            ans = false;
            break;
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int q=1;q<=t;++q)
    {
        scanf("%d %d",&n,&m);
        for (int i=1;i<=m;++i)
        {
            scanf("%d %d",&x,&y);
            if (x>y)
            {
                swap(x, y);
            }
            if (mu.count(mp(x, y)))
            {
                continue;
            }
            G[x].push_back(y);
            G[y].push_back(x);
            mu.insert(mp(x, y));
        }
        bool ans = true;
        for (int i=1;i<=n;++i)
        {
            if (!use[i])
            {
                ans = ans && dfs(i, 1);
                if (!ans)
                {
                    break;
                }
            }
        }
        printf("Scenario #%d:\n", q);
        if (ans)
        {
            printf("No suspicious bugs found!\n");
        }
        else
        {
            printf("Suspicious bugs found!\n");
        }
        for (int i=1;i<=n;++i)
        {
            color[i] = 0;
            use[i] = 0;
            G[i].clear();
        }
        mu.clear();
    }
    return 0;
}

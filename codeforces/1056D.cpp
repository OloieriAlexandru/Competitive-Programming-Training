#include <iostream>
#include <vector>
#define LMAX 100005

using namespace std;

int n;
int x;
int fv[LMAX];
vector<int>G[LMAX];

int dfs(int k)
{
    if (G[k].size()==0)
    {
        fv[1]++;
        return 1;
    }
    int f = 0;
    for (auto i = 0u; i<G[k].size(); i++)
    {
        f+=dfs(G[k][i]);
    }
    fv[f]++;
    return f;
}

int main()
{
    cin>>n;
    for (int i = 2; i<=n; i++)
    {
        cin>>x;
        G[x].push_back(i);
    }
    dfs(1);
    int nr = fv[1];
    int c = 1;
    for (int i =1; i<=n; i++)
    {
        if (i<=nr)
        {
            cout<<c<<' ';
        }
        else
        {
            while (i>nr)
            {
                c++;
                nr+=fv[c];
            }
            cout<<c<<' ';
        }
    }
    cout<<'\n';
    return 0;
}

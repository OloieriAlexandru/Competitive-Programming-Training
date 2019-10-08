#include <bits/stdc++.h>
#define LMAX 200005

using namespace std;

int act[LMAX];
int v[LMAX];
int st, dr, have;
int n, which;
int rankk;

int main()
{
    cin>>n>>which;
    for (int i = 1;i<=n;i++)
    {
        scanf("%d",&act[i]);
    }
    have = act[which];
    for (int i = 1;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }
    have += v[1];
    st = 2;
    dr = n;
    for (int i = 1;i<which;i++)
    {
        if (act[i] + v[dr] > have)
        {
            rankk++;
            st++;
        }
        else
        if (act[i] + v[dr] <= have)
        {
            dr--;
        }
    }
    for (int i = which+1; i<=n;i++)
    {
        if (act[i] + v[st] > have)
        {
            rankk++;
            dr--;
        }
        else
        {
            st++;
        }
    }
    cout<<rankk+1<<'\n';
    return 0;
}

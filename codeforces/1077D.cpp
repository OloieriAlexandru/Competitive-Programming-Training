#include <iostream>
#include <vector>
#define max(a,b) a>b?a:b
#define LMAX 222222

using namespace std;

struct e
{
    int v;
    int ap;
    e(int v, int ap)
    {
        this -> v= v;
        this -> ap = ap;
    }
};
vector<e> ve;
vector<int> sol;
int maxim;
int n, k;
int x;
int ap[LMAX];

bool ok(int m)
{
    int p = 0;
    for (int i = 0;i<ve.size();i++)
    {
        p+=ve[i].ap/m;
    }
    return p>=k;
}

void add(int m)
{
    int added = 0;
    sol.clear();
    for (int i = 0;i<ve.size();i++)
    {
        int nr = ve[i].ap;
        while (1)
        {
            nr-=m;
            if (nr<0)
            {
                break;
            }
            sol.push_back(ve[i].v);
            added++;
            if (added == k)
            {
                break;
            }
        }
    }
}

int main()
{
    cin>>n>>k;
    for (int i= 1;i<=n;i++)
    {
        cin>>x;
        maxim = max(maxim, x);
        ap[x]++;
    }
    for (int i = 1;i<=maxim;i++)
    {
        if (ap[i])
        {
            ve.emplace_back(i, ap[i]);
        }
    }
    int st = 1;
    int dr = n;
    while (st<=dr)
    {
        int m = (st+dr)/2;
        if (ok(m))
        {
            st = m+1;
            add(m);
        }
        else
        {
            dr = m-1;
        }
    }
    for (int i= 0;i<k;i++)
    {
        cout<<sol[i]<<' ';
    }
    cout<<'\n';
    return 0;
}

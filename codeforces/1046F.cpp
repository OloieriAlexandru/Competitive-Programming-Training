#include <iostream>
#define LMAX 200005
#define lld long long int
using namespace std;

lld n, m, fee;
lld a[LMAX];
lld af;
lld imp;

int main()
{
    cin>>n;
    for (int i = 1; i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>m>>fee;
    imp = m+fee;
    for (int i= 1 ;i<=n;i++)
    {
        if (a[i]>m)
        {
            af+=(a[i]/imp);
            if(a[i]%imp>m)
            {
                af++;
            }
        }
    }
    cout<<af*fee<<'\n';
    return 0;
}

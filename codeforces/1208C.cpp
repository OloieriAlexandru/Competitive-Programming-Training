#include <bits/stdc++.h>
#define nmax 1005
using namespace std;
int m[4][4] =
{
    {
        8,9,1,13
    },
    {
        3,12,7,5
    },
    {
        0,2,4,11
    },
    {
        6,10,15,14
    }
};
int ans[nmax][nmax], n, curr;

int main()
{
    cin>>n;
    int nn = n / 4;
    for (int i=1;i<=nn;++i)
    {
        for (int j=1;j<=nn;++j)
        {
            for (int ii = 0;ii<4;++ii)
                for (int jj=0;jj<4;++jj)
                    ans[(i-1)*4+1+ii][(j-1)*4+1+jj] = m[ii][jj] + curr;
            curr += 16;
        }
    }

    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            cout<<ans[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}

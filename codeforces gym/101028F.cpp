#include <bits/stdc++.h>
#define nmax 1001
using namespace std;
char s[nmax], s2[5], s3[5];
int ind[][3] =
{
    {
        0,1,2
    },
    {
        0,1,3
    },
    {
        0,2,3
    },
    {
        1,2,3
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s>>s2;
        if (strstr(s, s2))
        {
            cout<<"good\n";
            continue;
        }
        bool ok = false;
        for (int i=0;i<4;++i)
        {
            for (int j=0;j<3;++j)
            {
                s3[j] = s2[ind[i][j]];
            }
            if (strstr(s, s3))
            {
                ok = true;
                break;
            }
        }
        if (!ok)
            cout<<"none\n";
        else
            cout<<"almost good\n";
    }
    return 0;
}

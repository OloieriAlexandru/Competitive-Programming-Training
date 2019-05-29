#include <iostream>
#include <cstring>
#include <vector>
#define LMAX 105
#define MAX(a,b) a>b?a:b
using namespace std;

int dp[LMAX][LMAX];
char a[LMAX];
char b[LMAX];
int lga;
int lgb;

void doDp()
{
    for (int i=1; i<=lga; ++i)
    {
        for (int j=1; j<=lgb; ++j)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = MAX(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = lga, j = lgb;
    vector<int>poz1, poz2;
    while (i>=1&&j>=1)
    {
        if (a[i]==b[j])
        {
            //cout<<a[i];
            poz1.push_back(i);
            poz2.push_back(j);
            --j;
            --i;
        }
        else if (dp[i-1][j]>dp[i][j-1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }
    /*cout<<'\n';
    for (int i=poz1.size()-1;i>=0;--i)
    {
        cout<<poz1[i]<<' ';
    }
    cout<<'\n';
    for (int i=poz2.size()-1;i>=0;--i)
    {
        cout<<poz2[i]<<' ';
    }
    cout<<'\n';*/
    int it1 = 1, it2 = 1;
    i = poz1.size()-1;
    j = poz2.size()-1;
    while (i>=0&&j>=0&&it1<=lga&&it2<=lgb)
    {
        while (it1<poz1[i])
        {
            cout<<a[it1++];
        }
        while (it2<=poz2[j])
        {
            cout<<b[it2++];
        }
        ++it1;
        i--;
        j--;
    }
    while (it1<=lga)
    {
        cout<<a[it1++];
    }
    while (it2<=lgb)
    {
        cout<<b[it2++];
    }
    cout<<'\n';
}

int main()
{
    while (cin>>(a+1))
    {
        cin>>(b+1);
        lga = strlen(a+1);
        lgb = strlen(b+1);
        doDp();
    }
    return 0;
}

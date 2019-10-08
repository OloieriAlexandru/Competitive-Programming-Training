#include <stdio.h>
#include <iostream>
#include <vector>
#define LMAX 200005

using namespace std;

int n;
int a[LMAX];
int m1, m2 = -1;
int ap1, ap2;

vector<int>ans;

long long int s;

int main()
{
    scanf("%d",&n);
    for (int i= 1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if (a[i]>m1)
        {
            m2 = m1;
            ap2 = ap1;
            m1 = a[i];
            ap1 = 1;
        }
        else if (a[i]==m1)
        {
            ap1++;
        }
        else if (a[i]>m2)
        {
            m2 = a[i];
        }
        else if (a[i] == m2)
        {
            ap2++;
        }
        s+=a[i];
    }
    for (int i = 1; i<=n; i++)
    {
        long long int cs = s;
        cs-=a[i];
        if (a[i] == m1)
        {
            if (ap1>1)
            {
                if (cs-m1 == m1)
                {
                    ans.push_back(i);
                }
            }
            else
            {
                if (cs-m2 == m2)
                {
                    ans.push_back(i);
                }
            }
        }
        else
        {
            if (cs-m1 == m1)
            {
                ans.push_back(i);
            }
        }
    }
    cout<<ans.size()<<'\n';
    for (auto x : ans)
    {
        cout<<x<<' ';
    }
    cout<<'\n';
    return 0;
}

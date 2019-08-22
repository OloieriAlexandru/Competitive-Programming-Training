#include <bits/stdc++.h>
#define nmax 55
using namespace std;
bool a[nmax][nmax];
int odd = 1, even = 2, n, m, mid;
int nextOdd()
{
    odd += 2;
    return odd-2;
}
int nextEven()
{
    even += 2;
    return even-2;
}
int main()
{
    cin>>n;
    mid = n / 2 + 1;
    for (int i=1; i<=n; ++i)
        a[mid][i] = a[i][mid] = 1;
    for (int i=mid-1;i>=1;--i)
    {
        int cj1 = mid, ci = i, cj2 = mid;
        while (ci < mid)
        {
            a[ci][cj1] = a[ci][cj2] = 1;
            ++ci, --cj1, ++cj2;
        }
    }
    for (int i=mid+1;i<=n;++i)
    {
        int cj1 = mid, cj2 = mid, ci=i;
        while (ci > mid)
        {
            a[ci][cj1] = a[ci][cj2] = 1;
            --ci, --cj1, ++cj2;
        }
    }
    for (int i=1; i<=n; ++i)
    {
        for (int j=1; j<=n; ++j)
        {
            if (!a[i][j])
                cout<<nextEven()<<' ';
            else
                cout<<nextOdd()<<' ';
        }
        cout<<'\n';
    }
    return 0;
}

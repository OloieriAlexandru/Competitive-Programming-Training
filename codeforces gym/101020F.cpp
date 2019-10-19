#include <bits/stdc++.h>
#define nmax 16
using namespace std;
int n, a[nmax], ans1, ans2;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for (int i=0; i<n; ++i)
            cin>>a[i];
        sort(a,a+n);
        int cnt = 1<<n;
        ans1 =  ans2 = 0;
        for (int i=1; i<cnt; ++i)
        {
            int penalty = 0, sum = 0, cnt = 0;
            for (int j=0; j<n; ++j)
                if (i & (1 << j))
                {
                    sum += a[j];
                    penalty += sum;
                    ++cnt;
                }
            if (sum > 300) continue;
            if (cnt > ans1)
                ans1 = cnt, ans2 = penalty;
            else
            if (cnt == ans1 && penalty < ans2)
                ans2 = penalty;
        }
        cout<<ans1<<' '<<ans2<<'\n';
    }
    return 0;
}

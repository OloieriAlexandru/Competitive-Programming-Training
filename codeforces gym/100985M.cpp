#include <bits/stdc++.h>
#define nmax 1010
using namespace std;
int n, m, ans, cnt;
string a[nmax];
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>a[i];
    ans=0;
    cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m && i%2==0; j++)
        {
            if(a[i][j]=='L')
            {
                ans=max(ans,cnt);
                cnt=0;
            }
            cnt+=(a[i][j]=='.');
        }
        for(int j=m-1; j>=0 && i%2; j--)
        {
            if(a[i][j]=='L')
            {
                ans=max(ans,cnt);
                cnt = 0;
            }
            cnt+=(a[i][j]=='.');
        }
        ans=max(ans,cnt);

    }
    cout<<ans<<'\n';
    return 0;
}

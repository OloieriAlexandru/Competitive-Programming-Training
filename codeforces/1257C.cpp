#include <bits/stdc++.h>
#define inf 999999999
using namespace std;

int main()
{
    int t, n, x;
    scanf("%d",&t);
    while(t--)
    {
        unordered_map<int,int>lastP;
        scanf("%d",&n);
        int ans = inf;
        for (int i=1;i<=n;++i){
            scanf("%d",&x);
            if (lastP.count(x)){
                ans=min(ans,i-lastP[x]+1);
            }
            lastP[x]=i;
        }
        if (ans == inf){
            printf("-1\n");
        } else {
            printf("%d\n",ans);
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
vector<int>ans;
lld n;
int main()
{
    freopen("teanc.in","r",stdin);
    freopen("teanc.out","w",stdout);
    cin>>n;
    lld k;
    for (k=1;true;++k){
        if (k*(k+1)/2 == n){
            printf("%lld\n",k);
            for (int i=k;i>=1;--i){
                printf("%d ",i);
            }
            printf("\n");
            return 0;
        }
        if (n-(k*(k+1)/2)<=k){
            int more = n-(k*(k+1)/2);
            for (int i=k;i>=more;--i){
                ans.push_back(i);
            }
            ans.push_back(more);
            for (int i=more-1;i>=1;--i){
                ans.push_back(i);
            }
            break;
        }
        if (k > 100000){
            break;
        }
    }
    printf("%u\n",ans.size());
    for (unsigned int i=0;i<ans.size();++i){
        printf("%d ",ans[i]);
    }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}

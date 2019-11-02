#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, q, a[nmax], b[nmax];
int aiba[nmax], aibb[nmax];
int l1, c1, l2, c2;
int queryy(int a[nmax], int poz){
    int ret=0;
    for (int i=poz;i>=1;i-=(i&(-i)))
        ret+=a[i];
    return ret;
}
void updatee(int a[nmax], int poz, int add){
    for (int i=poz;i<=n;i+=(i&(-i)))
        a[i]+=add;
}
int main()
{
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
        updatee(aiba, i, a[i]%2);
    }
    for (int i=1;i<=n;++i) {
        scanf("%d",&b[i]);
        updatee(aibb, i, b[i]%2);
    }
    for (int i=1;i<=q;++i){
        scanf("%d %d %d %d",&l1,&c1,&l2,&c2);
        if (l1 > l2) swap(l1, l2);
        if (c1 > c2) swap(c1, c2);
        int res1 = queryy(aiba, l2) - queryy(aiba, l1-1);
        int res2 = queryy(aibb, c2) - queryy(aibb, c1-1);
        bool ok1 = (res1 == (l2-l1+1));
        bool ok3 = (!res1);
        bool ok2 = (res2 == (c2-c1+1));
        bool ok4 = (!res2);
        if ((ok1 && ok2) || (ok3 && ok4)){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

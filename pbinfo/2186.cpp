#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
struct lNode{
    lNode *lst, *nxt;
    int val;
    lNode(){
        lst = nxt = 0;
    }
};
int n, c, b, a[nmax], ans;
lNode* rm(lNode* nd){
    if (!nd){
        return NULL;
    }
    if (nd->lst){
        nd->lst->nxt=nd->nxt;
    }
    lNode* ret = nd->nxt;
    if (nd->nxt){
        nd->nxt->lst=nd->lst;
    }
    delete nd;
    return ret;
}
int main()
{
    freopen("barci.in","r",stdin);
    freopen("barci.out","w",stdout);
    scanf("%d %d %d",&n,&c,&b);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1,[](int a, int b){return a>b;});
    lNode* l = new lNode();
    l->val = a[1];
    lNode* ul = l;
    for (int i=2;i<=n;++i){
        lNode *nl = new lNode();
        nl->val = a[i];
        nl->lst = ul;
        ul->nxt = nl;
        ul = nl;
    }
    while (ul->lst && ul->lst->val+l->val <= c) ul=ul->lst;
    while (l){
        if (ul == l){
            ul = ul->nxt;
        }
        while (ul && ul->lst && ul->lst != l && ul->lst->val+l->val <= c) ul = ul->lst;
        if (ul){
            if (ul->val+l->val<=c && abs(ul->val-l->val)<=b){
                ul = rm(ul);
            }
        }
        ++ans;
        lNode* urm = l->nxt;
        rm(l);
        l = urm;
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

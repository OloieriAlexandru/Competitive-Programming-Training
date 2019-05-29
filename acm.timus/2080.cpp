#include <bits/stdc++.h>
#define nmax 100005
#define pii pair<int,int>
#define piii pair<pii,pii>
#define mp make_pair
using namespace std;
bool printed[nmax];
int a[nmax], dv, n, q, lst[nmax], fv[nmax], nt[nmax];
bool stlst[nmax];
vector<piii>queries;
/*
first.first = id query
first.second = ans query
second.first = left query
second.second = right query
*/
int ssqrt(int x)
{
    if (x<=1) return x;
    int d;
    for (d=2; d*d<=x; ++d);
    return d-1;
}
bool cmp1(piii a, piii b)
{
    /*
        Rearrange all queries in a way we will call MO's order. It is defined like this: [L1, R1] comes earlier than [L2, R2] in Mo's order if and only if:
     a) L1/BLOCK_SIZE < L2/BLOCK_SIZE
     b) L1/BLOCK_SIZE == L2/LOCK_SIZE && R1 < R2
    */
    if (a.second.first/dv == b.second.first/dv)
        return a.second.second < b.second.second;
    return ((a.second.first/dv) < (b.second.first/dv));
}
bool cmp2(piii a, piii b)
{
    return a.first.first < b.first.first;
}
int main()
{
    scanf("%d %d",&n,&q);
    for (int i=0; i<q; ++i)
    {
        scanf("%d",&a[i]);
        if (!printed[a[i]])
        {
            printed[a[i]]=true;
            printf("%d ", a[i]);
        }
        if (stlst[a[i]]) nt[lst[a[i]]]=i;
        // am mai gasit elementul a[i] la pozitia lst[a[i]], urmatoarea aparitie a acelei valori in sir este chiar i
        lst[a[i]]=i;
        stlst[a[i]]=true;
    }
    for (int i=1; i<=n; ++i)
        if (!printed[i]) printf("%d ",i);
    printf("\n");
    for (int i=0; i<q; ++i)
        if (!nt[i]) nt[i] = q-1;
    dv = ssqrt(q);
    for (int i=0; i<q; ++i)
        queries.push_back(mp(mp(i,0),mp(i,nt[i])));
    sort(queries.begin(), queries.end(), cmp1);
    int mo_left = 0, mo_right = -1, anss = 0;
    for (int i=0; i<(int)queries.size(); ++i)
    {
        int lft = queries[i].second.first;
        int rgh = queries[i].second.second;
        /*
        Answer all queries following Mo's order. Suppose the next query you want to answer is [L, R]. Then you perform these steps:
        a) while mo_right is less than R, extend current segment to [mo_left, mo_right + 1];
        b) while mo_right is greater than R, cut current segment to [mo_left, mo_right - 1];
        c) while mo_left is greater than L, extend current segment to [mo_left - 1, mo_right];
        d) while mo_left is less than L, cut current segment to [mo_left + 1, mo_right].
        */
        while (mo_right<rgh)
        {
            ++mo_right;
            ++fv[a[mo_right]];
            if (fv[a[mo_right]]==1)
                ++anss;
        }
        while (mo_left<lft)
        {
            --fv[a[mo_left]];
            if (!fv[a[mo_left]])--anss;
            ++mo_left;
        }
        while (mo_left>lft)
        {
            --mo_left;
            ++fv[a[mo_left]];
            if(fv[a[mo_left]]==1)
                ++anss;
        }
        while (mo_right>rgh)
        {
            --fv[a[mo_right]];
            if (!fv[a[mo_right]])--anss;
            --mo_right;
        }
        queries[i].first.second = anss-1;
    }
    sort(queries.begin(), queries.end(), cmp2);
    for (auto x:queries)
        printf("%d\n", x.first.second);
    return 0;
}

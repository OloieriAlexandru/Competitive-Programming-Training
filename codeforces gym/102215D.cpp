#include <bits/stdc++.h>
using namespace std;

class rangeMinimumQuery
{
private:
#define RMQ_CHECK_CREATED(ret) if (!created) return ret
#define RMQ_ERROR 2147483647
#define swp(a,b) (a)^=(b),(b)^=(a),(a)^=b;
#define uint unsigned int
    uint **rmq ,*v;
    bool created;
    uint n, dist, logg2, add;
    uint log2(uint x)
    {
        if (x <= 1) return 0;
        uint ans = 0, p2 = 1;
        while (true)
        {
            if (p2 > x) return ans - 1;
            ++ans, p2 *= 2;
        }
    }
public:
    rangeMinimumQuery(): created(false), rmq(nullptr), v(nullptr) {}
    bool create(uint sz, int a[])
    {
        if (created) return false;
        v = new uint[sz + 1];
        if (v == nullptr) return false;
        for (uint i=0; i<=sz; ++i)
            v[i] = a[i];
        rmq = new uint*[sz + 1];
        if (rmq == nullptr) return false;
        n = sz + 1;
        uint l2 = log2(n) + 1;
        for (uint i=0; i<n; ++i)
        {
            rmq[i] = nullptr;
            rmq[i] = new uint[l2];
            if (rmq[i] == nullptr)
            {
                for (uint j=0; j<i; ++j)
                {
                    delete[] rmq[j];
                }
                delete[] rmq;
                return false;
            }
        }
        for (uint i=1; i<n; ++i)
            rmq[i][0] = i;
        uint shf, secshf;
        for (uint j=1; (1u<<j)<n; ++j)
        {
            shf = 1u<<j;
            for (uint i=1; i+shf-1<n; ++i)
            {
                secshf = 1<<(j-1);
                if (a[rmq[i][j-1]] < a[rmq[i+secshf][j-1]])
                    rmq[i][j] = rmq[i][j-1];
                else
                    rmq[i][j] = rmq[i+secshf][j-1];
            }
        }
        created = true;
        return true;
    }
    int query(uint l, uint r)
    {
        RMQ_CHECK_CREATED(RMQ_ERROR);
        if (l > r) swp(l,r);
        if (r >= n) return RMQ_ERROR;
        dist = r - l + 1;
        logg2 = log2(dist);
        add = dist - (1u<<logg2);
        if (v[rmq[l][logg2]] < v[rmq[l+add][logg2]])
            return v[rmq[l][logg2]];
        return v[rmq[l+add][logg2]];
    }
    uint queryPoz(uint l, uint r)
    {
        RMQ_CHECK_CREATED(RMQ_ERROR);
        if (l > r) swp(l,r);
        if (r >= n) return RMQ_ERROR;
        dist = r - l + 1;
        logg2 = log2(dist);
        add = dist - (1u<<logg2);
        if (v[rmq[l][logg2]] < v[rmq[l+add][logg2]])
            return rmq[l][logg2];
        return rmq[l+add][logg2];
    }
#undef swp
};

class low
{
private:
#define uint unsigned int
#define LCA_CHECK_CREATED(ret) if (!created) return ret
#define LCA_ERROR 4294967295
#define pb push_back
    rangeMinimumQuery rmq;
    std::vector<uint>*tree;
    uint *euler, *firstAppearence, *height;
    uint n, nw, h;
    bool created;
    void dfs(int k, int lst)
    {
        euler[++nw] = k;
        height[nw] = h;
        firstAppearence[k] = nw;
        for (uint i=0; i<tree[k].size(); ++i)
        {
            if (tree[k][i] == lst) continue;
            ++h;
            dfs(tree[k][i],k);
            --h;
            euler[++nw] = k;
            height[nw] = h;
        }
    }
public:
    low(): tree(nullptr), firstAppearence(nullptr), height(nullptr), created(false) {}
    bool create(uint maxNodes)
    {
        if (created) return false;
        n = maxNodes + 1;

        euler = new uint[2 * n];
        if (euler == nullptr)
            return false;
        firstAppearence = new uint[n];
        if (euler == nullptr)
        {
            delete[] euler;
            return false;
        }
        height = new uint[2 * n];
        if (euler == nullptr)
        {
            delete[] euler;
            delete[] firstAppearence;
            return false;
        }
        tree = new std::vector<uint>[n];
        if (tree == nullptr)
        {
            delete[] euler;
            delete[] firstAppearence;
            delete[] height;
            return false;
        }
        created = true;
        return true;
    }
    bool addEdge(uint x, uint y)
    {
        LCA_CHECK_CREATED(false);
        if (x > n || y > n) return false;
        tree[x].pb(y);
        return true;
    }
    bool computeRmq()
    {
        LCA_CHECK_CREATED(false);
        nw = 0, h = 0;
        dfs(1,-1);
        if (!rmq.create(nw, (int*)height))
            return false;
        return true;
    }
    uint query(uint x, uint y)
    {
        LCA_CHECK_CREATED(LCA_ERROR);
        if (x > n || y > n) return false;
        uint l, r;
        l = firstAppearence[x];
        r = firstAppearence[y];
        int pos = rmq.queryPoz(l, r);
        if (pos == RMQ_ERROR)
            return LCA_ERROR;
        return euler[pos];
    }
};
int n, x, y, r, b, q, lc1, lc2, lc3, lc4;
vector<int>as, bs;
int main()
{
    scanf("%d",&n);
    low lca;
    lca.create((unsigned int)n*2);
    for (int i=1; i<n; ++i)
    {
        scanf("%d %d",&x,&y);
        lca.addEdge((uint)x, (uint)y);
        lca.addEdge((uint)y, (uint)x);
    }
    lca.computeRmq();
    scanf("%d",&q);
    for (int i=1; i<=q; ++i)
    {
        scanf("%d %d",&r,&b);
        as.clear();
        bs.clear();
        for (int j=1; j<=r; ++j)
        {
            scanf("%d",&x);
            as.push_back(x);
            if (j == 1)
                lc1 = x;
            else
                lc1 = lca.query(lc1, x);
        }
        for (int j=1; j<=b; ++j)
        {
            scanf("%d",&x);
            bs.push_back(x);
            if (j == 1)
                lc2 = x;
            else
                lc2 = lca.query(lc2, x);
        }
        bool ok = true;

        if (lc1 == lc2) ok = false;

        if (ok)
        {

            lc4 = lca.query(lc1, lc2);
            if (lc4 == lc1)
            {
                for (int j=0; j<as.size() && ok; ++j)
                {
                    lc3 = lca.query(lc2, as[j]);
                    //lc4 = lca.query(lc2, lc1);
                    if (lc3 == lc2)
                    {
                        ok = false;
                        continue;
                    }
                }
            }
            else if (lc4 == lc2)
            {
                for (int j=0; j<bs.size() && ok; ++j)
                {
                    lc3 = lca.query(lc1, bs[j]);
                    if (lc3 == lc1)
                    {
                        ok = false;
                        continue;
                    }
                }
            }
        }
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

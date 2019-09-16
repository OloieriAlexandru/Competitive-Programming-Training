#include <bits/stdc++.h>
#define nmax 100005
#define MAX_QUERIES 50
using namespace std;

class segmentTreeLazy
{
private:
#define left (node<<1)
#define right (node<<1|1)
#define SEG_TREE_LAZY_CHECK_CREATED(ret) if (!created) return ret
#define SEG_TREE_LAZY_ERROR 9223372036854775807LL
#define lld long long
#define uint unsigned int
    lld *aint, *lazy;
    uint n;
    bool created;
    void build(int node, int l, int r, uint* arr)
    {
        if (l == r)
        {
            aint[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(left, l, mid, arr);
        build(right, mid+1, r, arr);
        aint[node] = aint[left]+aint[right];
    }
    void push(int node, int l, int r)
    {
        if (lazy[node])
        {
            lld add = r - l + 1;
            add *= lazy[node];
            if (l != r)
                lazy[left] += lazy[node], lazy[right] += lazy[node];
            aint[node] += add;
            lazy[node] = 0;
        }
    }
    lld query(int node, int l, int r, int x, int y)
    {
        push(node, l, r);
        if (x > r || y < l || l > r) return 0LL;
        if (x <= l && r <= y)
            return aint[node];
        lld res = 0;
        int mid = (l+r)/2;
        res += query(left, l, mid, x, y);
        res += query(right, mid+1, r, x, y);
        return res;
    }
    void update(int node, int l, int r, int x, int y, uint val)
    {
        push(node, l, r);
        if (x > r || y < l || l > r) return;
        if (l == r)
        {
            aint[node] += val;
            return;
        }
        if (x <= l && r <= y)
        {
            lld add = r - l + 1;
            add *= val;
            lazy[left] += val;
            lazy[right] += val;
            aint[node] += add;
            return;
        }
        int mid = (l + r) / 2;
        update(left, l, mid, x, y, val);
        update(right, mid+1, r, x, y, val);
        aint[node] = aint[left]+aint[right];
    }
public:
    segmentTreeLazy(): aint(nullptr), lazy(nullptr), created(false){}
    bool create(uint sz)
    {
        if (created) return false;
        n = sz;
        aint = new lld[4*n+4];
        if (aint == nullptr) return false;
        lazy = new lld[4*n+4];
        if (lazy == nullptr)
        {
            delete[] aint;
            return false;
        }
        uint cnt = 4 * sz + 4;
        for (uint i=0;i<cnt;++i)
            lazy[i] = aint[i] = 0;
        created = true;
        return true;
    }
    bool create(uint sz, uint *arr)
    {
        if (created) return false;
        if (arr == nullptr) return false;
        n = sz;
        aint = new lld[4*n+4];
        if (aint == nullptr) return false;
        lazy = new lld[4*n+4];
        if (lazy == nullptr)
        {
            delete[] aint;
            return false;
        }
        uint cnt = 4 * sz + 4;
        for (uint i=0;i<cnt;++i)
            lazy[i] = aint[i] = 0;
        build(1,1,n,arr);
        created = true;
        return true;
    }
    bool update(uint l, uint r, uint add)
    {
        SEG_TREE_LAZY_CHECK_CREATED(SEG_TREE_LAZY_ERROR);
        if (!l || !r || l > n || r > n || l > r) return SEG_TREE_LAZY_ERROR;
        update(1,1,n,l,r,add);
        return true;
    }
    lld query(uint l, uint r)
    {
        SEG_TREE_LAZY_CHECK_CREATED(SEG_TREE_LAZY_ERROR);
        if (!l || !r || l > n || r > n || l > r) return SEG_TREE_LAZY_ERROR;
        return query(1, 1, n, l, r);
    }
    bool clearMem()
    {
        SEG_TREE_LAZY_CHECK_CREATED(SEG_TREE_LAZY_ERROR);
        if (aint != nullptr)
        {
            delete[] aint;
            aint = nullptr;
        }
        if (lazy != nullptr)
        {
            delete[] lazy;
            lazy = nullptr;
        }
        created = false;
        return true;
    }
};

segmentTreeLazy seg_trees[MAX_QUERIES];

int main()
{
    int t, n, q, type;
    uint x, y, val;
    scanf("%d",&t);
    for (int tt=0;tt<t;++tt)
    {
        scanf("%d %d",&n,&q);
        seg_trees[tt].create(n);
        for (int i=1;i<=q;++i)
        {
            scanf("%d",&type);
            if (type == 0)
            {
                scanf("%u %u %u",&x,&y,&val);
                seg_trees[tt].update(x, y, val);
            }
            else
            {
                scanf("%u %u",&x,&y);
                lld ans = seg_trees[tt].query(x,y);
                printf("%lld\n", ans);
            }
        }
        seg_trees[tt].clearMem();
    }
    return 0;
}

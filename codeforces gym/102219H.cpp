#include <bits/stdc++.h>
#define nmax 50
using namespace std;

class convexHull
{
#define ld long double
#define mp std::make_pair
#define pb push_back
#define uint unsigned int
private:
    struct point
    {
        ld x, y;
        point(ld x, ld y, convexHull *pt)
        {
            this->x = x, this->y = y, this->ptr = pt;
        }
        convexHull *ptr;
        bool operator<(point other) const
        {
            point third = ptr->points[0];
            point me = *this;
            return (ptr->crossProduct(third, me, other) < 0);
        }
        bool isSmaller(point &other)
        {
            return x < other.x || (x == other.x && y < other.y);
        }
    };
    std::vector<point>points;
    ld crossProduct(point a, point b, point c) const
    {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }
    void sortPoints()
    {
        int minPos = 0;
        for (uint i=1; i<points.size(); ++i)
            if (points[i].isSmaller(points[minPos]))
                minPos = i;
        std::swap(points[0], points[minPos]);
        auto it = points.begin();
        ++it;
        sort(it, points.end());
    }
public:
    void addPoint(ld x, ld y)
    {
        points.push_back(point(x, y, this));
    }
    bool getConvexHull(std::vector<std::pair<ld,ld>> &ans)
    {
        if (points.size() < 3) return false;
        ans.clear();
        sortPoints();
        std::stack<point> st;
        st.push(points[0]);
        points.push_back(points[0]);
        for(uint i=1; i<points.size()-1; ++i)
        {
            if (crossProduct(st.top(), points[i], points[i+1]) > 0)
                while (!st.empty())
                {
                    points[i] = st.top();
                    st.pop();
                    if (crossProduct(st.top(), points[i], points[i+1]) <= 0) break;
                }
            st.push(points[i]);
        }
        while (!st.empty())
        {
            ans.pb(mp(st.top().x, st.top().y));
            st.pop();
        }
        return true;
    }
#undef x
#undef y
};
convexHull hulls[nmax];
int n, q, x, y, t;
ld gx, gy;

struct fPoint
{
    ld x, y;
};

float sign (fPoint p1, fPoint p2, fPoint p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle (fPoint pt, fPoint v1, fPoint v2, fPoint v3)
{
    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

int main()
{
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for (int tt=0; tt<t; ++tt)
    {
        scanf("%d %d",&n,&q);
        for (int i=1; i<=n; ++i)
        {
            scanf("%d %d",&x,&y);
            hulls[tt].addPoint(x, y);
        }
        vector<pair<ld,ld>> ch;
        hulls[tt].getConvexHull(ch);
        printf("Case %d\n", tt+1);
        pair<ld,ld> act = ch[0];
        int index = 0;
        for (int i=1; i<ch.size(); ++i)
            if (ch[i] < act)
                act = ch[i], index = i;
        for (int i=index; i<ch.size(); ++i)
            cout<<ch[i].first<<' '<<ch[i].second<<'\n';
        for (int i=0; i<=index; ++i)
            cout<<ch[i].first<<' '<<ch[i].second<<'\n';
        gx = 0, gy = 0;
        for (auto x:ch)
        {
            gx += x.first;
            gy += x.second;
        }
        gx /= ch.size();
        gy /= ch.size();
        ch.push_back(ch[0]);
        fPoint g;
        g.x = gx;
        g.y = gy;
        for (int i=1; i<=q; ++i)
        {
            scanf("%d %d",&x,&y);
            fPoint f;
            f.x = x;
            f.y = y;
            bool ok = false;
            for (int j=0; j<ch.size()-1&&!ok; ++j)
            {
                fPoint f1, f2;
                f1.x = ch[j].first;
                f1.y = ch[j].second;
                f2.x = ch[j+1].first;
                f2.y = ch[j+1].second;
                if (PointInTriangle(f, g, f1, f2))
                    ok = true;
            }
            if (!ok)
                printf("%d %d is safe!\n", x, y);
            else
                printf("%d %d is unsafe!\n", x, y);
        }
        cout<<'\n';
    }
    return 0;
}

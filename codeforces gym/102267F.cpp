#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <cmath>
#include <ostream>
#define pb push_back
#define ld long double
#define nmax 3005
#define PI 3.1415926535
#define eps 1e-7
using namespace std;
vector<int>g[nmax];
int n, x, y, a, r;
struct fighter{
    int x, y, a, r;

    fighter(int x, int y, int a, int r){
        this->x = x;
        this->y = y;
        this->a = a;
        this->r = r;
    }

    friend ostream& operator<<(ostream& out, const fighter f){
        out<<f.x<<' '<<f.y<<' ';
        return out;
    }
};
vector<fighter> fighters;
int di[nmax], ans[nmax];

ld dist(const fighter& a, const fighter& b){
    ld x1, x2, y1, y2;
    x1 = a.x;
    x2 = b.x;
    y1 = a.y;
    y2 = b.y;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

ld getU(ld x){
    return x * 360.0 / (2 * PI);
}

bool inter(const fighter& a, const fighter& b){

    ld va = dist(a, b);
    ld vb = b.y - a.y;

    //cout<<va<<' '<<vb<<'\n';

    ld u = asin(vb/va);
    ld vu = getU(u);

    if (b.x < a.x){
        vu = 180.0 - vu;
    }
    if (vu < 0){
        vu = 360.0 + vu;
    }

    //cout<<a<<b<<' '<<vu<<' ';

    ld u1 = a.a-a.r;
    ld u2 = a.a+a.r;
    //cout<<u1<<' '<<u2<<' '<<a.a<<' '<<r<<'\n';
    if (vu-u1 >-eps && u2-vu >-eps){
        return true;
    }

    if (u1 < 0 && vu-(u1 + 360.0) >-eps){
        return true;
    }

    if (u2 - 360.0 > -eps && u2 - 360.0 -vu >-eps){
        return true;
    }

    return false;
}

int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y>>a>>r;
        fighters.emplace_back(x,y,a,r);
    }

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            if (i == j){
                continue;
            }
            if (inter(fighters[i],fighters[j])){
                ++di[j];
                g[i].pb(j);
            }
        }
    }

    queue<int>q;
    for (int i=0;i<n;++i){
        if (!di[i]){
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty()){
        auto act = q.front();
        q.pop();
        ++cnt;
        ans[cnt] = act;
        for (int i=0;i<g[act].size();++i){
            --di[g[act][i]];
            if (!di[g[act][i]]){
                q.push(g[act][i]);
            }
        }
    }
    if (cnt == n){
        for (int i=1;i<=n;++i){
            cout<<ans[i]+1<<' ';
        }
        cout<<'\n';
    } else {
        cout<<"-1\n";
    }
    return 0;
}

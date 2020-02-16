#include <bits/stdc++.h>
#define nmax 77
#define inf 999999999.0
using namespace std;
int n, m, k, x, y, xs, ys, ndc;
long double vel, cmin[nmax*nmax], ans;
char a[nmax][nmax];
bool inqueue[nmax*nmax];
vector<pair<int,double>>g[nmax*nmax];
vector<pair<int,int>>v;

int dl[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
int dld[] = {-1,1,1,-1};
int dcd[] = {1,1,-1,-1};

bool interior(int i, int j){
    return i>=1&&j>=1&&i<=n&&j<=m;
}

int pairToNode(int x, int y){
    return (x-1) * m + y;
}

void addEdges(int x1, int y1, int x2, int y2, double value){
    int node1 = pairToNode(x1, y1);
    int node2 = pairToNode(x2, y2);
    g[node1].push_back(make_pair(node2, value));
}

void createGraph() {
    double s2 = sqrt(2.0);
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            for (int k=0;k<4;++k){
                if (!interior(i+dl[k],j+dc[k])){
                    continue;
                }
                if (a[i+dl[k]][j+dc[k]] == '#'){
                    continue;
                }
                addEdges(i, j, i+dl[k], j+dc[k], 1.0);
            }
            for (int k=0;k<4;++k){
                if (!interior(i+dld[k],j+dcd[k])){
                    continue;
                }
                if (a[i+dld[k]][j+dcd[k]] == '#'){
                    continue;
                }
                addEdges(i, j, i+dld[k], j+dcd[k], s2);
            }
        }
    }
}

void bellmanFord(int start) {
    for (int i=1;i<=ndc;++i){
        cmin[i] = inf;
    }
    cmin[start] = 0.0;
    queue<int>q;
    q.push(start);
    inqueue[start] = true;
    while (!q.empty()){
        auto act = q.front();
        inqueue[act] = false;
        q.pop();
        for (auto x:g[act]){
            if (cmin[x.first] > cmin[act] + x.second){
                cmin[x.first] = cmin[act] + x.second;
                if (!inqueue[x.first]){
                    q.push(x.first);
                    inqueue[x.first] = true;
                }
            }
        }
    }
}

int main() {
    cin>>m>>n>>k>>vel;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>a[i][j];
        }
    }
    ndc = n * m;
    createGraph();
    cin>>xs>>ys;
    swap(xs,ys);
    for (int i=1;i<=k;++i){
        cin>>x>>y;
        swap(x,y);
        v.push_back(make_pair(x,y));
    }
    x = xs;
    y = ys;
    for (int i=0;i<v.size();++i) {
        int node1 = pairToNode(x, y);
        int node2 = pairToNode(v[i].first, v[i].second);
        bellmanFord(node1);
        if (abs(cmin[node2] - inf) < 0.00006){
            continue;
        }
        ans += cmin[node2];
        x = v[i].first;
        y = v[i].second;
    }
    ans = ans / vel;
    cout<<setprecision(2)<<fixed<<ans<<'\n';
    return 0;
}

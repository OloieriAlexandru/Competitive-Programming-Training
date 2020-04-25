#include <bits/stdc++.h>
#define pii pair<int,int>
#define nmax 5005
using namespace std;
const int inf = 1e9;
int n, x, y, d1, d2;
int p, s, c, best, worst, add, sub;
int poz[nmax], pozAfterSort[nmax], versus[nmax], p1, p2;
struct player{
    int p, s, c;
    int index;
    player(int p, int s, int c, int index){
        this->p = p;
        this->s = s;
        this->c = c;
        this->index = index;
    }
};
vector<player>players;
vector<player>cp;
vector<pii>v;
vector<pair<int,pii>>ans;
bool cmp(const player& p1, const player& p2){
    if (p1.p == p2.p){
        int d1 = p1.s - p1.c;
        int d2 = p2.s - p2.c;
        if (d1 == d2) {
            return p1.s > p2.s;
        }
        return d1 > d2;
    }
    return p1.p > p2.p;
}
void insertLeft(int poz){
    int swapPos = poz;
    player init = cp[poz];
    for (int i=poz;i>0;--i){
        if (cmp(init, cp[i-1])) {
            cp[i] = cp[i-1];
            swapPos = i-1;
        } else {
            break;
        }
    }
    if (swapPos != poz){
        cp[swapPos] = init;
    }
}
void insertRight(int poz) {
    int swapPos = poz;
    player init = cp[poz];
    for (int i=poz;i<n-1;++i){
        if (cmp(cp[i+1], init)){
            cp[i] = cp[i+1];
            swapPos = i + 1;
        } else {
            break;
        }
    }
    if (swapPos != poz){
        cp[swapPos] = init;
    }
}
int main()
{
    scanf("%d",&n);
    int nn = n / 2;
    for (int i=1;i<=nn;++i){
        scanf("%d %d",&x,&y);
        --x, --y;
        versus[x] = y;
        versus[y] = x;
        v.push_back(make_pair(x,y));
    }
    for (int i=1;i<=n;++i){
        scanf("%d %d %d",&p,&s,&c);
        players.emplace_back(p, s, c, i-1);
    }
    sort(players.begin(), players.end(), cmp);
    for (int i=0;i<n;++i){
        pozAfterSort[players[i].index] = i;
    }
    for (int i=0;i<n;++i){
        int oldI = i;
        i = players[i].index;
        cp = players;
        y = pozAfterSort[versus[i]];

        cp[pozAfterSort[i]].p += 3;
        cp[pozAfterSort[i]].s += inf;
        cp[y].c += inf;
        if (y < pozAfterSort[i] && cmp(players[pozAfterSort[i]], players[y])){
            ++y;
        }
        insertLeft(pozAfterSort[i]);
        insertRight(y);

        for (int j=0;j<n;++j){
            poz[cp[j].index] = j;
        }

        add = 0;
        best = poz[i];

        for (auto x : v){
            if (x.first == i || x.second == i){
                continue;
            }
            p1 = poz[x.first];
            p2 = poz[x.second];
            if (p1 > best && p2 > best){
                d1 = cp[poz[i]].p - cp[p1].p;
                d2 = cp[poz[i]].p - cp[p2].p;
                if (!d1) {
                    if (d2 < 3){
                        ++add;
                    }
                } else if (!d2) {
                    if (d1 < 3){
                        ++add;
                    }
                }
            }
        }

        y = pozAfterSort[versus[i]];
        cp = players;
        cp[y].p += 3;
        cp[y].s += inf;
        cp[pozAfterSort[i]].c += inf;
        int newPos = pozAfterSort[i];
        if (newPos < y && cmp(players[y], players[newPos])){
            ++newPos;
        }
        insertLeft(y);
        insertRight(newPos);

        for (int j=0;j<n;++j){
            poz[cp[j].index] = j;
        }
        worst = poz[i];
        sub = 0;

        for (auto x : v){
            if (x.first == i || x.second == i){
                continue;
            }
            p1 = poz[x.first];
            p2 = poz[x.second];
            if (p1 > worst && p2 > worst){
                d1 = cp[poz[i]].p - cp[p1].p;
                d2 = cp[poz[i]].p - cp[p2].p;
                if (!d1) {
                    if (d2 <= 3) {
                        sub += 2;
                    } else {
                        ++sub;
                    }
                } else if (!d2) {
                    if (d1 <= 3){
                        sub += 2;
                    } else {
                        ++sub;
                    }
                } else if (d1 == 1 && d2 == 1){
                    sub += 2;
                } else if (d1 <= 3 || d2 <= 3){
                    ++sub;
                }
            } else if (p1 > worst && p2 < worst){
                d1 = cp[poz[i]].p - cp[p1].p;
                if (d1 <= 3){
                    ++sub;
                }
            } else if (p2 > worst && p1 < worst) {
                d2 = cp[poz[i]].p - cp[p2].p;
                if (d2 <= 3){
                    ++sub;
                }
            }
        }

        ans.push_back({i, {best+add+1, worst+sub+1}});
        i = oldI;
    }
    sort(ans.begin(), ans.end());
    for (auto x:ans){
        printf("%d %d\n", x.second.first, x.second.second);
    }
    return 0;
}


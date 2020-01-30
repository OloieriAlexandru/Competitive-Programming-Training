#include <bits/stdc++.h>
#define nmax 100005
#define mkp make_pair
using namespace std;
int n, fv[nmax], a, b, c, lsta, lstb;
map<pair<int,int>,vector<int>>mp;
void add(int a, int b, int c){
    if (a > b){
        swap(a,b);
    }
    mp[mkp(a,b)].push_back(c);
}
void rem(int a, int b, int c){
    if (a > b){
        swap(a,b);
    }
    int poz = -1;
    for (int i=0;i<mp[mkp(a,b)].size();++i){
        if (mp[mkp(a,b)][i]==c){
            poz=i;
            break;
        }
    }
    if (poz != -1){
        mp[mkp(a,b)].erase(mp[mkp(a,b)].begin()+poz);
    }
}
int getLast(int a, int b){
    if (a > b){
        swap(a,b);
    }
    int ret = mp[mkp(a,b)].back();
    rem(a,b,ret);
    rem(a,ret,b);
    rem(ret,b,a);
    return ret;
}
bool exists(int a, int b){
    if (a > b){
        swap(a,b);
    }
    return mp.count(mkp(a,b));
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n-2;++i){
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
        add(b,c,a);
        add(a,c,b);
        ++fv[a];
        ++fv[b];
        ++fv[c];
    }
    vector<int>fv1,fv2;
    for (int i=1;i<=n;++i){
        if (fv[i]%3==1){
            fv1.push_back(i);
        }
        if (fv[i]%3==2){
            fv2.push_back(i);
        }
    }
    bool ok=false;
    for (auto x:fv1){
        for (auto y:fv2){
            if (exists(x,y)){
                lsta=x;
                lstb=y;
                ok=true;
                break;
            }
        }
        if (ok){
            break;
        }
    }
    cout<<lsta<<' '<<lstb<<' ';
    for (int i=3;i<=n;++i){
        int nw = getLast(lsta,lstb);
        lsta=lstb;
        lstb=nw;
        cout<<nw<<' ';
    }
    cout<<'\n';
    return 0;
}

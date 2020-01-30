#include <bits/stdc++.h>
#define nmax 100005
using namespace std;
int n, x, maxx, ans[nmax];
bool used[nmax];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>maxx;
        memset(used,0,sizeof(used));
        ans[1] = maxx;
        bool ok = true;
        used[ans[1]]=true;
        int act = 1;
        for (int i=2;i<=n;++i){
            cin>>x;
            if (!ok){
                continue;
            }
            if (x != maxx){
                if (x < maxx){
                    ok = false;
                    continue;
                }
                maxx = x;
                used[maxx] = true;
                ans[i] = maxx;
                continue;
            } else {
                while (used[act]) ++act;
                if (act > maxx){
                    ok = false;
                    continue;
                }
                used[act] = true;
                ans[i] = act;
            }
        }
        if (!ok){
            cout<<"-1\n";
            continue;
        }
        for (int i=1;i<=n;++i){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}

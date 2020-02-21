#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 30002
#define nmax2 15005
#define lld long long
#define ld long double
#define pb push_back
using namespace std;

bool pprim[nmax],ciur[nmax];
int n, p, k, a[nmax2];
vector< pii > ans;
vector< int > primes;

void erath() {
    for (int i=2;i<=30000;++i){
        if (ciur[i]){
            continue;
        }
        primes.push_back(i);
        for (int j=i*i;j<=30000;j+=i){
            ciur[j]=true;
        }
    }
}

void precalc() {
    int act = 1;
    while (true){
        if (act > 30000){
            break;
        }
        pprim[act] = true;
        for (int i=0;i<primes.size();++i){
            lld x = 1LL * primes[i] * act;
            if (x > 30000){
                break;
            }
            pprim[x] = true;
        }
        act *= p;
    }
}

int main()
{
    freopen("secvente1.in","r",stdin);
    freopen("secvente1.out","w",stdout);

    erath();

    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&p,&k);

        ans.clear();
        memset(pprim,0,sizeof(pprim));
        precalc();
        pprim[1] = 0;

        for (int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }

        int l=-1,r=1,cnt=0;
        while (r <= n && cnt < k){
            if (pprim[a[r]]){
                if (l == -1){
                    l = r;
                }
                ++cnt;
                if (cnt == k){
                    break;
                }
            }
            ++r;
        }
        if (r <= n && cnt == k){
            while (r<=n){
                ans.push_back(make_pair(l,r));
                ++l;
                while (!pprim[a[l]]){
                    ++l;
                }
                ++r;
                while (r<=n&&!pprim[a[r]]){
                    ++r;
                }
            }
        }

        printf("%u\n",ans.size());
        for (unsigned int i=0;i<ans.size();++i){
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

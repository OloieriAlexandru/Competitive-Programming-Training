#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 1005
using namespace std;
int a[nmax], b[nmax], n, ans, rm;
vector<pii >t;
bool cmp(const pii & a, const pii & b){
    return a.second < b.second;
}
int main()
{
    freopen("eoliene.in","r",stdin);
    freopen("eoliene.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n;++i){
        cin>>b[i];
        t.pb(mp(a[i]-b[i],a[i]+b[i]));
    }
    sort(t.begin(),t.end(),cmp);
    int l = -100000;
    for (int i=0;i<n;++i){
        if (t[i].first > l){
            l = t[i].second;
            ++rm;
        }
    }
    ans = n-rm;
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}


/*
26 feb 2015, 11:27
70 puncte

#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("eoliene.in");
ofstream fout("eoliene.out");
struct obiect
{
    int D;
    int L;
};obiect eol[1001];
int criteriu (obiect a,obiect b)
              {if (a.D<=b.D)
                   return 1;
               return 0;}
int n,i,elim,ii;
int main()
{
fin>>n;
for (i=1;i<=n;i++)
    fin>>eol[i].D;
for (i=1;i<=n;i++)
     fin>>eol[i].L;
sort (eol+1,eol+n+1,criteriu);
for (i=1;i<n;i++)
    {ii=i;
     if (eol[i+1].D-eol[ii].D<=eol[ii].L+eol[i+1].L)
         while (eol[i+1].D-eol[ii].D<=eol[ii].L+eol[i+1].L&&i<n)
               {elim++;i++;}}
fout<<elim<<"\n";
fin.close();
fout.close();
return 0;
}
*/

#include <bits/stdc++.h>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 100005
#define inf 1000000000000000LL
using namespace std;
int n, x, ans1, ans2, l, r;
lld s[nmax], ans = inf, diff;
vector<pair<long long,int> >v;
int main()
{
    freopen("suma3.in","r",stdin);
    freopen("suma3.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&x);
        s[i] = s[i-1] + x;
        v.push_back(mp(s[i],i));
    }
    v.push_back(make_pair(0,0));
    sort(v.begin(),v.end());
    for (int i=0;i<n-1;++i){
        l = v[i].second, r = v[i+1].second;
        if (l > r){
            swap(l,r);
        }
        diff = s[r]-s[l];
        if (diff < 0){
            diff = -diff;
        }
        if (diff < ans){
            ans = diff;
            ans1 = l+1, ans2 = r;
        }
    }
    printf("%lld %d %d\n",ans,ans1,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
8 dec 2016, 10:24
0 puncte

#include <fstream>
#include <cstdlib>
#define LMAX 50005

using namespace std;
ifstream fin("suma3.in");
ofstream fout("suma3.out");

long long int sf, in;
long long int sfarsit, inceput, smax=999999999999;
long long int n, k;
long long int a[LMAX], s[LMAX];

void citire();
void afisare();
void pd();

int main()
{
citire();
pd();
afisare();
fout.close();
fin.close();
return 0;
}

void citire()
    {
     int i;
     fin>>n;
     for (i=1;i<=n;i++)
         {
          fin>>a[i];
          s[i]=a[i]+s[i-1];
         }
    }

void afisare()
    {
     fout<<smax<<' '<<inceput<<' '<<sfarsit<<'\n';
    }

void pd()
    {
     inceput=1;
     for (sf=n, in=1;sf<=n;sf++,in++)
         {
         if (s[in-1]<s[inceput-1])
             inceput=in;
         if (abs(s[sf]-s[inceput-1])<smax)
             {
             smax=abs(s[sf]-s[inceput-1]);
             sfarsit=sf;
             }
         }
    }
*/

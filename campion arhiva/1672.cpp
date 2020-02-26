#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 1005
using namespace std;
vector< pii > ans;
vector < pair<string,int> > v;
string s;
int n, p[nmax], a[nmax];
int main()
{
    freopen("sort2dist.in","r",stdin);
    freopen("sort2dist.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        reverse(s.begin(),s.end());
        while (s.size()<31){
            s.push_back('0');
        }
        reverse(s.begin(),s.end());
        v.push_back(mp(s,i));
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();++i){
        p[i+1]=v[i].second;
        a[v[i].second] = i+1;
    }
    for (int i=n;i>=1;--i){
        if (i == p[i]){
            continue;
        }
        int poz = p[i], dist = i-p[i];
        for (int j=0;j<10;++j){
            if (dist&(1<<j)){
                p[a[poz+(1<<j)]]=poz;
                a[poz]=a[poz+(1<<j)];
                ans.push_back(make_pair(poz,poz+(1<<j)));
                poz=poz+(1<<j);
            }
        }
    }
    printf("%u\n",ans.size());
    for (unsigned int i=0;i<ans.size();++i){
        printf("%d %d\n",ans[i].first, ans[i].second);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
19 oct 2016, 23:18
4 puncte

#include <fstream>
#include <algorithm>
#define LMAX 1005

using namespace std;
ifstream fin("sort2dist.in");
ofstream fout("sort2dist.out");

struct mutare{
    int plecare;
    int sosire;
};mutare m[LMAX*10];

int a[LMAX], s[LMAX];
int nrm;
int n;

void sortare();
void citire();
void afisare();
void sortare();
void rezolvare();
bool corect(int a);

int main()
{
citire();
sortare();
rezolvare();
afisare();
fin.close();
fout.close();
return 0;
}

void rezolvare()
    {
     int i, j, ok=0;
     while (!ok)
         {ok=1;
         for (i=n;i>=1;i--)
              if (s[i]!=a[i])
                  {
                   ok=0;
                   nrm++;
                   for (j=1;j<=n;j++)
                        if (s[i]==a[j])
                            if (corect(i-j))
                                {m[nrm].sosire=i, m[nrm].plecare=j;
                                swap(a[i],a[j]);break;}
                  }}
    }

bool corect(int a)
    {
     while (a>1&&a%2==0)
        {
         a=a/2;
        }
     if (a==1) return 1;
     return 0;
    }

void afisare()
    {
     int i;
     fout<<nrm<<'\n';
     for (i=1;i<=nrm;i++)
          fout<<m[i].plecare<<' '<<m[i].sosire<<'\n';
    }

void sortare()
    {
     sort (s+1,s+n+1);
    }

void citire()
    {
     int i;
     fin>>n;
     for (i=1;i<=n;i++)
          {fin>>a[i];
           s[i]=a[i];}
    }
*/

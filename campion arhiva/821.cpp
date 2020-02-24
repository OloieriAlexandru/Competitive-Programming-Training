#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 4002
using namespace std;

int n, nr, ans1, ans2, ii;
string s, cs;
vector<pair<string,string> >v[nmax];

int main()
{
    freopen("pluton.in","r",stdin);
    freopen("pluton.out","w",stdout);

    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        cs = s;
        sort(cs.begin(),cs.end());
        bool ok = false;
        for (int j=1;j<=nr;++j){
            if (v[j][0].second == cs){
                v[j].push_back(make_pair(s,cs));
                if (v[j].size() > ans1){
                    ans1 = v[j].size();
                    ans2 = 1;
                    ii = j;
                } else if (v[j].size() == ans1){
                    ++ans2;
                }
                ok = true;
                break;
            }
        }
        if (ok){
            continue;
        }
        ++nr;
        v[nr].push_back(make_pair(s,cs));
        if (v[nr].size() > ans1){
            ans1 = v[nr].size();
            ans2 = 1;
            ii = nr;
        } else if (v[nr].size() == ans1){
            ++ans2;
        }
    }
    printf("%d\n%d\n%d\n",nr,ans1,ans2);
    for (int i=0;i<v[ii].size();++i){
        cout<<v[ii][i].first<<' ';
    }
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
1 dec 2016, 18:31
83 puncte

#include <fstream>
#include <algorithm>
#define LMAX 4002
#define LMAX2 10

using namespace std;
ifstream fin("pluton.in");
ofstream fout("pluton.out");

struct pluton{
    short int frecventa[LMAX2];
    short int soldati[50];
    short int nr;
};pluton p[4000];

short int n, nrp;
short int f[LMAX2];

void citire();
void interpretez(int a);
void scot_frecv(int a);
void adaug(int nr, int x, int decid);
void afisez2();
void afisare();
void sortare();

short int calculez();

bool sepotriveste(int nr);
bool criteriu(pluton a, pluton b);

int main()
{
citire();
sortare();
afisare();
fin.close();
fout.close();
return 0;
}

short int calculez()
    {
     int i;
     int eg=p[1].nr;
     for (i=2;;i++)
          if (p[i].nr!=eg) break;
     return i-1;
    }

void afisare()
    {
     int af1=nrp;
     int af2=p[1].nr;
     int af3=calculez();
     fout<<af1<<'\n';
     fout<<af2<<'\n';
     fout<<af3<<'\n';
     afisez2();
    }

void afisez2()
    {
     int i;
     for (i=1;i<=p[1].nr;i++)
          fout<<p[1].soldati[i]<<' ';
     fout<<'\n';
    }

void sortare()
    {
     sort (p+1,p+nrp+1,criteriu);
    }

void citire()
    {
     int i, a;
     fin>>n;
     for (i=1;i<=n;i++)
         {
          fin>>a;
          interpretez(a);
         }
    }

void scot_frecv(int a)
    {
     while (a>0)
         {
          f[a%10]++;
          a=a/10;
         }
    }

void p0()
    {
     int i;
     for (i=0;i<=9;i++)
          f[i]=0;
    }

void interpretez(int a)
    {
     int i;
     p0();
     scot_frecv(a);
     for (i=1;i<=nrp;i++)
          if (sepotriveste(i))
              {
               adaug(i,a,0);
               return ;
              }
     nrp++;
     adaug(nrp,a,1);
    }

bool sepotriveste(int nr)
    {
     int i;
     for (i=0;i<=9;i++)
          if (p[nr].frecventa[i]!=f[i])
              return 0;
     return 1;
    }

void adaug(int nr, int x, int decid)
    {
     int i;
     p[nr].nr++;
     p[nr].soldati[p[nr].nr]=x;
     if (!decid)
         return;
     for (i=0;i<=9;i++)
         p[nr].frecventa[i]=f[i];
    }

bool criteriu(pluton a, pluton b)
    {
     return a.nr>b.nr;
    }
*/

#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 35
using namespace std;
int v1[nmax], v2[nmax], v3[nmax];
int ans1, ans2, ans3, calc[nmax];
int main()
{
    freopen("becuri2.in","r",stdin);
    freopen("becuri2.out","w",stdout);
    int n, a, b;
    cin>>n>>a>>b;
    for (int i=1;i<=n;++i){
        v1[i] = a%2;
        a/=2;
        v2[i] = b%2;
        b/=2;
        v3[i] = (v1[i] && v2[i]);
        if (v1[i] && !v2[i]){
            ++ans1;
        }
        if (!v1[i] && v2[i]){
            ++ans2;
        }
        if (!v3[i]){
            calc[i] = 0;
        } else {
            calc[i] = calc[i-1] + 1;
        }
        ans3 = max(ans3, calc[i]);
    }
    cout<<ans1<<' '<<ans2<<' '<<ans3<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
10 dec 2016, 12:01
70 puncte

#include <fstream>
#define LMAX 32

using namespace std;
ifstream fin("becuri2.in");
ofstream fout("becuri2.out");

bool r1[LMAX];
bool r2[LMAX];
int r3[LMAX];

int n, a, b;

void citire();
void tbin(int a, bool r[]);
void afisare();
int c1();
int c2();
int c3();

int main()
{
citire();
afisare();
fin.close();
fout.close();
return 0;
}

void citire()
    {
     fin>>n;
     fin>>a;fin>>b;
     tbin(a, r1);tbin(b, r2);
    }

void tbin(int a, bool r[])
    {
     int i=0;
     for (i=0;i<n;i++)
          {r[i]=a%2;
           a=a/2;}
    }

void afisare()
    {
     fout<<c1()<<' '<<c2()<<' '<<c3()<<'\n';
    }

int c1()
    {
     int i, c=0;
     for (i=0;i<n;i++)
          if (r1[i]&&!r2[i])
              c++;
     return c;
    }

int c2()
    {
     int i, c=0;
     for (i=0;i<n;i++)
          if (!r1[i]&&r2[i])
              c++;
     return c;
    }

int c3()
    {
     int i, c=0, lg;
     for (i=0;i<n;i++)
          if (r1[i]&&r2[i])
              r3[i]=2;
     if (r3[0]==2)
         lg=1;
         else lg=0;
     for (i=1;i<n;i++)
          if (r3[i]==2)
              lg++;
              else
              {
               if (lg>c)
                   c=lg;
               lg=0;
              }
     return c;
    }
*/

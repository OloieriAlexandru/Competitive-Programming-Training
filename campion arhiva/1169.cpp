#include <fstream>

using namespace std;
ifstream fin ("atelier.in");
ofstream fout ("atelier.out");

int a[10005];
int b[10005];

int main()
{
    int i, n, maxim=0, var=0, zi=0;
    char c;
    fin>>n>>a[0]>>b[0];
    for (i=1; i<n; i++){
        fin>>a[i]>>b[i];
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    for (i=0; i<n-1; i++){
       var=a[i]+b[n-1]-b[i];
        if (maxim<=var){
            maxim=var;
            c='A';
            zi=i+1;
        }
    }
    for (i=0; i<n-1; i++){
       var=b[i]+a[n-1]-a[i];
        if (maxim<var){
            maxim=var;
            c='B';
            zi=i+1;
        }
    }
    fout<<maxim<<'\n'<<c<<'\n'<<zi;
    return 0;
}

/*
#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 10005
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
int n, a[nmax], b[nmax], sa[nmax], sb[nmax];
int ans1, ans3;
char ans2;
void check(int v1[nmax], int v2[nmax], char cv){
    int s1, s2;
    for (int i=n;--i){
        s1 = v1[i];
        s2 = v2[n]-v2[i];
        if (s1+s2>=ans1){
            ans1=s1+s2;
            ans2=cv;
            ans3=i;
        }
    }
}
int main()
{
    freopen("atelier.in","r",stdin);
    freopen("atelier.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d %d",&a[i],&b[i]);
        sa[i]=sa[i-1]+a[i];
        sb[i]=sb[i-1]+b[i];
    }
    check(sb,sa,'B');
    check(sa,sb,'A');
    printf("%d\n%c\n%d\n",ans1,ans2,ans3);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

13 dec 2016, 23:07
80 puncte

#include <fstream>
#define LMAX 10002

using namespace std;
ifstream fin("atelier.in");
ofstream fout("atelier.out");

int n;
int a[LMAX];
int b[LMAX];
int sa[LMAX];
int sb[LMAX];
int smax;
int zm;
int pers;

void citire();
void afisare();
void rezolvare();

int maxim(int v1[], int v2[],int& lucr);

int main()
{
citire();
rezolvare();
afisare();
fin.close();
fout.close();
return 0;
}

void citire()
    {
     int i;
     int x, y;
     fin>>n;
     for (i=1;i<=n;i++)
        {
         fin>>x>>y;
         a[i]=x;b[i]=y;
         sa[i]=sa[i-1]+x;
         sb[i]=sb[i-1]+y;
        }
    }

void rezolvare()
    {
     int v, z2;
     smax=maxim(sa,sb,zm);
     pers=1;
     v=maxim(sb,sa,z2);
     if (v>smax)
        {
         pers=2;
         zm=z2;
         smax=v;
        }
    }

void afisare()
    {
     fout<<smax<<'\n';
     if (pers==1)
         fout<<"A\n";
         else
         fout<<"B\n";
     fout<<zm<<'\n';
     }

int maxim(int v1[], int v2[],int& lucr)
    {
     int i, smax=0;
     for (i=1;i<n;i++)
          if (v1[i]+v2[n]-v2[i]>=smax)
              {smax=v1[i]+v2[n]-v2[i];
               lucr=i;}
     return smax;
    }
*/

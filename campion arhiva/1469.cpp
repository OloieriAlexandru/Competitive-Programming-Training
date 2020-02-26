#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 1005
using namespace std;
int n, r, x, fv[nmax];
struct mare{
    char cif[205];
    int len;
    mare(){
        memset(cif,0,sizeof(cif));
        len=1;
    }
    mare& operator*=(int x){
        int t = 0, v;
        for (int i=0;i<len;++i){
            v = t + x*cif[i];
            cif[i] = v%10;
            t=v/10;
        }
        while (t){
            cif[len++]=t%10, t/=10;
        }
        return *this;
    }
    mare& operator+=(int x){
        int t =0, v, i;
        for (i=0;i<len||x;++i){
            v=x%10+cif[i]+t;
            x/=10;
            cif[i]=v%10;
            t=v/10;
        }
        len=i;
        if (t){
            cif[len++]=1;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& out, const mare & m){
        for (int i=m.len-1;i>=0;--i){
            out<<(int)m.cif[i];
        }
        return out;
    }
};
mare ans;
int main()
{
    freopen("minm.in","r",stdin);
    freopen("minm.out","w",stdout);
    cin>>r>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        int fvv=0, cx=x;
        while (cx%2==0){
            cx/=2;
            ++fvv;
        }
        fv[2] = max(fv[2],fvv);
        for (int d=3;d*d<=x;d+=2){
            if (cx%d){
                continue;
            }
            fvv=0;
            while(cx%d==0){
                cx/=d;
                ++fvv;
            }
            fv[d]=max(fv[d],fvv);
        }
        if (cx > 1){
            fv[cx]=max(fv[cx],1);
        }
    }
    ans += 1;
    for (int i=2;i<=1000;++i){
        for (int j=1;j<=fv[i];++j){
            ans *= i;
        }
    }
    ans += r;
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
7 feb 2017, 22:01
80 puncte

#include <fstream>
#define LMAX1 205
#define LMAX2 1005

using namespace std;
ifstream fin("minm.in");
ofstream fout("minm.out");

typedef short int NrMare[LMAX1];
NrMare a, b;
int lga, lgb;

int fp[LMAX2];
int n, r;

void citire();
void calculare();
void afisare(NrMare a, int lga);
void imp_f_p(int x);
void transf(int x, NrMare a, int& lga);
void suma(NrMare a, int lga, NrMare b, int lgb, NrMare c, int&lgc);
void produsc(NrMare a, int lga, int x, NrMare b, int& lgb);
void pune0(NrMare a ,int lga);

int main()
{
citire();
calculare();
afisare(a, lga);
fin.close();
fout.close();
return 0;
}

void afisare(NrMare a, int lga)
    {
     int i;
     for (i=lga-1;i>=0;i--)
          fout<<a[i];
     fout<<'\n';
    }

void citire()
    {
     int i;
     int a;
     fin>>r;
     fin>>n;
     for (i=1;i<=n;i++)
         {
          fin>>a;
          imp_f_p(a);
         }
    }

void imp_f_p(int x)
    {
     int d=2;
     int nr;
     while (x>1&&d<=1000)
         {
          nr=0;
          while (x%d==0)
                {
                 nr++;
                 x=x/d;
                }
          if (fp[d]<nr)
              fp[d]=nr;
          d++;
         }
    }

void calculare()
    {
     int i;
     a[0]=1;
     lga=1;
     for (i=1;i<=1000;i++)
          while (fp[i]>0)
                 {
                  fp[i]--;
                  produsc(a, lga, i ,a, lga);
                 }
     transf(r, b, lgb);
     suma(a, lga, b, lgb, a, lga);
    }

void transf(int x, NrMare a, int& lga)
    {
     int lg=0, cx=x;
     int i;
     while (cx>0)
         cx=cx/10, lg++;
     lga=lg;
     for (i=0;i<lg;i++)
          a[i]=x%10, x=x/10;
    }

void suma(NrMare a, int lga, NrMare b, int lgb, NrMare c, int&lgc)
    {
     int i, v, t=0;
     pune0(a, lga);
     pune0(b, lgb);
     if (lga>lgb)
         lgc=lga;
         else
         lgc=lgb;
     for (i=0;i<lgc;i++)
         {
          v=a[i]+b[i]+t;
          c[i]=v%10;
          t=t/10;
         }
     if (t)
         c[lgc++]=1;
    }

void produsc(NrMare a, int lga, int x, NrMare b, int& lgb)
    {
     int i, v, t=0;
     lgb=lga;
     for (i=0;i<lgb;i++)
         {
          v=a[i]*x+t;
          b[i]=v%10;
          t=v/10;
         }
     while (t)
         b[lgb++]=t%10, t=t/10;
    }

void pune0(NrMare a ,int lga)
    {
     int i;
     for (i=lga;i<LMAX1;i++)
          a[i]=0;
    }
*/

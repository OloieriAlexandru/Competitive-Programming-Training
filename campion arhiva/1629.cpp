#include <cstdio>
#include <cstring>
#define LGMAX 10005
using namespace std;
FILE *fin=fopen("conjectura.in","r");
FILE *fout=fopen("conjectura.out","w");
typedef short int NrMare[LGMAX];
NrMare a,b;
int lga,lgb,x;
bool lych[10005];
char c;
void citire (NrMare x, int& lgx,int cetresapun);
void suma (NrMare a, int lga, NrMare b, int lgb, NrMare c, int& lgc);
void pune0 (NrMare x, int lgx);
int palindrom(NrMare a,int lga);
int main()
{
    int i,n,contor,j;
    fscanf(fin,"%d",&n);
    for (i=1; i<=n; ++i)
    {
        fscanf(fin,"%d",&x);
        if (lych[x]==1)
        {
            fprintf(fout,"LYCHREL\n");
            continue;
        }
        citire(a,lga,x);
        if (lga<2)
            fprintf(fout,"0\n");
        else
        {
            if (palindrom(a,lga))
            {
                fprintf(fout,"0\n");
                continue;
            }
            for (contor=1; contor<=1000; ++contor)
            {
                lgb=lga;
                for (j=0; j<lga; ++j)
                    b[lgb-1-j]=a[j];
                suma(a,lga,b,lgb,a,lga);
                if (palindrom(a,lga))
                {
                    fprintf(fout,"%d\n",contor);
                    break;
                }
            }
            if (contor==1001)
            {
                fprintf(fout,"LYCHREL\n");
                lych[x]=1;
            }
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

void citire (NrMare x, int& lgx,int cetresapun)
{
    int i, cif=0,copie;
    copie=cetresapun;
    while (copie>0)
    {
        ++cif;
        copie=copie/10;
    }
    copie=cetresapun;
    lgx=cif;
    for (i=0; i<=cif-1; ++i)
    {
        x[i]=copie%10;
        copie=copie/10;
    }
}

void suma (NrMare a, int lga, NrMare b, int lgb, NrMare c, int& lgc)
{
    int i, t=0, v;
    if (lga>lgb) lgc=lga;
    else lgc=lgb;
    for (i=0; i<lgc; ++i)
    {
        v=(i<lga?a[i]:0)+(i<lgb?b[i]:0)+t;
        c[i]=v%10;
        t=v/10;
    }
    if (t!=0)
        c[lgc++]=t;
}

int palindrom(NrMare a,int lga)
{
    int st,dr;
    for (st=0,dr=lga-1; st<dr; ++st,--dr)
        if (a[st]!=a[dr])
            return 0;
    return 1;
}

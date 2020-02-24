#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 20005
using namespace std;
int a[nmax], n, ans1, ans2, sum, ans, l;
char ch;
int main()
{
    freopen("bloc.in","r",stdin);
    freopen("bloc.out","w",stdout);
    scanf("%d\n",&n);
    for (int i=1;i<=n;++i){
        scanf("%c\n",&ch);
        if (ch == 'B'){
            a[i] = 1;
        } else {
            a[i] = -1;
        }
    }
    l = 1;
    for (int i=1;i<=n;++i){
        sum += a[i];
        if (sum < 0){
            sum = 0;
            l = i + 1;
        }
        if (sum >= ans){
            if (sum > ans){
                ans = sum;
                ans1 = l;
                ans2 = i;
            } else {
                if (l == ans1){
                    ans2 = i;
                }
            }
        }
    }
    printf("%d %d\n",ans1,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
2019 ?
80 puncte

#include <fstream>
#define LMAX 20005
#define INFINIT 999999999

using namespace std;
FILE *fin=fopen("bloc.in","r");
FILE *fout=fopen("bloc.out","w");

int n;
int nr[LMAX];
int difmax, incp, sf, schimb, schimb2=INFINIT;

void citire();
void rezolvare();
void afisare();

int main()
{
    citire();
    rezolvare();
    afisare();
    fclose(fin);
    fclose(fout);
    return 0;
}

void citire()
{
    int i;
    fscanf(fin,"%d\n",&n);
    char c;
    for (i=1; i<=n; i++)
    {
        fscanf(fin,"%c\n",&c);
        if (c=='B')
        {
            nr[i]=nr[i-1]+1;
            schimb=i;
            if (i<schimb2)
                schimb2=i;
        }
        else nr[i]=nr[i-1];
    }
}

void rezolvare()
{
    int i, j;
    int dif, dist, ia;
    for (i=schimb2; i<=schimb; i++)
        for (j=schimb; j>=i; j--)
        {
            dif=nr[j]-nr[i-1];
            dist=j-i+1;
            ia=dist-dif;
            if (dif-ia>difmax)
            {
                difmax=dif-ia;
                incp=i;
                sf=j;
            }
        }
}

void afisare()
{
    fprintf(fout, "%d %d\n",incp,sf);
}
*/

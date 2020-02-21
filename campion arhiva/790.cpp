#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 52
#define lld long long
#define inf 999999999
#define ld long double
using namespace std;
int n, m, a[nmax][nmax], sum[nmax][nmax];
int min1 = inf, min2 = inf;
ld x;
int getV1(int i, int j){
    int v1 = sum[i-1][m];
    int v2 = sum[n][m] - sum[i][m];
    return abs(v1-v2);
}
int getV2(int i, int j){
    int v1 = sum[n][j-1];
    int v2 = sum[n][m] - sum[n][j];
    return abs(v1-v2);
}
int main()
{
    freopen("ocr.in","r",stdin);
    freopen("ocr.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin>>x;
            x *= 100;
            a[i][j] = (int)x;
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            min1 = min(min1, getV1(i, j));
            min2 = min(min2, getV2(i, j));
        }
    }
    int ans1, ans2;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (min1 == getV1(i,j) && min2 == getV2(i,j)){
                ans1 = i, ans2 = j;
            }
        }
    }
    cout<<ans1<<' '<<ans2<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
2 nov 2017, 20:35
70 puncte
#include <fstream>
#include <algorithm>
#define LMAX 55

using namespace std;
ofstream fout("ocr.out");

float a[LMAX][LMAX];
int sump[LMAX][LMAX];
int n, m;
int tip;
int minim=999999999;
int im, jm;
void citire1();
void citire();

int calc_dif(int i, int j);

int main()
{
    int dif;
    citire1();
    citire();
    for (int i=n;i>=1;i--)
        {
         for (int j=m;j>=1;j--)
             {
              dif=calc_dif(i,j);
              if (dif<minim)
                {
                 minim=dif;
                 im=i;
                 jm=j;
                }
             }
        }
    fout<<im<<' '<<jm<<'\n';
    fout.close();
    return 0;
}

int calc_dif(int i, int j)
{
    int s1, s2;
    int s3, s4;
    s1=sump[i-1][m];
    s2=sump[n][m]-sump[i][m];
    s3=sump[n][j-1];
    s4=sump[n][m]-sump[n][j];
    return abs(s1-s2)+abs(s3-s4);
}

void citire()
{
    ifstream fin("ocr.in");
    char c1, c2, c3;
    short int cn1, cn2, cn3;
    char c;
    int i, j;
    fin>>n>>m;
    fin.get(c);
    for (i=1;i<=n;i++)
        {
         for (j=1;j<=m;j++)
             {
              fin.get(c1);
              fin.get(c);
              fin.get(c2);
              if (tip==2)
                  fin.get(c3);
              if (tip==2)
                 {
                  cn1=(short int)(c1-'0');
                  cn2=(short int)(c2-'0');
                  cn3=(short int)(c3-'0');
                  a[i][j]=100*cn1+10*cn2+cn3;
                 }
                 else
                 {
                  cn1=(short int)(c1-'0');
                  cn2=(short int)(c2-'0');
                  a[i][j]=10*cn1+cn2;
                 }
             fin.get(c);
             sump[i][j]=sump[i-1][j]+sump[i][j-1]-sump[i-1][j-1]+a[i][j];
             }
        }
    fin.close();
}

void citire1()
{
    char c1, c2, c3;
    char c;
    int n, m;
    ifstream fin("ocr.in");
    fin>>n>>m;
    fin.get(c);
    fin.get(c1);
    fin.get(c);
    fin.get(c2);
    fin.get(c3);
    if (c3==' ')
        tip=1; else tip=2;
    fin.close();
}
*/

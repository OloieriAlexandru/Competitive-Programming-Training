#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 20001
#define inf 1000000000LL
using namespace std;
set< int > st;
int n, k, ans1, ans2, a[nmax];
int p4[180], cnt = 177, p4cif[10], sum;
bool putere4(int x){
    for (int i=1;i<=cnt;++i){
        if (p4[i] > x){
            return false;
        }
        if (st.count(x-p4[i])){
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("patru.in","r",stdin);
    freopen("patru.out","w",stdout);
    scanf("%d %d",&n,&k);
    for (int i=0;i<10;++i){
        p4cif[i] = 1;
        for (int j=1;j<=4;++j){
            p4cif[i] = (p4cif[i] * i) % 10;
        }
    }
    for (int i=1;i<=cnt;++i){
        p4[i] = i*i*i*i;
        st.insert(p4[i]);
    }
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if (putere4(a[i])){
            ++ans1;
        }
    }
    for (int i=1;i<=k;++i){
        sum += p4cif[a[i]%10];
    }
    sum %= 10;
    for (int i=k+1;i<=n;++i){
        if (sum == 4){
            ++ans2;
        }
        sum -= p4cif[a[i-k]%10];
        sum += p4cif[a[i]%10];
        sum %= 10;
        if (sum < 0){
            sum += 10;
        }
    }
    if (sum == 4){
        ++ans2;
    }
    printf("%d\n%d\n",ans1,ans2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
10 apr 2017, 09:37
35 puncte

#include <fstream>
#include <algorithm>
#define LMAX 30000
#define MAX 1000001

using namespace std;
ifstream fin("patru.in");
ofstream fout("patru.out");

int n, k;
int p[LMAX];
int i4[LMAX];
int a[LMAX];
int nr;

void gen();
bool cb(int x);
int lp(int x);

int main()
{
int i;
int nr4=0;
int nrs=0;
int s;
int st;
fin>>n>>k;
gen();
for (i=1;i<=n;i++)
    {
     fin>>a[i];
     if (cb(a[i]))
         nr4++;
     a[i]=a[i]%10;
     a[i]=lp(a[i])%10;
    }
fout<<nr4<<'\n';
s=0;
for (i=1;i<=k;i++)
    s+=a[i];
st=1;
if (s%10==4)
   nrs++;
for (i=i;i<=n;i++)
    {
     s+=a[i];
     s-=a[st];
     if(s<0)
        s+=10;
     st++;
     if (s%10==4)
        nrs++;
    }
fout<<nrs<<'\n';
fin.close();
fout.close();
return 0;
}

int lp(int x)
    {
     return x*x*x*x;
    }

void gen()
    {
     int i;
     int j;
     int k;
     for (i=1;1;i++)
         {
          i4[i]=i;
          if (i4[i]*i<MAX)
             i4[i]*=i; else {i4[i]=0; break;}
          if (i4[i]*i<MAX)
             i4[i]*=i; else {i4[i]=0; break;}
          if (i4[i]*i<MAX)
             i4[i]*=i; else {i4[i]=0; break;}
         }
     i--;
     for (j=1;j<=i;j++)
         for (k=j;k<=i;k++)
              p[++nr]=i4[j]+i4[k];
     sort(p+1,p+nr+1);
    }

bool cb(int x)
    {
     int st=0, dr=nr+1;
     int m;
     while (st<=dr)
         {
          m=(st+dr)/2;
          if (p[m]==x)
             return 1;
          if (p[m]>x)
             dr=m-1;
              else st=m+1;
         }
     return 0;
    }
*/

#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 1000005
using namespace std;
bool pr[nmax];
void erath(){
    pr[1] = true;
    pr[0] = true;
    for (int i=2;i*i<nmax;++i){
        if (!pr[i]){
            for (int j=i*i;j<nmax;j+=i){
                pr[j] = true;
            }
        }
    }
}
int a, b, n, x;
int main()
{
    freopen("bileprime.in","r",stdin);
    freopen("bileprime.out","w",stdout);
    scanf("%d %d %d",&n,&a,&b);
    int tot = a+b;
    erath();
    for (int i=1;i<=n;++i){
        scanf("%d",&x);
        if (x > tot){
            continue;
        }
        if (!pr[x]){
            if (x <= a){
                a -= x;
                b += x;
            }
        } else if (pr[x]) {
            if (x <= b){
                b -= x;
                a += x;
            }
        }
    }
    printf("%d\n",a);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
30 nov 2015, 21:38
25 puncte

#include <fstream>

using namespace std;
ifstream fin("bileprime.in");
ofstream fout("bileprime.out");
int n,a,b,x,i;
int prim(int a);
int altprim(int a);
int main()
{
fin>>n>>a>>b;
for (i=1;i<=n;i++)
    {fin>>x;
     if (altprim(x))
        {if ((a-x)>0)
             {a-=x;b+=x;}
        }
        else
        {if ((b-x)>0)
             {b-=x;
              a+=x;
             }
        }
    }
fout<<a<<'\n';
fin.close();
fout.close();
return 0;
}
int altprim(int a)
    {int i,d=0;
     for (i=1;i<=a;i++)
          if (a%i==0)
              d++;
     if (d==2)
        return 1;
     return 0;

    }
int prim(int a)
   {int d;
    if (a==1||a==2)
        return 0;
    if (a%2==0)
        return 0;
    for (d=3;d*d<=a;d+=2)
         if (a%d==0)
             return 0;
    return 1;
   }
*/

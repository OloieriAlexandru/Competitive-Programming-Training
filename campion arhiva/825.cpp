#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax
using namespace std;
lld ans, n, k;
int main()
{
    freopen("cifre2.in","r",stdin);
    freopen("cifre2.out","w",stdout);
    cin>>n>>k;
    ans = 0;
    lld j = 1, z = 0;
    while (n >= k){
        if (n % 10 > k){
            ans = ans + (n/10+1)*j;
        } else if (n % 10 == k){
            ans = ans + (n/10)*j+z+1;
        } else {
            ans = ans + (n/10)*j;
        }
        z = z + (n%10)*j;
        n/=10;
        j*=10;
    }
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
27 nov 2014, 22:32
60 puncte

#include <fstream>

using namespace std;
ifstream fin("cifre2.in");
ofstream fout("cifre2.out");


int main()
{int n,c,i,copien;
fin>>n>>c;
i=0;
if (c==1)
    i=1;
while (n>1)
    {copien=n;
     while (copien>0)
           {if (copien%10==c)
                i=i+1;
            copien=copien/10;
           }
    n=n-1;
    }

fout<<i;
fin.close();
fout.close();
    return 0;
}
*/

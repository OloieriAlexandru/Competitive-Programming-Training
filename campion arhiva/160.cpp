#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
int n, ans, v1, v2, v3;
string str;
int main()
{
    freopen("pizza.in","r",stdin);
    freopen("pizza.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>str;
        if (str == "1/4"){
            ++v1;
        } else if (str == "1/2"){
            ++v2;
        } else {
            ++v3;
        }
    }
    v1 -= v3;
    if (v2 % 2){
        v1 -= 2;
    }
    if (v1 < 0) {
        v1 = 0;
    }
    ans = v3 + (v2 + 1) / 2 + (v1 + 3) / 4;
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
17 feb 2020, 14:33
60 puncte

#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
int n, ans, v1, v2, v3;
string str;
int main()
{
    freopen("pizza.in","r",stdin);
    freopen("pizza.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>str;
        if (str == "1/4"){
            ++v1;
        } else if (str == "1/2"){
            ++v2;
        } else {
            ++v3;
        }
    }
    if (v1 >= v3){
        v1 -= v3;
        v3 = 0;
        ans += v3;
    } else {
        v1 = 0;
    }
    if (v2 % 2 == 1 && v1 >= 2){
        v1 -= 2;
        ans += v2;
        v2 = 0;
    } else if (v2 % 2 == 1){
        v1 = 0;
    }
    ans += v1 / 4 + (v1 % 4 ? 1 : 0) + v2 / 2 + (v2 % 2 ? 1 : 0) + v3;
    cout<<ans<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

27 nov 2016, 15:21
20 puncte

#include <fstream>

using namespace std;
ifstream fin("pizza.in");
ofstream fout("pizza.out");

int s;
int nr;
int m[5];

void citire();
void afisare();

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
     int i, n, v1, v2;
     char c;
     fin>>n;
     for (i=1;i<=n;i++)
          {
           fin>>v1;
           fin>>c;
           fin>>v2;
           if (v1==1&&v2==2)
              m[1]++;
              else
              if (v1==1&&v2==4)
                   m[2]++;
                   else
                   m[3]++;
           }
    }

void afisare()
    {
     if (m[2]>m[3])
         {
         nr+=m[3];
         m[2]-=m[3];
         m[3]=0;}
         else if (m[2]<=m[3])
                {
                 nr+=m[2];
                 m[3]-=m[2];
                 m[2]=0;
                }
     nr+=m[1]/2;
     if (m[1]/2&&(m[2]%4==3||m[2]%4==0))
         nr++;
     nr=nr+m[1]%2+m[3];
     fout<<nr<<'\n';
    }
*/

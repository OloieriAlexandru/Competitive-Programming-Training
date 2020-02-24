#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax
using namespace std;
int value(int a, int b){
    if (a == b && a == 5){
        return 2;
    }
    if (a == b && a == 3){
        return 3;
    }
    if (a == b && a == 4){
        return 3;
    }
    return max(a,b);
}
int main()
{
    freopen("sport1.in","r",stdin);
    freopen("sport1.out","w",stdout);
    int a, b, c, n;
    double sum = 0;
    cin>>a>>b>>n;
    sum += a+b;
    for (int i=3;i<=n;++i){
        c = value(a,b);
        sum += c;
        a = b;
        b = c;
    }
    sum /= n;
    cout<<setprecision(6)<<fixed<<sum<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
29 nov 2016, 23:08
80 puncte

#include <fstream>
#include <iomanip>

using namespace std;
ifstream fin("sport1.in");
ofstream fout("sport1.out");

int s, n;
int v1, v2, v3;

void citire();
void afisare();
void rezolvare();

int valoare();

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
     fin>>v1>>v2;
     s+=v1+v2;
     fin>>n;
    }

void afisare()
    {
     fout<<setprecision(2)<<fixed<<(double)s/(double)n<<'\n';
    }

void rezolvare()
    {
     int i;
     for (i=3;i<=n;i++)
         {
          v3=valoare();
          s+=v3;
          v1=v2;
          v2=v3;
         }
    }

int valoare()
    {
     if (v1!=v2)
        {
         if (v1>v2)
             return v1;
         return v2;
        }
     if (v1==4&&v2==4||v1==3&&v2==3)
         return 3;
     if (v1==5&&v2==5)
         return 2;
     return 3;
    }
*/

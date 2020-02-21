#include <bits/stdc++.h>
using namespace std;
int n, x, fv[10], rm;
vector<int>v;
int main()
{
    freopen("sircifre.in","r",stdin);
    freopen("sircifre.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d",&x);
        v.push_back(x);
    }
    bool ok = true;
    while (ok){
        ok = false;
        for (int j=0;j<(int)v.size()-1;){
            if (abs(v[j]-v[j+1]) == 1){
                rm = j;
                ok = true;
                v.erase(v.begin()+rm,v.begin()+rm+2);
            } else {
                ++j;
            }
        }
        if (!ok){
            break;
        }
    }
    for (int i=0;i<v.size();++i){
        ++fv[v[i]];
    }
    bool af = false;
    for (int i=0;i<10;++i){
        if (fv[i]){
            af = true;
            cout<<i<<' '<<fv[i]<<'\n';
        }
    }
    if (!af){
        cout<<"-1\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
30 nov 2016, 21:54
30 puncte

#include <fstream>
#include <algorithm>
#define LMAX 505

using namespace std;
ifstream fin("sircifre.in");
ofstream fout("sircifre.out");

int s[LMAX];
int n;
int vf=-1;

void citire();
void afisare();

int pop();
void push(int a);
bool libera();

bool consecutive(int a, int b);

int main()
{
citire();
afisare();
fin.close();
fout.close();
return 0;
}

void afisare()
    {
     int i, nr, cif;
     if (libera())
         {fout<<-1<<'\n';;
         return ;}
     sort(s,s+vf);
     for (i=0;i<=vf;i++)
         {
          nr=0;
          cif=s[i];
          while (s[i]==cif)
                {
                 i++;
                 nr++;
                }
          i--;
          fout<<cif<<' '<<nr<<'\n';
         }
    }

void citire()
    {
     int i, a, b;
     fin>>n;
     for (i=1;i<=n;i++)
         {
          fin>>a;
          if (libera())
             {
              push(a);
              continue;
             }
          b=pop();
          if (consecutive(a,b))
              continue;
          push(b);
          push(a);
         }
    }

bool consecutive(int a, int b)
    {
     int d=a-b;
     if (d==-1||d==1)
         return 1;
     return 0;

    }

int pop()
    {
     vf--;
     return s[vf+1];
    }

void push(int a)
    {
     s[++vf]=a;
    }

bool libera()
    {
     return vf==-1;
    }
*/

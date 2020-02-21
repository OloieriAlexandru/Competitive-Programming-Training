#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define nmax 1005
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
int n, maxx = -1, af2, af1;
bool ap[256];
char s[nmax];
vector<pii>ans;
void check(const string& str, int cnt){
    for (unsigned int i=0;i<str.size();++i){
        ap[(int)str[i]] = true;
    }
    int mx = 0, act = 1;
    for (unsigned int  i=1;i<str.size();++i){
        if (str[i] <= str[i-1]){
            mx = max(mx, act);
            act = 1;
        } else {
            ++act;
        }
    }
    mx = max(mx, act);
    maxx = max(maxx, mx);
    ans.pb(mp(mx,cnt));
}
int main()
{
    freopen("text2.in","r",stdin);
    freopen("text2.out","w",stdout);
    cin>>n>>s;
    char *p = strtok(s, "*");
    int cnt = 0;
    while (p){
        ++cnt;
        string asd = string(p);
        check(asd,cnt);
        p = strtok(NULL, "*");
    }
    for (int i=1;i<=128;++i){
        if ((i>='a'&&i<='z') || (i>='A'&&i<='Z')){
            if (ap[i]){
                ++af2;
            }
        }
    }
    for (unsigned int i=0;i<ans.size();++i){
        if (ans[i].first == maxx){
            ++af1;
        }
    }
    cout<<af1<<'\n';
    for (unsigned int i=0;i<ans.size();++i){
        if (ans[i].first == maxx){
            cout<<ans[i].second<<' ';
        }
    }
    cout<<'\n';
    cout<<af2<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
31 ian 2017, 22:46
90 puncte
#include <fstream>
#include <cstring>
#define LMAX 1005

using namespace std;
ifstream fin("text2.in");
ofstream fout("text2.out");

char s[LMAX];
int n;

int care[LMAX];
bool ap[50];
int nrc;
int maxim;


void citire();
void afisare();
void rezolvare();

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
     char c;
     fin>>n;
     fin.get(c);
     fin.getline(s,LMAX);
    }

void rezolvare()
    {
     char *p, *altul;
     char c;
     int nr=0;
     int ordine=0;
     p=strtok(s,"*");
     while (p)
         {
          ordine++;
          altul=p;
          nr=1;
          while (*altul!=0)
             {
              c=*altul;
              ap[(int)(c-'a')]=1;
              if (*altul<*(altul+1))
                  nr++;
                  else
                  {
                   if (nr>=maxim)
                      {
                       if (nr==maxim&&ordine!=care[nrc])
                           care[++nrc]=ordine;
                           else
                           {
                            maxim=nr;
                            nrc=1;
                            care[nrc]=ordine;
                           }
                      }
                   nr=1;
                  }
              altul++;
             }
          \/\*if (nr>=maxim)
              {
                if (nr==maxim)
                    care[++nrc]=ordine;
                    else
                    {
                    maxim=nr;
                    nrc=1;
                    care[nrc]=ordine;
                    }
                }\*\/
          p=strtok(NULL,"*");
         }
    }

void afisare()
    {
     int i;
     int nr=0;
     fout<<nrc<<'\n';
     for (i=1;i<=nrc;i++)
          fout<<care[i]<<' ';
     fout<<'\n';
     for (i=0;i<27;i++)
          if (ap[i])
              nr++;
     fout<<nr<<'\n';
    }
*/

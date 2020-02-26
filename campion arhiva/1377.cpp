#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax
using namespace std;
int main()
{
    freopen("zuma.in","r",stdin);
    freopen("zuma.out","w",stdout);
    int k, st, dr;
    string s;
    cin>>k;
    --k;
    cin>>s;
    st = k, dr = k;
    bool ok = false;
    if (s[k] == s[k-1] && s[k] == s[k+1]){
        ok = true;
    }
    while (st >= 0 && dr < (int)s.size() && s[st] == s[dr] && ok){
        char ch = s[st];
        int cnt = 0, ist = st, idr = dr;
        if (st == dr){
            ++cnt, --st, ++dr;
        }
        while (st>=0&&s[st] == ch){
            --st, ++cnt;
        }
        while (dr < (int)s.size() && s[dr] == ch){
            ++dr, ++cnt;
        }
        if (cnt < 3){
            st = ist, dr = idr;
            break;
        }
    }
    for (int i=0;i<=st;++i){
        cout<<s[i];
    }
    for (int j=(dr==st?dr+1:dr);j<(int)s.size();++j){
        cout<<s[j];
    }
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
19 ian 2017, 23:24
90 puncte

#include <fstream>
#include <cstring>
#define LMAX 1010

using namespace std;
ifstream fin("zuma.in");
ofstream fout("zuma.out");

int n, cn;
char sir[LMAX];
int lg;
void citire();
int main()
{
citire();
if (!(sir[cn-1]==sir[cn]&&sir[cn]==sir[cn+1])&&!((cn==0&&sir[cn]==sir[cn+1]&&sir[cn+1]==sir[cn+2])||(cn==lg-1&&sir[cn]==sir[cn-1]&&sir[cn-1]==sir[cn-2])))
    fout<<sir<<'\n';
    else
    {int ok=1, st, dr;
     while (ok)
         {for (st=cn-1;st>=0&&sir[st]==sir[cn];st--);st++;
          for (dr=cn+1;sir[dr]==sir[cn];dr++);dr--;
          if ((dr-st+1)<3) {ok=0;continue;}
          cn=st-1;
          strcpy(sir+st,sir+dr+1);
         }
     fout<<sir<<'\n';
    }
fin.close();
fout.close();
return 0;
}
void citire()
    {char c;
     fin>>n;cn=n-1;
     fin.get(c);
     fin>>sir;
     lg=strlen(sir);
    }
*/

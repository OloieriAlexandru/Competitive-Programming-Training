#include <bits/stdc++.h>
#define lld unsigned long long int
using namespace std;
int main() {
    freopen("betisoare.in","r",stdin);
    freopen("betisoare.out","w",stdout);
    int n;
    char ch;
    cin >> n; cin.get();
    for (int i = 0; i < n; i++) {
        lld ans = 0, t = 1, f = 0;
        while (true){
            ch = cin.get();
            if (ch == '\n'){
                t *= f;
                ans += t;
                break;
            } else if (ch == 'I'){
                ++f;
            } else if (ch == '*'){
                t *= f;
                f = 0;
            } else if (ch == '+'){
                t *= f;
                ans += t;
                t = 1;
                f = 0;
            }
        }
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
28 feb 2016, 13:06
50 puncte

#include <fstream>

using namespace std;
ifstream fin("betisoare.in");
ofstream fout("betisoare.out");

int main()
{
int n, i, s, b, ab, inm, ok;
char c;
fin>>n;fin.get(c);
for (i=1;i<=n;i++)
     {s=0; b=0;
      do
      {
       fin.get(c);
       if (c=='I')
           {b++; continue;}
       if (c=='*')
          {loop:
           inm=b;
           ab=0;
           ok=1;
           while (ok)
              {fin.get(c);
               if (c=='I')
                   ab++;
                   else
                   break;
              }
           inm=inm*ab;
           if (c=='*')
               goto loop;
           s=s+inm;
           b=0;
           continue;
          }
       s=s+b;
       b=0;
       continue;
      }while (c!='\n');
      fout<<s<<'\n';
     }
fin.close();
fout.close();
return 0;
}
*/

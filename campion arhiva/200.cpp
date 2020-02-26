#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
string s;
int n;
string getIntAsString(int x){
    string res;
    if (!x){
        return string("0");
    }
    while (x){
        res.push_back(x%10+'0');
        x/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}
string getNxt(const string & s){
    string res;
    for (unsigned int i=0;i<s.size();++i){
        int cnt = 1;
        while (i < s.size()-1 && s[i] == s[i+1]){
            ++cnt, ++i;
        }
        res += getIntAsString(cnt);
        res.push_back(s[i]);
    }
    return res;
}
int main()
{
    freopen("cifre.in","r",stdin);
    freopen("cifre.out","w",stdout);
    cin>>s;
    cin>>n;
    for (int i=1;i<=n;++i){
        string nw = getNxt(s);
        s = nw;
    }
    cout<<s<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
14 ian 2017, 22:07
70 puncte

#include <fstream>
#include <cstring>
#define LMAX 60000

using namespace std;
ifstream fin("cifre.in");
ofstream fout("cifre.out");

char nr[LMAX];
char ce[LMAX];
int n;
int lg;
int per;

void citire();
void rezolvare();
void afisare();

void aplic_procedeu();
int trans(char s[], int nr);

void scot_frecventa();
void construiesc_nr();

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
     fin.getline(nr, LMAX);
     lg=strlen(nr);
     fin>>n;
    }

void afisare()
    {
     fout<<nr<<'\n';
    }

void rezolvare()
    {
     int i;
     for (i=1;i<=n;i++)
         {
          //lg=strlen(nr);
          aplic_procedeu();
         }
     }

void aplic_procedeu()
    {
     scot_frecventa();
     //construiesc_nr();
    }

void scot_frecventa()
    {
     int i;
     char c=nr[0];
     char cifr[15];
     int fr=0, lge;
     ce[0]=0;
     int nlg=0;
     for (i=0;i<lg;)
         {
          per++;
          while (nr[i]==c)
                 i++, fr++;
          lge=trans(cifr,fr);
          strcat(ce,cifr);
          nlg+=lge;
          ce[nlg]=c;
          nlg++;
          ce[nlg]=0;

          c=nr[i];
          fr=0;
         }
     lg=nlg;
     strcpy(nr,ce);
    }

\/\*void construiesc_nr()
    {
     int i;
     lg=0;
     char cifr[100];
     nr[0]=0;
     int lge;
     for (i=1;i<=per;i++)
         {
          lge=trans(cifr,p[i].fr);
          strcat(nr,cifr);
          lg+=lge;
          nr[lg]=p[i].nr;
          lg++;
          nr[lg]=0;
         }
     nr[lg+1]=0;
    }\*\/

int trans(char s[], int nr)
    {
     int i=0;
     int st, dr;
     while (nr>0)
         {
          s[i++]=(char)(nr%10+'0');
          nr=nr/10;
         }
     s[i]=0;
     for (st=0, dr=i-1;st<dr;st++,dr--)
          swap(s[st],s[dr]);
     return i;
    }
*/

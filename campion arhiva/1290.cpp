#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
using namespace std;
string s;
vector<int>fv;
vector < pair<int,int> > v;
int stringToInt(const string & s){
    int res = 0;
    for (int i=0;i<(int)s.size();++i){
        res = res * 10 + (s[i] - '0');
    }
    return res;
}
bool palindrome(const vector<int> & fv){
    int k = 0, nen = 0;
    for (int i=0;i<10;++i){
        k += (fv[i]%2);
        if (i > 0){
            nen += fv[i];
        }
    }
    if (nen == 1 && fv[0]){
        return false;
    }
    return k < 2;
}
bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if (a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}
int main()
{
    freopen("talent.in","r",stdin);
    freopen("talent.out","w",stdout);
    int n, diff;
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>s;
        vector<int>fv(10,0);
        for (int i=0;i<(int)s.size();++i){
            ++fv[s[i]-'0'];
        }
        if (!palindrome(fv)){
            continue;
        }
        diff = 0;
        int num = stringToInt(s);
        for (int i=0;i<10;++i){
            if (fv[i]){
                ++diff;
            }
        }
        v.push_back(make_pair(num, diff));
    }
    if (v.size() == 0){
        cout<<"0 0\n";
        return 0;
    }
    sort(v.begin(),v.end(),cmp);
    cout<<v.size()<<' '<<v[0].first<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
29 nov 2016, 23:48
90 puncte

#include <fstream>
#define LMAX 10
#define INFINIT 999999999

using namespace std;
ifstream fin("talent.in");
ofstream fout("talent.out");

int amax=INFINIT, nrcmax;
int nr;
int n;
int f[LMAX];

int palindrom(int a);

void interpretez(int a);
void citire();
void afisare();
void curat();

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
     int i, a;
     fin>>n;
     for (i=1;i<=n;i++)
         {
          fin>>a;
          interpretez(a);
         }
    }

void afisare()
    {
     fout<<nr<<' ';
     if (amax!=INFINIT)fout<<amax<<'\n';
         else fout<<"0\n";
    }

void interpretez(int a)
    {
     int nrc=palindrom(a);
     if (!nrc) return ;
     nr++;
     //fout<<a<<'\n';
     if (nrc>=nrcmax)
        {
         if (nrc==nrcmax)
             {if (a<amax)
                  amax=a;}
             else {amax=a;
                   nrcmax=nrc;}
        }
    }

int palindrom(int a)
    {
     int i, nr1=0, r=0;
     curat();
     while (a>0)
         {
          f[a%10]++;
          a=a/10;
         }
     for (i=0;i<=9;i++)
          {if (f[i]!=0)
              {r++;
              if (f[i]%2)
                  nr1++;}}
     if (nr1>1)
         return 0;
     if (f[0]>0)
        {
         if (f[0]%2==0)
             {if ((nr1==1&&r>2)||(r>=2&&nr1==0))
                 return r;
                 else return 0;}
         if (f[0]%2==1)
             {if ((nr1==1&&r>1)||(r>=2&&nr1==0))
                 return r;
                 else return 0;}
        }
     //if ((f[0]%2==0&&f[0]>0)&&nr1==1&&r<=2) return 0;
     return r;
    }

void curat()
    {
     int i;
     for (i=0;i<=9;i++)
          f[i]=0;
    }
*/

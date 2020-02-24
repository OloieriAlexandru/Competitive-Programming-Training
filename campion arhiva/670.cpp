#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax
using namespace std;
vector<int>ans1, ans2, ans3;
void add(int n, int start){
    int rep = (n-start)/6;
    int act = start;
    for (int i=1;i<=rep;++i){
        ++act;
        ans1.push_back(act);
        ++act;
        ans2.push_back(act);
        ++act;
        ans3.push_back(act);
        ++act;
        ans3.push_back(act);
        ++act;
        ans2.push_back(act);
        ++act;
        ans1.push_back(act);
    }
}
int main()
{
    freopen("excursie1.in","r",stdin);
    freopen("excursie1.out","w",stdout);

    int n;
    cin >> n;
    if (n < 5){
        cout<<"NU\n";
        return 0;
    }
    int total = n * (n+1) / 2;
    if (total % 3){
        cout<<"NU\n";
        return 0;
    }

    cout<<"DA\n";
    if ((n-5)%6==0){
        ans1.push_back(5);
        ans2.push_back(2);
        ans2.push_back(3);
        ans3.push_back(1);
        ans3.push_back(4);
        add(n,5);
    } else if ((n-6)%6==0) {
        ans1.push_back(2);
        ans1.push_back(5);
        ans2.push_back(3);
        ans2.push_back(4);
        ans3.push_back(1);
        ans3.push_back(6);
        add(n,6);
    } else if ((n-8)%6==0) {
        ans1.push_back(1);
        ans1.push_back(2);
        ans1.push_back(3);
        ans1.push_back(6);
        ans2.push_back(5);
        ans2.push_back(7);
        ans3.push_back(4);
        ans3.push_back(8);
        add(n,8);
    } else {
        ans1.push_back(1);
        ans1.push_back(2);
        ans1.push_back(3);
        ans1.push_back(4);
        ans1.push_back(5);
        ans2.push_back(7);
        ans2.push_back(8);
        ans3.push_back(6);
        ans3.push_back(9);
        add(n,9);
    }
    for (unsigned int i=0;i<ans1.size();++i){
        cout<<ans1[i]<<' ';
    }
    cout<<'\n';
    for (unsigned int i=0;i<ans2.size();++i){
        cout<<ans2[i]<<' ';
    }
    cout<<'\n';
    for (unsigned int i=0;i<ans3.size();++i){
        cout<<ans3[i]<<' ';
    }
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
10 mar 2016, 11:47
40 puncte

#include <cstdio>
#include <algorithm>
#define LMAX 10005

using namespace std;
FILE *fin=fopen("excursie1.in","r");
FILE *fout=fopen("excursie1.out","w");

int n, s, col;
int a[LMAX][5], i;

void rezolva();
void afisarematrice();

int main()
{
fscanf(fin,"%d",&n);
s=((1+n)*n)/2;
if (!(s%3==0))
    fprintf(fout,"NU\n");
    else
    {
     col=n/3;
     fprintf(fout,"DA\n");
     rezolva();
     afisarematrice();
    }
fclose(fin);
fclose(fout);
return 0;
}

void afisarematrice()
    {
     int i, j,x;
     for (i=1;i<=col;i++)
          {for (j=1;j<=col+1;j++)
               {x=a[j][i];
               if (x) fprintf(fout,"%d ",x);}
          fprintf(fout,"\n");}
    }

void rezolva()
    {
     int i, j;
     for (i=col+1;i>=1;i--)
         {
          for (j=1;j<=3&&n>0;j++)
               {a[i][j]=n;n--;}
          i--;
          if (n==0||i==0)break;
          for (j=3;j>=1&&n>0;j--)
               {a[i][j]=n;n--;}
          if (n==0) break;
         }
    }
*/

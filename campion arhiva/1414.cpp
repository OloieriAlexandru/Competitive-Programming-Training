#include <bits/stdc++.h>
#define pii pair<int,int>
#define mp make_pair
#define lld long long
#define ld long double
#define pb push_back
#define nmax 1005
using namespace std;
int n, poz;
vector< pair < int, lld > > v;
lld val, mat[2][nmax];
int main()
{
    freopen("triunghi4.in","r",stdin);
    freopen("triunghi4.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%d %lld",&poz,&val);
        v.push_back(make_pair(poz,val));
    }
    reverse(v.begin(),v.end());
    int nw = 1, lst = 0;
    mat[lst][1] = v[0].second;
    for (int i=2;i<=n;++i){
        poz=v[i-1].first;
        val=v[i-1].second;
        mat[nw][poz]=val;
        for (int j=poz-1;j>=1;--j){
            mat[nw][j]=mat[lst][j]-mat[nw][j+1];
        }
        for (int j=poz+1;j<=i;++j){
            mat[nw][j]=mat[lst][j-1]-mat[nw][j-1];
        }
        if (i < n){
            nw = 1 - nw;
            lst = 1 - lst;
        }
    }
    for (int i=1;i<=n;++i){
        printf("%lld ", mat[nw][i]);
    }
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
28 feb 2015, 11:47
35 puncte

#include <fstream>

using namespace std;
ifstream fin("triunghi4.in");
ofstream fout ("triunghi4.out");
int a[350][350],i,j,n,c[105];
int main()
{
   fin>>n;
   for(i=n;i>=1;i--)
	   {fin>>c[i];
	    fin>>a[i][c[i]];

	   }
	for(i=1;i<=n;i++)
	{   for(j=c[i]-1;j>=1;j--)
		    a[i][j]=a[i-1][j]-a[i][j+1];
	    for(j=c[i]+1;j<=i;j++)
			a[i][j]=a[i-1][j-1]-a[i][j-1];
	}
	for(i=1;i<=n ;i++)
		fout<<a[n][i]<<' ';
    fin.close();
    fout.close();
    return 0;
}
*/
